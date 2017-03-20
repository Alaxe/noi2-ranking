#include<iostream>
using namespace std;
int main(){
    long k, e, s=0, cn, ci=1;
    cin>>k>>e;
    long num[e+1], sd=k, sdi, ri[e+1], cri = 1;
    while(1){
        cin>>cn;
        if(cn==200) break;
        if(cn%2==0){
            num[ci] = cn;
            ri[ci] = cri;
            s += cn;
            ci++;
        }
        cri++;
        if(s>=e) break;
    }
    for(long c=ci-1;c>=1;c--){
        if(k<=num[c]){
            if(num[c]-k<sd){
                sd = num[c]-k;
                sdi = ri[c];
            }
        } else {
            if(k-num[c]<sd){
                sd = k-num[c];
                sdi = ri[c];
            }
        }
    }
    cout<<sdi<<' '<<s;

    return 0;
}
