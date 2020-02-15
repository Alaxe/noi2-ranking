#include<iostream>
using namespace std;
int main ()
{
    int n,e,m,d,c,g;
    cin >> n;
    for (int i;i<n;i++)
    {
       e=n/1000%10;
       m=n/100%10;
       d=n/10%10;
       c=n%10;
       while (n!=0)
       {
           g=g*g+n%10;
           n=n/10;
       }
    }
     if (e==m || e==d || e==c || m==d || m==c || c==d)
     cout <<  n <<endl;
     return 0;
}
