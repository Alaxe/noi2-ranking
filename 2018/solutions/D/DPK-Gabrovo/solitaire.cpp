#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main ()
{
  int n;
  char a;
  int b[100][100],i,j;
  int sum[100][100];
  cin>>n;
  cin.get(a);
  for ( i=0;i<n;i++)
  {
      for ( j=0;j<n;j++)
      {
    cin.get(a);
      if (isdigit(a))b[i][j]=a-'0';
      else
      {
        if (a=='A')b[i][j]=1;
        if (a=='T')b[i][j]=10;
        if (a=='J')b[i][j]=11;
        if (a=='Q')b[i][j]=12;
        if (a=='K')b[i][j]=13;
      }
      cin.get(a);
      cin.get(a);
      }
  }
  sum[n-1][0]=b[n-1][0];
  for (i=n-2;i>=0;i--)
  {
      sum[i][0]=sum[i+1][0]+b[i][0];
  }
  for (i=1;i<n;i++)
  {
      sum[n-1][i]=sum[n-1][i-1]+b[n-1][i];
  }
  for (i=n-2;i>=0;i--)
  {
      for (j=1;j<n;j++)
      {
          sum[i][j]=b[i][j]+max(sum[i+1][j],sum[i][j-1]);
      }
  }


  cout<<sum[0][n-1]<<endl;
   return 0;
}



