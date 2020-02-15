#include<iostream>
#include<string>
using namespace std;
bool a[30];
string s,izv;
int main()
{
int n,brraz=0,maxb=0;
cin>>s;
n=s.size();
for(int i=0;i<n;i++)
{
int ind=int(s[i])-'A'+1;
if(a[ind]==false){brraz++;a[ind]=true;}
if(ind>maxb)maxb=ind;
}
for(int i=0;i<n;i++)
{
    long long br=0;
    for(int j=int(s[i])-'A'+1;j<=maxb;j++)if(a[j]==true)br++;
    cout<<char('A'+(brraz-br));
    izv+=char('A'+(26-br));
}
cout<<endl<<izv<<endl;
}
