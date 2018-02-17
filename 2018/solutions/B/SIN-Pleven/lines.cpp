#include<iostream>
using namespace std;
int n,ans;
pair<double,double> points[1001];
int main ()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cout<<i<<" -> ";
        cin>>points[i].first>>points[i].second;
    }
    if (n==2)
    {
        cout<<2<<endl;
        return 0;
    }
    for (int i=1;i<=n-2;i++)
    {
        for (int j=i+1;j<=n-1;j++)
        {
///            cout<<points[j].second<<" "<<points[i].second<<" "<<points[j].first<<" "<<points[i].first<<endl;
            double a = (points[j].second - points[i].second)/(points[j].first - points[i].first)  , b = points[i].second - a*points[i].first;
///            cout<<a<<" "<<b<<endl;
            int cur=2;

            for (int k=j+1;k<=n;k++)
            {
                if (points[k].first == points[j].first && points[k].first == points[i].first) cur++;
                else if (points[k].first*a + b == points[k].second) cur++;
            }

            if (ans<cur) ans = cur;
        }
    }
    cout<<ans<<endl;
}
/**
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/

/**
1<n<1000
-100 <= xi,yi <= -100
*/
