#include <stdlib.h>
#include <string.h>
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif
#include <cstdio>
#include <cassert>
#include <stdexcept>
#include <algorithm>
#include <vector>

// Pawel Czerwinski
// O(n log m)
//
// dla kazdego cyklu tworzymy drzewo przedzialowe
// za pomoca ktorego wyliczymy minimalny prefiks i moment w ktorym dziecak bankrutuje
// koejnosc zapytan jest bez znaczenia
//
//

typedef unsigned long long ull;
typedef long long ll;


const ll MAX_N = 1000 * 1000;
const ll MAX_M = 1000 * 1000;

const ll MAX_VAL = 1000 * 1000 * 1000;
const ll MIN_VAL = 1;

const bool DEBUG = true;


using namespace std;

inline size_t pow2up(size_t val) {
	size_t result = 1;
	while (result < val) result <<= 1;
	return result;
}

inline ull celi(ull a, ull b) {
	return (a % b == 0) ? a / b : (a / b) + 1;
}


struct tree_t {
	// cykliczne drzewo przedzialowe zwracajace najmniejszy prefiks
	struct node_t {
		ll pref, sum;

		node_t() : pref(0), sum(0) {}
		node_t(ll val) : pref(val), sum(val){}
		node_t(const node_t &l, const node_t &r) {
			pref = min(l.pref, l.sum + r.pref);
			sum = l.sum + r.sum;
		}

		// debug
		void print() {
			printf("(" INT64 ", " INT64 ")", pref, sum);
		}
	};

	node_t *tree;
	ll size, length;

	tree_t(const vector<bool> &vals) { // jestem leniwy to po prostu robie kopie lisci :P
		size = 2 * pow2up(vals.size());
		length = vals.size();
		tree = new node_t[2 * size];

		for (size_t i = 0; i < vals.size(); ++i)
			tree[size + i] = (vals[i]) ? node_t(1) : node_t(-1);

		for (size_t i = 0; i < vals.size(); ++i)
			tree[size + i + vals.size()] = (vals[i]) ? node_t(1) : node_t(-1);

		for (size_t i = size - 1; i > 0; --i)
			tree[i] = node_t(tree[2 * i], tree[2 * i + 1]);
	}


	~tree_t() {
		delete[] tree;
	}

	ll sum(size_t start = 0) {
		size_t f_idx = size + start;
		size_t t_idx = length + f_idx - 1;
		
		ll f_sum = tree[f_idx].sum, t_sum = tree[t_idx].sum;
		if(f_idx == t_idx)
			return f_sum;

		while (f_idx / 2 != t_idx / 2) {
			if (f_idx % 2 == 0)
				f_sum += tree[f_idx + 1].sum;

			if (t_idx % 2 == 1) {
				t_sum += tree[t_idx - 1].sum;
			}

			f_idx /= 2;
			t_idx /= 2;
		}

		return f_sum + t_sum;
	}

	ll min_pref(size_t start) {

		size_t f_idx = size + start, t_idx = f_idx + length - 1;
		ll f_pref = tree[f_idx].pref, f_sum = tree[f_idx].sum;
		ll t_pref = tree[t_idx].pref;
		
		if (f_idx == t_idx)
			return f_pref;

		while (f_idx / 2 != t_idx / 2) {
			if (f_idx % 2 == 0) {
				f_pref = min(f_pref, f_sum + tree[f_idx + 1].pref);
				f_sum += tree[f_idx + 1].sum;
			}

			if (t_idx % 2 == 1) {
				t_pref = min(tree[t_idx - 1].pref, tree[t_idx - 1].sum + t_pref);
			}

			f_idx /= 2;
			t_idx /= 2;
		}

		return min(f_pref, f_sum + t_pref);
	}

	ll steps0(size_t start, ll val) {
		if (DEBUG) {
			if (val + min_pref(start) > 0)
				throw invalid_argument("val musi wyzerowac sie w 1 obrocie");
		}
		
		ll f_idx = size + start, from = size + start;
		ll f_sum = tree[f_idx].sum, f_pref = tree[f_idx].pref;

		if (val + f_sum <= 0)
			return 1;

		while (true) {
			if (f_idx % 2 == 0) {
				f_pref = min(f_pref, f_sum + tree[f_idx + 1].pref);
				f_sum += tree[f_idx + 1].sum;
			}

			if (f_pref + val <= 0)
				break;
			f_idx /= 2;
		}

		ll n_val = val + f_sum - tree[f_idx + 1].sum;

		f_idx = f_idx + 1;

		while (f_idx < size) {
			if (n_val + tree[2 * f_idx].pref <= 0)
				f_idx *= 2;
			else {
				n_val += tree[2 * f_idx].sum;
				f_idx = 2 * f_idx + 1;
			}
				
		}
		
		return f_idx - from + 1;	
	}

};


