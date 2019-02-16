#include<iostream>
using namespace std;
const int MAXN=1024;
int a,br=0;
int main()
{
    int k,m,n;
    cin>>k>>m>>n;
a=0;
if(k>=m){cout<<0;return 0;}

    for(int j=1;j<m;j++)
   {
         a++;
    if(a+k<m&&a-k>0)br++;
   }

   cout<<(m-1+br)+(n-2)*((m-(2*k)))<<endl;

    return 0;
}
