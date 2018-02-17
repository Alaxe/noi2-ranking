#include<iostream>
#include<cmath>
using namespace std;
long long zeros[100];
int main(){
    unsigned long long s,t, ans=0, st;
    int br1=0, br2=0;
    int cur;
    int z;
    cin>>s>>t>>z;
    st = s;
    while(s>0){
        cur = s%2;
        s/=2;
        br1++;
    }

    while(t>0){
        cur = t%2;
        t/=2;
        br2++;
    }

    int temp = 2;
    zeros[0] = 1;
    for(int j=0;j<br2-4;j++){
        zeros[0] += temp;
        for(int i=1;i<z-1;i++){
            if(j == 0) zeros[i] = 1;
            zeros[i] += zeros[i-1];
        }
        if(j>=br1-4) ans += zeros[z-2];
        temp++;
    }
    for(int i=st;i<=4;i++){
        int temp=i, m=0;
        while(temp>0){
            cur = temp%2;
            if(cur == 0) m++;
            temp/=2;
        }
        if(m == z) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
