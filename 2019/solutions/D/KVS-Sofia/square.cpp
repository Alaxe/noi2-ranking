#include<bits/stdc++.h>
using namespace std;
long long del[42];
long long prosti[13]={2,3,5,7,11,13,17,19,23,29,31,37,41};
long long brDel[13];
bool razl[43];
void kanon(long long a){
    razl[a]=true;
    for(long long i=0;i<13;i++){
        if(prosti[i]>a)break;
        long long h=0;
        while(a%prosti[i]==0){
            h++;
            a/=prosti[i];
        }
        brDel[i]=max(brDel[i],h);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N,c=1,a;
    cin>>N;
    for(long long i=0;i<N;i++){
        cin>>a;
        if(!razl[a]) kanon(a);
    }
    for(long long i=0;i<13;i++)
        for(long long j=0;j<brDel[i]/2+brDel[i]%2;i++)
            c*=prosti[i];
    cout<<c<<endl;
    return 0;
}
/*
42
1 2 3 4  5 6 7 8 9
10 11 12 13 14 15 16 17 18 19
20 21 22 23 24 25 26 27 28 29
30 31 32 33 34 35 36 37 38 39
40 41 42
*/
