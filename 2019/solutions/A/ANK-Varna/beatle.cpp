#include<bits/stdc++.h>
using namespace std;
struct str
{
    int x;
    int y;
    int d;
};
str b[100005];
int ans[200005];
bool cmp(str a, str b)
{
    return a.y<b.y;
}
int main()
{
    int n;
    int m;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>b[i].x>>b[i].y>>b[i].d;
    }
    sort(b,b+n,cmp);
    for(int i=0; i<n; i++)
    {
    	m=min(ans[b[i].x],ans[b[i].x+b[i].d+1])+1;
    	for(int j=b[i].x+1;j<=b[i].x+b[i].d;j++)
		{
			ans[j]=m;
		}
    }

    cin>>m;
    int q;
   for(int i=0; i<m-1; i++)
    {
    	cin>>q;
        cout<<ans[q+1]<<" ";
    }
    cin>>q;
    cout<<ans[q+1]<<endl;
    return 0;
}
/*
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11


*/
