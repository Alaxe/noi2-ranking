#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

const int MAXN = 200;
int n,w1,w2,br;
int a[MAXN+5];
stack <int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n>>w1>>w2;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) s.push(a[i]);
    while(!s.empty())
    {
        int z = s.top();s.pop();
        if(w2-z>=0) {br+=z;w2-=z;}
        else if(w1-z>=0) {br+=z;w1-=z;}
    }
    cout << br << '\n';
    return 0;
}
