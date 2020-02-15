#include<bits/stdc++.h>
using namespace std;
long long i, a[100003], B, C, N, stepen, novbr, M;
pair<long long, long long> tree[400012];
long long findnextx(long long k){
    i=2;
    long long br=1;
    while(i<k){
        br++;
        i*=2;
    }
    return br;
}
void builtd(long long ind){
    tree[ind]={tree[2*ind].first, tree[2*ind+1].second};
    if(ind==1)return ;
    builtd(ind-1);
}
long long proverka(long long ind, long long left, long long right, long long sl, long long sr){
    if(sr<tree[ind].first or sl>tree[ind].second)return 0;
    if(sr>=tree[ind].second and sl<=tree[ind].first)return right-left+1;
    long long middle=(right+left)/2;
    return proverka(2*ind, left, middle, sl, sr)+proverka(2*ind+1, middle+1, right, sl, sr);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(i=0; i<N; i++){
        cin>>a[i];
    }
    sort(a, a+N);
    stepen=findnextx(N);
    novbr=i;
    for(i=0; i<N; i++){
        tree[i+novbr]={a[i], a[i]};
    }
    for(; i<novbr; i++){
        tree[i+novbr]={100003, 100003};
    }
    builtd(novbr-1);
    cin>>M;
    for(i=0; i<M; i++){
        cin>>B>>C;
        cout<<proverka(1, 0, novbr-1, B, C)<<endl;
    }
    return 0;
}
