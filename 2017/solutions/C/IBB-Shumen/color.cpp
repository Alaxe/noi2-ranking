#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int pr,n,t;
vector<int>v[10003][10003];
void init()
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<v[t][i].size();j++)v[t][i][j]=0;
    }
}
int main() {
    int i,j,x,k;
    cin>>t;
    for(k=0; k<t; k++) {
        cin>>n;
        for(j=1; j<=n; j++) {
            cin>>x;
            v[k][x].push_back(j);
        }
        init();
        int msz=0;
        for(i=1; i<=n; i++) {
            if(v[k][i].size()>msz)msz=v[k][i].size();
        }
        cout<<msz+1<<endl;
        if(k==t-2)break;
    }

    return 0;
}