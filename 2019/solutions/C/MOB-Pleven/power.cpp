#include<iostream>
#include<vector>
using namespace std;
int main()
{
int n,k;
cin>>n>>k;
int g,g1;
vector<int>a(43,0);
int counter=0;
for(int i=0;i<n;i++)
{
    cin>>g;
    g1=g;
    for(int j=2;j<=g1;j++)
    {
        counter=0;
        while(g%j==0)
        {
            g/=j;
            counter++;
        }
        a[j]=max(counter,a[j]);
    }
}
unsigned long long output=1;
for(int i=2;i<a.size();i++)
{
    if(a[i]%k!=0)a[i]=a[i]-a[i]%k+k;
    for(int j=0;j<a[i]/k;j++)
    {
        output*=i;
    }
}
cout<<output<<endl;
return 0;
}
/**
43 999
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 42
*/
///HELLO
