#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
vector<int>a;
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int k,y;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        int r=upper_bound(a.begin(),a.end(),y)-a.begin();
        int t=lower_bound(a.begin(),a.end(),x)-a.begin();
        cout<<r-t<<endl;
    }
return 0;
}
/**
papa joni
misho si schupi kirkata
ivanje
*/
