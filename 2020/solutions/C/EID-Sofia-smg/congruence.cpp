#include<bits/stdc++.h>
using namespace std;
multiset<pair<int, long long>> s;
char c;
int num, i, m, N, a[15000000];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>c){
        num=c;
        s.insert({num, i});
        i++;
    }
    N=i;
    auto it=s.begin();
    auto it2=s.begin();
    a[(*it).second]=0;
    it++;
    for(; it!=s.end(); it++){
        if((*it).first==(*it2).first)a[(*it).second]=a[(*it2).second];
        else{
            a[(*it).second]=a[(*it2).second]+1;
            m=a[(*it2).second]+1;
        }
        it2++;
    }
    for(i=0; i<N; i++){
        c='A'+a[i];
        cout<<c;
    }
    cout<<endl;
    for(i=0; i<N; i++){
        c='Z'+a[i]-m;
        cout<<c;
    }
    cout<<endl;
    return 0;
}
