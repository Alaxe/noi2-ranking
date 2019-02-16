#include<iostream>
using namespace std;

int main()
{
   int k, m , n;
   cin >> k >> m >> n;

   int a[n+1][m];
   for(int i=1; i<m; i++)
    a[1][i]=1;

   for(int i=2; i<=n; i++)
    for(int p=1; p<m; p++)
     {
        if(p>k && p<m-k)
         a[i][p]=a[i-1][p-k]+a[i-1][p+k];
        else if(p<m-k)
         a[i][p]=a[i-1][p+k];
        else if(p>k)
         a[i][p]=a[i-1][p-k];
        else
         a[i][p]=0;
     }

   int counter=0;
   for(int i=1; i<m; i++)
    counter+=a[n][i];

   cout << counter << endl;

   return 0;
}
