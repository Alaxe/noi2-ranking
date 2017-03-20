#include <iostream>
#define maxn 1000
using namespace std;
int a[maxn];
int diff[maxn][maxn], dyn[maxn][maxn];
int main()
{
    int n;
    cin>>n;
    int x,y;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int maxDiff = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            diff[i][j] = a[j] - a[i];
            if(diff[i][j]>maxDiff){
                maxDiff = diff[i][j];
            }
        }
    }

    int result = 0;
    for (int d = 1; d<=maxDiff; d++)
    {

        for(int i = 0; i < n; i++)
        {
            dyn[i][i] = 1;
            for(int j = i+1; j < n; j++)
            {
                dyn[i][j] = 0;
                if(diff[i][j] == d)
                {
                    for(int p = 0; p <= i; p++)
                    {
                        dyn[i][j] += dyn[p][i];
                    }
                    result += dyn[i][j];
                }
            }
        }

    }
    cout<<result<<endl;
    return 0;

}
