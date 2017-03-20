#include <bits/stdc++.h>

using namespace std;

const int N = (1e7) + 7;

unsigned n,k,first,mul,add,mod,a[N];
unsigned long long ans;
unsigned d[N],from,to;

void insert_it(unsigned value) {
    while(from<=to && d[to]<value) --to;
    d[++to]=value;
}

void erase_it(unsigned value) {
    if(from<=to) if(d[from]==value) ++from;
}

unsigned get() {
    return d[from];
}

int main() {
    unsigned i;

    from=1;
    to=0;
    cin>>n>>k;
    cin>>first>>mul>>add>>mod;
    a[1]=first;
    for(i=2;i<=n;i++) a[i]=(a[i-1]*1llu*mul + 0llu + add)%mod;
    ans=0;
    for(i=1;i<=k;i++) {
        insert_it(a[i]);
        ans+=get();
    }
    for(i=k+1;i<=n;i++) {
        insert_it(a[i]);
        erase_it(a[i-k]);
        ans+=get();
    }
    cout<<ans<<endl;

    //fprintf(stderr, "Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));

    return 0;
}