struct cycle_t {
	tree_t *tree;
	ll income;
	size_t length;
	vector <bool> vals;

	cycle_t() {
		tree = NULL;
	}

	~cycle_t() {
		if (tree)
			delete tree;
	}

	void insert(bool val) {
		vals.push_back(val);
	}

	void init() {
		if (tree == NULL) {
			length = vals.size();
			tree = new tree_t(vals);
			vals.clear();
			income = tree->sum();
		}
	}

	ll time_to_bancrupt(size_t delta, ll coins, size_t n) {
		ll tmp = tree->min_pref(delta);
		if (coins + tmp > 0) {
			if (income >= 0)
				return -1;

			ll tmp2 = coins + tmp;
			tmp2 = celi(tmp2, -income);
			return ((length * tmp2) + tree->steps0(delta, coins + income * tmp2) - 1) * n + 1;

		}

		return (tree->steps0(delta, coins)  - 1)* n + 1;
	}

};


void read_in(vector<ll> &coins, vector<bool> &win) {
	size_t n, m;
	scanf("%lu", &n);
	coins.resize(n);
	ll tmp;
	for (size_t i = 0; i < n; ++i) {
		scanf(INT64, &tmp);
		coins[i] = tmp;
		if (DEBUG) {
			if (tmp < MIN_VAL || tmp > MAX_VAL)
				throw invalid_argument("bledne oszczednosci");
		}
	}
	scanf("%lu", &m);
	win.resize(m);
	char c;
	for (size_t i = 0; i < m; ++i) {
		scanf(" %c", &c);
		if (DEBUG) {
			if (!(c == 'W' || c == 'P'))
				throw invalid_argument("bledny cykl pracy automatu");
		}

		win[i] = (c == 'W') ? true : false;
	}
}


void init(cycle_t *cycles[], size_t c_delta[], const vector<ll> &coins,
	const vector<bool> &win) {

	size_t n = coins.size(), m = win.size();

	cycle_t *c;

	cycle_t **tmp = new cycle_t*[MAX_M];
	for (size_t i = 0; i < m; ++i)
		tmp[i] = NULL;

	size_t *tmp_d = new size_t[MAX_M];

	
	size_t i = 0, j;
	size_t d;

	while (i < min(n, m)) { // O(n+m)
		if (tmp[i % m] == NULL) {
			d = 0;
			c = new cycle_t;
			c->insert(win[i % m]);
			
			tmp[i % m] = cycles[i] = c;
			tmp_d[i % m] = c_delta[i] = d;
			
			j = (i + n) % m;
			while (j != i % m) {
				++d;
				c->insert(win[j]);
				tmp[j] = c;
				tmp_d[j] = d;
				j = (j + n) % m;
			}

		}
		else {
			cycles[i] = tmp[i % m];
			c_delta[i] = tmp_d[i % m];
		}

		++i;
	}

	while (i < n) {
		cycles[i] = cycles[i % m];
		c_delta[i] = c_delta[i % m];
		++i;
	}

	for (size_t i = 0; i < n; ++i) {
		cycles[i]->init();
	}

	delete[]tmp_d;
	delete[]tmp;
}


int main() {
	vector<ll> coins;
	vector<bool> win;

	read_in(coins, win);
	static cycle_t * cycles[MAX_N];
	static size_t c_delta[MAX_N];

	init(cycles, c_delta, coins, win);

	ll result = -1, tmp;
	size_t n = coins.size();
	
	for (size_t i = 0; i < coins.size(); ++i) {
		tmp = cycles[i]->time_to_bancrupt(c_delta[i], coins[i], n);
		if (tmp > 0)
			tmp += i;
		
		if (result < 0)
			result = tmp;
			

		if (tmp < result && tmp > 0) 
			result = tmp;
			
	}

	printf(INT64 "\n", result);

	return 0;
}
