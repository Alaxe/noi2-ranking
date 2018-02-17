#include <iostream>
using namespace std;
int a[1000];
int b[8];
int n,k,j;
int i=0;
void plu (int r)
{
    a[r]++;
    if (a[r]==10)
    {a[r]=0;
    plu(r+1);
    }
}
int del ()
{
    int t=0;
    for (int z=n-1;z>=0;z--)
    {
        t=t*10+a[z];

        if(t%k==0){t=0;continue;}
        t=t%k;
    }
    if (t==0)return true;
    else return false;
}
int main ()
{
   cin>>n>>k;
   a[n-1]=1;
   for (j=0;j<k;j++)
   {

       if (del())
       {

           for (int z=n-1;z>=0;z--)cout<<a[z];
           cout<<endl;
           return 0;
       }plu(0);
   }


}
