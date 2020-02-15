#include<iostream>
using namespace std;
int cnt[100002], br;
int main()
{
    int n, num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        cnt[num]++;
    }
    int m, a, b;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        br=0;
        for(int j=a;j<=b;j++)
            br+=cnt[j];
        cout<<br<<endl;
        br=0;
    }
    return 0;
}
/**
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/
