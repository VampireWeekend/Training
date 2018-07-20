#include <bits/stdc++.h>

using namespace std;
int n,num0=1,num1=0;
int ax[305],res[305];
char ans0[305],ans1[305],en[305];

void yuchuli (){
    if(ax[32])res[0]=1;
    en[0]=' ';ans0[0]='^';
    int i;
    for(i='0';i<='9';i++)
    {
        en[i-'0'+1]=(char)i;
        if(ax[i])res[i-'0'+1]=1;
    }
    for(i='A';i<='Z';i++)
    {
        en[i-'A'+11]=(char)i;
        if(ax[i])res[i-'A'+11]=1;
    }
    for(i='a';i<='z';i++)
    {
        en[i-'a'+37]=(char)i;
        if(ax[i])res[i-'a'+37]=1;//Ò»¹²37+26=63¸ö×Ö·û
    }
    for(i=1;i<=61;i++){
        if(res[i]==res[i-1]&&res[i]==res[i+1])res[i]=-1;
        if(res[i-1]==-1&&res[i]==res[i+1])res[i]=-1;
    }
    for(i=0;i<=62;i++){
        if(res[i]==1){
            ans1[num1]=en[i];
            num1++;
        }
        if(res[i]==0){
            ans0[num0]=en[i];
            num0++;
        }
        if(res[i]==-1){
            if(res[i-1]){
                ans1[num1]='-';
                num1++;
            }
            else {
                ans0[num0]='-';
                num0++;
            }
            while(res[i+1]==-1)i++;
        }
    }
}

void play (){
    int i,j;
    for(i=0;i<num0;i++){
        if(ans0[i]=='0'&&ans0[i+1]=='-')ans0[i]='!';
        if(ans0[i]=='A'&&ans0[i+1]=='-')ans0[i]=':';
        if(ans0[i]=='a'&&ans0[i+1]=='-')ans0[i]='[';
    }
    for(i=0;i<num1;i++){
        if(ans1[i]=='0'&&ans1[i+1]=='-')ans1[i]='!';
        if(ans1[i]=='A'&&ans1[i+1]=='-')ans1[i]=':';
        if(ans1[i]=='a'&&ans1[i+1]=='-')ans1[i]='[';
    }
    ans0[num0]='\0';
    ans1[num1]='\0';
}


int main()
{
 //   freopen("hh.txt","r",stdin);
    int a;
    char ch;
    while(scanf("%c",&ch)!=EOF){
 //       a = scanf("%c",&ch);
 //       if(a==0||a==EOF)break;
        ax[ch]=1;
    }
    yuchuli();
    play();
    putchar('%');putchar('[');
    if(num1==1){
        printf("^!");
    }
    else {
    if(num0<num1)printf("%s",ans0);
    else {
    if(num0==num1&&ans0[0]<ans1[0])printf("%s",ans0);
    else printf("%s",ans1);
    }
    }
    putchar(']');
    return 0;
}

