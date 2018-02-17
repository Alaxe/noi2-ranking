#include<iostream>
#include<cmath>
using namespace std;
int a[1024],par[1024],used[1000003],otr[1000003];
int main() {
    int n,i,j,br=0,k;
    cin>>n;
    par[0]=0;
    for(i=1; i<=n; i++) {
        cin>>a[i];
        if(a[i]<0) {
            int tr=abs(a[i]);
            if(!used[tr]) {
                otr[tr]=1;
                br++;
            }
        } else {
            if(!used[a[i]]) {
                used[a[i]]=1;
                br++;
            }
        }

        par[i]=par[i-1]+a[i];
    }
    for(i=1; i<=n; i++) {
        for(j=i+1; j<=n; j++) {
            int tem=par[j]-par[i-1];
            if(tem<0) {
                int tk=abs(tem);
                if(!otr[tk]) {
                    br++;
                    otr[tk]=1;
                }
            } else if(!used[tem]) {
                br++;
                used[tem]=1;
            }
            tem=a[i]+a[j];
            if(tem<0)
            {
                tem*=-1;
                if(!otr[tem])
                {
                    br++;
                    otr[tem]=1;
                }
            }
            else
            {
                if(!used[tem])
                {
                    br++;
                    used[tem]=1;
                }
            }
            tem=a[n]-a[j-1]+a[i];
            if(tem<0)
            {
                tem*=-1;
                if(!otr[tem])
                {
                    br++;
                    otr[tem]=1;
                }
            }
            else
            {
                if(!used[tem])
                {
                    br++;
                    used[tem]=1;
                }
            }
            tem=a[n]-a[j-1]+par[i];
            if(tem<0)
            {
                tem*=-1;
                if(!otr[tem])
                {
                    br++;
                    otr[tem]=1;
                }
            }
            else
            {
                if(!used[tem])
                {
                    br++;
                    used[tem]=1;
                }
            }
        }
    }
    cout<<br<<endl;
    return 0;
}