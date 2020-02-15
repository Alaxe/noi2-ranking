#include <iostream>
using namespace std;

int main(){

    int n, w1, w2;
    cin>>n>>w1>>w2;
    int d[n];
    int k1 = 0, k2 = 0;
    for (int i=0; i<n; i++){
        cin>>d[i];
        k1 += d[i];
    }
    int a[n];
    for (int i=0; i<n; i++) a[i]=d[i];
    int temp;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (a[j]>a[i]){
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    temp = 0;
    if (w2>w1){
        temp = w1;
        w1 = w2;
        w2 = temp;
    }
    int aat = 0;
    for (int i=n-1; i>=0; i--){
        k1 -= a[i];
        k2 += a[i];
        if (k1<=w1) {
            aat = i;
            break;
        }
    }
    for (int i=n-1; i>=aat; i--){
        for (int j=aat-1; j>=0; j--){
            if (k2>w2){
                if ((k1+a[i])>k1 && (k1+a[i])==w1){
                    k1 += a[i];
                    k2 -= a[i];
                    a[i]=0;
                }
            }
            else {
                if (((k1-a[j])+a[i])>k1 && ((k1-a[j])+a[i])<=w1){
                    k1 -= a[j];
                    k1 += a[i];
                    k2 -= a[i];
                    k2 += a[j];
                    temp = a[j];
                    a[j]=a[i];
                    a[i]=temp;
                }
            }
        }
    }
    if (k1<w1){
        for (int i=n-1; i>=aat; i--){
            for (int j=aat-1; j>=0; j--){
                if (k2>w2){
                    if ((k1+a[i])>k1 && (k1+a[i])<=w1){
                        k1 += a[i];
                        k2 -= a[i];
                        a[i]=0;
                    }
                }
            }
        }
    }
    if (k2>w2){
        for (int i=aat; i<n; i++){
            k2 -= a[i];
            if (k2<=w2) break;
        }
    }
    int case1 = k1 + k2;

    int m=0, mn=0;
    temp=0;
    if (w2>w1) {
        temp = w1;
        w1 = w2;
        w2 = temp;
    }
    k1=0; k2=0;
    for (int i=0; i<n; i++) a[i]=d[i];
    while (true) {
        for (int i=0; i<n; i++){
            if (k1+a[i]<=w1 && a[i]>m){
                m = a[i];
                mn = i;
            }
        }
        if (m==0) break;
        k1 += m;
        m=0;
        a[mn]=-1;
    }
    while (true){
        for (int i=0; i<n; i++){
            if (k2+a[i]<=w2 && a[i]>m){
                m = a[i];
                mn = i;
            }
        }
        if (m==0) break;
        k2 += m;
        m=0;
        a[mn]=-1;
    }
    int case2 = k1 + k2;
    if (case1>case2) cout<<case1<<endl;
    else cout<<case2<<endl;

return 0;
}
