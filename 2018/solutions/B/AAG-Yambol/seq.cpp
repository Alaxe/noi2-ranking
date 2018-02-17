#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define pb push_back
#define mp make_pair
using namespace std;
const int N=275;

int n,m;

long long part[N][N],all_part[N];
long long ans;

void calc_part()
{
    int i,j;

    part[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            part[i][j]+=part[i-1][j-1] + part[i-j][j];
        }
    }
}

long long troll_part[N][N][N];
void troll_partition()
{
    int i,j,k;
    long long sum_all;

    troll_part[0][1][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
          //  sum_all=0;
            for(k=1;k<=m;k++)
            {
                troll_part[i][j][k]+=troll_part[i-j][j][k-1] + troll_part[i-1][j-1][k];

                //sum_all+=troll_part[i-1][j-1][k];
            }

        }
    }
}

int main()
{
   int i,j,k;
   cin>>n>>m;

   if(m > n)
    m=n;

 //  calc_part();

   troll_partition();

   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           ans+=troll_part[n][i][j];
       }
   }

 /*  for(i=1;i<=n;i++)
   {
       for(j=1;j<=i;j++)
       {
           for(k=1;k<=m;k++)
           {
               cerr<<troll_part[i][j][k]<<" ";
           }
           cerr<<endl;
       }
       cerr<<" -------- "<<endl;
   } */



   cout<<ans<<endl;


   return 0;
}


/*
270 270

1050197489931117

*/
