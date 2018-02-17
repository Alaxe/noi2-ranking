#include<iostream>
#include<deque>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    unsigned long long fun,mul,add,mod,ans=0;
    cin>>fun>>mul>>add>>mod;
    deque<pair<unsigned long long,int> > stories;
    for(int i=0;i<n;i++){
        while(!stories.empty()&&fun>stories.back().first){
                stories.pop_back();
        }
        stories.push_back(make_pair(fun,i));
        ans+=stories.front().first;
        if(stories.front().second+(k-1)==i){
            stories.pop_front();
        }
        fun=((fun*mul)%mod+add)%mod;
    }
    cout<<ans<<"\n";
    return 0;
}
