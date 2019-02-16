#include <iostream>
#include <iomanip>
using namespace std;
#define endl '\n'
double ans[8], h[8];
void print_ans() {
    cout << fixed << setprecision(3) << ans[1];
    for (int i=2;i<=4;i++) cout << ' ' << ans[i];
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long s, d, k;
    cin >> s >> k >> h[1] >> h[2] >> h[3] >> d;
    if (k>=s*4*d or k%(4*d)==0) {
        for (int i=1;i<=4;i++) ans[i]=(double)d;
        print_ans();
        return 0;
    }
    int sektor=(k/(4*d)+1)%4;
    double k1=k-(k/(4*d)*(4*d));
    double maxh=h[3];
    if (4.0*h[3]<=k1) {
        for (int i=1;i<=4;i++) ans[i]=(double)(k1/4.0);
        print_ans();
        return 0;
    }
    if (sektor==1) swap(h[2],h[3]);
    if (sektor==2) swap(h[1],h[2]);
    if (sektor==3) {
        swap(h[1],h[3]);
        swap(h[1],h[2]);
    }
    if (sektor==0) {
        swap(h[3],h[2]);
        swap(h[2],h[1]);
    }
    h[4]=h[0]=d;
    int gr, ind;
    for (int i=1;i<=4;i++) {
        if (k1==0) break;
        gr=h[i-1];
        if (h[i]<=gr) {
            if (k1>h[i]) {
                ans[i]=h[i];
                k1-=h[i];
            } else {
                ans[i]=k1;
                k1=0;
                continue;
            }
        } else {
            ind=i;
            while (ans[i]<min(maxh,h[i])) {
                while (ind>=0 and ans[ind]==ans[i]) ind--;
                ind++;
                gr=h[ind-1];
                if (gr>=min(maxh,h[i])) {
                    if (k1<(i-ind+1)*(h[i]-ans[i])) {
                        for (int j=ind;j<=i;j++) ans[j]=ans[j]+(double)k1/(double)(i-ind+1.0);
                        k1=0;
                    } else {
                        k1-=(i-ind+1)*(h[i]-ans[i]);
                        for (int j=ind;j<=i;j++) ans[j]=h[i];
                    }
                    break;
                } else {
                    if (k1<(i-ind+1)*(gr-ans[i])) {
                        for (int j=1;j<=i;j++) ans[j]=ans[j]+(double)k1/(double)(i-ind+1.0);
                        k1=0;
                        break;
                    } else {
                        k1-=(i-ind+1)*(gr-ans[i]);
                        for (int j=ind;j<=i;j++) ans[j]=gr;
                    }
                }
            }
        }
    }
    print_ans();
    return 0;
}
