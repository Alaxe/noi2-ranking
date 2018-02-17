///FINAL FAST (i think)
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned long long table[280][280];
int n, m;
unsigned long long min1(int a, int b, int c)
{
    return min( a , min ( b , c ) );
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0; i<280; i++)
    {
        table [i][0] = 1;
        table [i][1] = 1;
        table [0][i] = 1;
        table [1][i] = 1;
    }
    for(int i=2; i<=m; i++)
    {
        for(int j=i; j<=n; j++)
        {
            for(int k=1; k<=i; k++)
            {
                table [j][i] += table [ j-k ] [ min1(k,j-k,i) ];
                //if(j==6 && i==5)
                //cout<<table[j-k][min1(k,j-k,i)]<<" "<<j-k<<min1(k,j-k,i)<<endl;
            }
            //if(j==i)
            //table[j][i]++;
        }
        //cout<<endl;
    }
    if(m>n)
    {
        cout << table[n][n] << endl;
    }
    else
    {
        cout << table[n][m] << endl;
    }
    return 0;
}
