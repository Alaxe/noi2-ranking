#include<bits/stdc++.h>
using namespace std;
vector<int> h;
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int broiSteni,a,b,B;
    long long obem=0;
    cin>>broiSteni>>a>>b;
    B=a*b;
    for(int i=0;i<broiSteni;i++) {
        int z;
        cin>>z;
        h.push_back(z);
    }
    for(int i=0;i<h.size();i++) {
        if(i+1<h.size()) {
            if(h[i]<=h[i+1]) {
//                cout<<h[i]*B<<" + ";
                obem=obem+h[i]*B;
            }else{
                int j;
                for(j=i+1;j<h.size() && h[i]>=h[j];j++) {

                }
                int maxH=h[j-1];
//                cout<<maxH*B*(j-i-1)<<" + ";
                obem=obem+maxH*B*(j-i-1);
                i=j;
            }
        }
    }
//    cout<<" = ";
    cout<<obem<<endl;
}

int main() {
    solve();


    return 0;
}
