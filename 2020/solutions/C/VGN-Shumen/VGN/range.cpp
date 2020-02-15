#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 100001;
int n,k, br[MAXN];
int ans(int a, int b)
{
    int cnt = 0;
    for(int i=a; i<=b; i++)
    {
        cnt += br[i];
    }
    return cnt;
}
void read()
{
    //cin >> n ;
    scanf("%d",&n);
    int x;
    for(int i=0; i<n; i++)
    {
        //cin >> x ;
        scanf("%d",&x);
        br[x] ++;
    }
    //cin >> k ;
    scanf("%d",&k);
    int a,b;
    for(int i=0; i<k; i++)
    {
        //cin >> a >> b ;
        scanf("%d""%d",&a,&b);
        cout << ans(a,b) << endl;
    }
}
int main()
{
	read();
    return 0;
}
