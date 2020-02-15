#include<iostream>
#include<string>
#include<map>
#include<cstdio>
using namespace std;
int equals(string &a,string &b)
{
    while(a.size()>b.size())
        b="0"+b;
    while(a.size()<b.size())
        a="0"+a;
    return a.size();
}
string add(string a,string b)
{
    int l=equals(a,b);
    int c=0;
    char ch;
    string res="";
    for(int i=l-1;i>=0;i--)
    {
        c=(a[i]-'0')+(b[i]-'0')+c;
        ch=c%10+'0';
        c/=10;
        res=ch+res;
    }
    if(c==1)res="1"+res;
    return res;
}
int cmp(string a,string b)
{
     if(a.size()>b.size())return 1;
     if(a.size()<b.size())return -1;
     if(a>b)return 1;
     if(a<b)return -1;
     return 0;
}
string del2(string a)
{
    int c=a.size();
    string res="";
    int t=0;
    int i;
    for(i=0;i<c;i++)
    {
        t=t*10+(a[i]-'0');
        res+=(char)(t/2+'0');
        t%=2;
    }
    i=0;
    return res.substr(i);
}
string C[61][61];
int U;
int N;
string pattern="";
string ref;
map<int,int> nums;
int u;
int i,j;
int res[60];
string t="0";
string m;
string tmp;
void calcC()
{
     for(i=1;i<=U;i++)
     {
         C[i][0]=C[i][i]="1";
         for(j=1;j<i;j++)
             C[i][j]=add(C[i-1][j],C[i-1][j-1]);
     }
}
void init()
{
     int a;
     scanf("%d %d",&N,&U);
     for(i=0;i<N;i++)
     {
         scanf("%d",&a);
         if(nums.find(a)==nums.end())
             nums.insert(make_pair(a,nums.size()));
         pattern+=nums[a];
     }
     u=nums.size();
     for(map<int,int>::iterator it=nums.begin();it!=nums.end();it++)
         ref=ref+(char)(*it).second;
}
void solve()
{
    int i=1;
    for(j=u;j>0;j--)
    {
        for(;i<U-j+1;i++)
            if(cmp(tmp=add(C[U-i][j-1],t),m)==-1)t=tmp;
            else break;
        res[ref[u-j]]=i;
    }
}
int main()
{
    init();
    calcC();
    m=add(del2(add(C[U][u],"1")),"1");
    solve();
    for(i=0;i<N;i++)
        printf("%d ",res[pattern[i]]);
    printf("\n");
    return 0;
}
