#include <iostream>

using namespace std;

int main()
{
   int n;
   cin>>n;
   int arr[n];
   for (int i=0; i<n; i++)
  {
      cin>>arr[i];
  }
   int m;
   cin>>m;
   int a[m],b[m];
   for (int e=0;e<m;e++ )
   {
       cin>>a[e];
       cin>>b[e];
   }
 int br=0;
 for (int y=0;y<m;y++)
 {
    for (int j=0; j<n; j++)
    {
        if (a[y]<=arr[j]&&arr[j]<=b[y]) br++;

    } cout<<br<<endl; br=0;
 }
    return 0;
}
