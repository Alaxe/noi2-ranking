//#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 11384
short F[MAXN][MAXN]={};
long long area[MAXN]={};
int h, w, a[MAXN], b[MAXN], n, w1[MAXN], h1[MAXN], i, j, l, qx, qy, t, it;
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    scanf("%d %d", &w, &h);
    area[0]=w*h;
    scanf("%d", &n);

    for(i=1;i<=n;i++){
        scanf("%d %d %d %d", &a[i], &b[i], &w1[i], &h1[i]);
        area[i]=w1[i]*h1[i];
        bool flag=false;
        for(j=b[i];j>0;j--){
                //cout<<a[i]<<" "<<j<<" "<<F[j][a[i]]<<endl;
            if(F[j][a[i]]!=0&&((a[F[j][a[i]]]<=a[i]&&a[i]<=(a[F[j][a[i]]]+w1[F[j][a[i]]]))&&(b[F[j][a[i]]]<=b[i]&&b[i]<=(b[F[j][a[i]]]+h1[F[j][a[i]]])))){
                area[F[j][a[i]]]-=area[i];
                flag=true;
                break;
                //cout<<i<<endl;
            }
        }
        if(flag==false) area[0]-=area[i];
        for(j=a[i];j<a[i]+w1[i];j++)
                F[b[i]][j]=i;

    }

    //for(i=1;i<=n;i++) cout<<area[i]<<endl;

    scanf("%d", &t);
    for(it=0;it<t;it++){
        bool flag=false;
        scanf("%d %d", &qx, &qy);
        for(j=qy;j>=0;j--){
                //cout<<a[i]<<" "<<j<<" "<<F[j][a[i]]<<endl;
            if(F[j][qx]!=0&&((a[F[j][qx]]<=qx&&qx<=(a[F[j][qx]]+w1[F[j][qx]]))&&(b[F[j][qx]]<=qy&&qy<=(b[F[j][qx]]+h1[F[j][qx]])))){
                printf("%lld\n", area[F[j][qx]]);
                flag=true;
                break;
            }
        }
        if(flag==false) printf("%lld\n", area[0]);
    }

    /*for(j=0;j<h;j++){
        for(l=0;l<w;l++)
            cout<<F[j][l]<<" ";
        cout<<endl;
    }*/
    return 0;
}
/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3

6 5
2
1 1 2 2
4 0 2 4
5
2 2
5 1
5 4
1 4
2 4
*/
