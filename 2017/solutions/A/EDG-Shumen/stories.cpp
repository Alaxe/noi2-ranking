#include<iostream>
#include<deque>
using namespace std;
long long n,k,a,mul,ad,m;
long long ans=0;
void solve(){
    int i;
    deque<pair<long long,long long> >q(k);
    q.push_back(make_pair(a,0));
    ans=a;
    for(i=1;i<k;i++){
//            cout<<1<<' ';
        a=(a*mul+ad)%m;
//        cout<<1<<' ';
        while(!q.empty()&&(a>=(q.back()).first))
            q.pop_back();
//        cout<<1<<endl;
        q.push_back(make_pair(a,i));
        ans+=(q.front()).first;
    }
    for(;i<n;i++){
//        cout<<(q.front()).first<<' ';
//        cout<<1<<endl;
        a=(a*mul+ad)%m;
        while(!q.empty()&&((q.front()).second<=i-k))
            q.pop_front();
        while((!q.empty())&&a>=(q.back()).first)
            q.pop_back();
        q.push_back(make_pair(a,i));
        ans+=(q.front()).first;
    }
//    cout<<(q.front()).first<<endl;
    cout<<ans<<endl;
}
int main(){
    cin>>n>>k;
    cin>>a>>mul>>ad>>m;
    solve();
return 0;
}

/**
7 3
5 3 2 23

133742 666
20 3 17 1000000007
**/