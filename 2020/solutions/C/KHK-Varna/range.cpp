#include<iostream>
using namespace std;
int a[100005],b[100005];
int main()
{
int n,ch,m,maxi=0;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
    if(a[i]>maxi)maxi=a[i];
}
for(int i=0;i<n;i++)
{
    ch=a[i];
    while(ch<=maxi)b[ch]++,ch++;
}
cin>>m;
for(int i=0;i<m;i++)
{
    int nach,krai,izv1;
    cin>>nach>>krai;
    if(krai>maxi)izv1=n;
    else izv1=b[krai];
    if(nach>maxi)cout<<0<<endl;
    else cout<<izv1-b[nach-1]<<endl;
}
}
/**
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/
