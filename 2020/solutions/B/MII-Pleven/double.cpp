#include <bits/stdc++.h>
using namespace std;

multiset <int> s;
int n, w1, w2, a[2001];

int main (){
int i;

    scanf("%d%d%d", &n, &w1, &w2);
    for(i=1;i<=n;i++){
        scanf("%d", &a[i]);
        s.insert(-a[i]);
    }

    //sort(a+1, a+n+1);
    int ww1, ww2, sum=0;
    ww1=max(w1,w2);
    ww2=min(w1,w2);
    int p;
    for(i=n;i>=1;i--){
        p=*s.begin();
        s.erase(s.begin());
        if(-p<=ww1){
            ww1+=p;
            sum-=p;
            if(ww1<ww2) swap(ww1,ww2);
        }
    }

    printf("%d", sum);

    return 0;
}
