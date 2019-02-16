#include <iostream>
#define endl '\n'
using namespace std;
int m[1000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

     long long n,k,brel=1,b=1,b2=0;
     cin>>n>>k;

     for(int t=1;;t++)
     {
         for(int i=1;;i++)
         {

             if(m[i]!=0) {m[i]+=2;}
             else {m[i]=1;break;}
         }
         if(m[n]==k)
         {
             cout<<brel-n+1+b2<<endl;
             return 0;
         }
         if(m[n]>k)
         {
             cout<<b2+n<<endl;
             return 0;
         }
         b2+=brel;
         brel+=2;
         b+=brel;
     }

}
