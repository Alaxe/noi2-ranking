#include<iostream>
#include<deque>
using namespace std;
struct elem { long long int num;
              long long int day; };
deque <elem> nums;
int main () {
    long long int k,n,f,m,a,mod,ans=0,cur,i;
    elem p;
    cin >> n >> k ;
    cin >> f >> m >> a >> mod ;
    p.num=f; p.day=0;
    nums.push_back(p);
    cur=f; ans+=f;
    for (i=1; i<n; i++) {
        cur*=m; cur%=mod;
        cur+=a; cur%=mod;
        for (;;) {
            if ((nums.empty()==1)||(nums.back().num>cur)) {
               p.num=cur; p.day=i;
               nums.push_back(p);
               break;
               }
            nums.pop_back();
            }
        for (;;) {
            if ((i-nums.front().day)<k) break;
            nums.pop_front();
            }
        ans+=nums.front().num;
        }
    cout << ans ;
    cout << endl ;
    return 0;
}
