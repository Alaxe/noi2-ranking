#include <iostream>
#include <algorithm>
using namespace std;
long long n,i=0,j=0;
int main()
{
    string br;
  cin>>n;
  string a[101][101];

  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
  {
      cin>>a[i][j];

 }
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
  {
       if(a[i][j]=="AC") a[i][j]=1;
      else if(a[i][j]=="2C") a[i][j]=2;
      else if(a[i][j]=="3C") a[i][j]=3;
      else if(a[i][j]=="4C") a[i][j]=4;
      else if(a[i][j]=="5C") a[i][j]=5;
      else if(a[i][j]=="6C") a[i][j]=6;
      else if(a[i][j]=="7C") a[i][j]=7;
      else if(a[i][j]=="8C") a[i][j]=8;
      else if(a[i][j]=="9C") a[i][j]=9;
      else if(a[i][j]=="TC") a[i][j]=10;
      else if(a[i][j]=="JC") a[i][j]=11;
      else if(a[i][j]=="QC") a[i][j]=12;
      else if(a[i][j]=="KC") a[i][j]=13;

      if(a[i][j]=="AD") a[i][j]=1;
      else if(a[i][j]=="2D") a[i][j]=2;
      else if(a[i][j]=="3D") a[i][j]=3;
      else if(a[i][j]=="4D") a[i][j]=4;
      else if(a[i][j]=="5D") a[i][j]=5;
      else if(a[i][j]=="6D") a[i][j]=6;
      else if(a[i][j]=="7D") a[i][j]=7;
      else if(a[i][j]=="8D") a[i][j]=8;
      else if(a[i][j]=="9D") a[i][j]=9;
      else if(a[i][j]=="TD") a[i][j]=10;
      else if(a[i][j]=="JD") a[i][j]=11;
      else if(a[i][j]=="QD") a[i][j]=12;
      else if(a[i][j]=="KD") a[i][j]=13;

      if(a[i][j]=="AH") a[i][j]=1;
      else if(a[i][j]=="2H") a[i][j]=2;
      else if(a[i][j]=="3H") a[i][j]=3;
      else if(a[i][j]=="4H") a[i][j]=4;
      else if(a[i][j]=="5H") a[i][j]=5;
      else if(a[i][j]=="6H") a[i][j]=6;
      else if(a[i][j]=="7H") a[i][j]=7;
      else if(a[i][j]=="8H") a[i][j]=8;
      else if(a[i][j]=="9H") a[i][j]=9;
      else if(a[i][j]=="TH") a[i][j]=10;
      else if(a[i][j]=="JH") a[i][j]=11;
      else if(a[i][j]=="QH") a[i][j]=12;
      else if(a[i][j]=="KH") a[i][j]=13;

      if(a[i][j]=="AS") a[i][j]=1;
      else if(a[i][j]=="2S") a[i][j]=2;
      else if(a[i][j]=="3S") a[i][j]=3;
      else if(a[i][j]=="4S") a[i][j]=4;
      else if(a[i][j]=="5S") a[i][j]=5;
      else if(a[i][j]=="6S") a[i][j]=6;
      else if(a[i][j]=="7S") a[i][j]=7;
      else if(a[i][j]=="8S") a[i][j]=8;
      else if(a[i][j]=="9S") a[i][j]=9;
      else if(a[i][j]=="TS") a[i][j]=10;
      else if(a[i][j]=="JS") a[i][j]=11;
      else if(a[i][j]=="QS") a[i][j]=12;
      else if(a[i][j]=="KS") a[i][j]=13;
  }
 br=a[n][n];
/* for(i=1;;)
for(j=n;;)
  {
    if(a[i][j+1])
  }*/
cout<<br;
  return 0;
}
