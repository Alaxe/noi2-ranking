#include<iostream>
using namespace std;
int main()
{
 int n, a, b, sbor=0, m, max;
 cin>>n;
 int c[n-1], d[n-1], e[n-1];
 for(int i=0; i<n; i++)
 {
    cin>>a>>b;
    c[i]=a;
    d[i]=b;
 }
 for(int k=0; k<n; k++)
 {
 for(int j=0; j<=n; j++)
 {
     if(c[0]==c[j+1]) m++;
     if(c[0]==d[j+1] && c[0]!=d[j+1]) m++;
     if(d[0]==c[j+1]) m++;
     if(d[0]==d[j+1] && d[0]!=c[j+1]) m++;
     if(m!=0) sbor++;
     m=0;
 }
    e[k]=sbor;
    sbor=0;
 }
 max=e[0];
 for(int l=1; l<n; l++)
 {
     if(max<=e[l]) max=e[l];
 }
 cout<<endl<<max;
 return 0;
}
