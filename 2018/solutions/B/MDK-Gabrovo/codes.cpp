//3-4 часа на тази задача, накрая тръгна
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
long long where(int p,long long w,long long x)
{
if(p%2==1)return x-w*(p-1);
return w-(x-w*(p-1))+1;
}
int n,k;
char inp[nmax];
long long a,b;
int s(string now)
{
int SZ=now.size(),s=0;
for(int i=0;i<SZ;i++)s=s+(now[i]-'0');
//cout<<now<<"->"<<s<<endl;
return s;
}
long long st[70];
string take(long long x,int k_now)
{
//cout<<x<<" "<<k_now<<endl;
if(k_now==1)
{
string res="";
res=res+inp[x];
return res;
}
long long w=st[k_now-1];
int p=(x+w-1)/w;
//cout<<"p= "<<p<<endl;
string ans;
ans=take(where(p,w,x),k_now-1);
//cout<<"ans= "<<ans<<endl;
ans=inp[p]+ans;
//cout<<"ans= "<<ans<<endl;
return ans;
}
void brute_force()
{
int ans=0;
string biggest;
string prev=take(a,k);
biggest=prev;
//cout<<a<<" -> "<<prev<<endl;
for(long long i=a+1;i<=b;i++)
{
string now=take(i,k);
//cout<<i<<" -> "<<now<<endl;
ans=max(ans,abs(s(now)-s(prev)));
if(biggest<now)
{
//cout<<i<<" "<<now<<endl;
biggest=max(biggest,now);
}
prev=now;
}

cout<<biggest<<" "<<ans<<endl;
}

string query(int k_now,long long A,long long B)
{
if(A>B)swap(A,B);
//cout<<k_now<<" "<<A<<" "<<B<<endl;
if(k_now==1)
{
char maxi='0';
    for(long long i=A;i<=B;i++)maxi=max(maxi,inp[i]);
string res="";
res=res+maxi;
return res;
}
//cout<<st[k_now-1]<<" "<<B-A+1<<endl;
if(st[k_now]==B-A+1)
{
string ans="";
char maxi='0';
for(int i=1;i<=n;i++)maxi=max(maxi,inp[i]);
for(int i=1;i<=k_now;i++)ans=ans+maxi;
return ans;
}
long long w=st[k_now-1];
int p=(A+w-1)/w,q=(B+w-1)/w;
//cout<<p<<" "<<q<<endl;
if(p==q)
{
string ans;
if(p%2==0)ans=query(k_now-1,w-(B-w*(p-1)-1),w-(A-w*(p-1)-1));
else ans=query(k_now-1,A-w*(p-1),B-w*(p-1));
//cout<<"ans= "<<ans<<endl;
ans=inp[p]+ans;
//cout<<"ans= "<<ans<<endl;
return ans;
}
char maxi='0',full='0'-1;
for(int i=p;i<=q;i++)maxi=max(maxi,inp[i]);
for(int i=p+1;i<q;i++)full=max(full,inp[i]);
if(maxi==full)
{
//имаме пълен интервал
string ans="";
ans=ans+maxi;
char real_max='0';
for(int i=1;i<=n;i++)real_max=max(real_max,inp[i]);
for(int i=2;i<=k_now;i++)ans=ans+real_max;
return ans;
}
string ans="";
//имаме само 2 подзачаци, които представляват интерес

if(inp[p]==maxi)
{
string now="";
now=query(k_now-1,where(p,w,A),where(p,w,w*p));
//cout<<"ans= "<<ans<<endl;
now=inp[p]+now;
ans=max(ans,now);
}

if(inp[q]==maxi)
{
string now="";
now=query(k_now-1,where(q,w,B),where(q,w,w*(q-1)+1));
//cout<<"ans= "<<ans<<endl;
now=inp[q]+now;
ans=max(ans,now);
}
//cout<<k_now<<" "<<A<<" "<<B<<" "<<ans<<endl;
return ans;
}

void fast()
{
cout<<query(k,a,b);
int ans=0;
for(int i=2;i<=n;i++)ans=max(ans,abs(inp[i]-inp[i-1]));
cout<<" "<<ans<<endl;
}
int main()
{
    cin>>n>>k>>a>>b;
    for(int i=1;i<=n;i++)cin>>inp[i];
    long long mem=1,q=1;
    while(mem<=b/n)
    {
    mem=mem*n;
    q++;
    }
    if(q<k)
    {
    for(int p=q+1;p<=k;p++)cout<<inp[1];
    k=q;
    }
    st[0]=1;
    for(int i=1;i<k;i++)st[i]=st[i-1]*n;
    //вече n^(k-1)<=b

    if(b-a<=1000)brute_force();
    else fast();
    return 0;
}
/*
3 2 3 5
7 1 5

3 3 10 16
7 1 5


2 10000 999999999999999000 1000000000000000000
5 7

2 10000 1 1000000000000000000
5 7

2 3 1 3
2 4

8 4 971 3507
6 0 2 4 1 8 1 9

10 4 1554 3524
4 4 3 8 0 9 9 4 0 3

10 4 1231 3773
6 5 0 0 2 2 0 1 2 1

7 4 14 1670
9 4 7 6 3 6 7

8 4 1942 3247
7 0 8 3 0 3 6 1


*/
