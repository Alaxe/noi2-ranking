#include<iostream>
using namespace std;
int main()
{
    int n,u,v,V=0,mas[100],i,j,bru=1;
    cin>>n>>u>>v;

     i=0;

    cin>>mas[i];
    for( j=1;j<n;j++)
    {
      cin>>mas[j];

      if(mas[i]>mas[j]&&mas[j]!= mas[n-1]) bru++;
      if(mas[i]>mas[j]&&mas[j]==mas[n-1]) {bru=1; V=u*v*mas[j]+V; mas[i]=mas[j];}

     if(mas[i]<mas[j]) V=u*bru*v*mas[i]+V;
      if(mas[i]<mas[j]) mas[i]=mas[j];

    }
       cout<<V<<endl;
      return 0;

}

