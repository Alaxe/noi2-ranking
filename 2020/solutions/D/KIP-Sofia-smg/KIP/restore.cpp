#include<bits/stdc++.h>
using namespace std;
vector<long long> b;
long long a[100010];
bool ostanali[100010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long broiChisla;
    cin>>broiChisla;
    for(long long i=0;i<broiChisla;i++) {
        long long z;
        cin>>z;
        b.push_back(z);
    }
    for(long long i=0;i<broiChisla;i++) {
        ostanali[i]=1;
    }
    long long broiNamereni=0;
    long long predishen=-3;
    for(int i=0;i<b.size();i++) {
        if(b[i]==0) {
            if(predishen==-3) {
                predishen=i;
            }
            a[i]=broiChisla-(i-predishen);
            ostanali[i]=0;
            broiNamereni++;
            //cout<<i<<endl;
        }
    }
    a[0]=broiChisla-b[0];
    long long broiOstanali=0;
    for(int i=0;i<b.size();i++) {
        long long chislo=b[i];
        if(ostanali[chislo]) {
          //  cout<<broiChisla-broiNamereni<<" ";
            a[i]=broiChisla-broiNamereni;
            ostanali[chislo]=0;
            broiNamereni++;
        }
    }
    for(int i=0;i<broiChisla;i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}
