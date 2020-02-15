#include <iostream>
using namespace std;
long long a[100000],b[100001],c[100000],x[100000],y[100000],z[100000];
int main () {
    long long m,n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        b[a[i]]++;
    }
    long long p=-1;
    for(int i=1;i<=100001;i++) {
            c[i]=c[i-1]+b[i];
            if(c[i]==n){
                p=i+1;
                break;
            }
    }
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>x[i]>>y[i];
        if(p<=x[i]) {
            z[i]=0;
        }else {
           if(p<=y[i]) {
            c[y[i]]=n;
        }
        if(c[x[i]]==0){
                z[i]=c[y[i]];
        }
        else {
            z[i]=c[y[i]]-c[x[i]]+1;
        }
        }
    }
    for (int i=0;i<m;i++) {
        cout<<z[i]<<endl;
    }
    return 0;
}
