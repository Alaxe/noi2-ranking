#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int main(){
    long long n, k, first, mul, add, mod, i, fun, sum=0;
    priority_queue<pair<long long, long long>>q;
    cin >> n >> k >> first >> mul >> add >> mod;
    fun = first;
    for(i=0; i<n; i++){
        q.push(make_pair(fun, i));
        while(i - q.top().second >= k){
            q.pop();
        }
        sum += q.top().first;
        fun = (fun*mul + add) % mod;
    }
    cout << sum << '\n';
    return 0;
}
