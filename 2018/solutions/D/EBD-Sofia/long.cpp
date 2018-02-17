#include<iostream>
using namespace std;
int main()
{
     int n,k;
     cin>>n>>k;
     long long ch=10,r;
     for (int i=2;i<n;i++)
     {
          ch=ch*10;
     }
     r=ch/k+1;
     if(ch%k!=0)
     {
          cout<<r*k<<endl;
     }
     else
     {
          cout<<ch<<endl;
     }
     return 0;
}
