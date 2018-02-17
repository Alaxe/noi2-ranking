#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
 int N;
 cin>>N;
 string a[N][N];
 int sum=0;
 int n=N-1;
 for (int i=0;i<N;i++)
 {
     for (int j=0;i<N;j++)
     {
         cin>>a[i][j];
         if (a[i][j]==a[0][n])
         {
             if (a[i][j]/10=='A')sum=sum+1;
             else if (a[i][j]/10=='T')sum=sum+10;
             else if (a[i][j]/10=='J')sum=sum+11;
             else if (a[i][j]/10=='Q')sum=sum+12;
             else if (a[i][j]/10=='K')sum=sum+13;

         }
             if (a[i][j]/10=='A')a[i][j]=1;
             else if (a[i][j]/10=='T')a[i][j]=10;
             else if (a[i][j]/10=='J')a[i][j]=11;
             else if (a[i][j]/10=='Q')a[i][j]=12;
             else if (a[i][j]/10=='K')a[i][j]=13;

     }
 }
 int b=a[0][0];
 int i=0;
 int j=n;
 while (b=a[n][0])
 {
     if (a[i][j-1]>a[i+1][j])
     {sum=sum+a[i][j-1];
     b=a[i][j-1];
     j--;
     }
     else
     {sum=sum+a[i+1][j];
     b=a[i+1][j];
     i++;

 }
 }
cout<<sum<<endl;
    return 0;
}
