#include<bits/stdc++.h>
using namespace std;
long long N,K;
long long a[100005],x,y;
int dvoichnom(int n){
    int dolna=0,gorna=N-1;
    long long sreda;
    while(dolna<gorna){
        sreda=(gorna+dolna)/2;
        if(a[sreda]<n){
            dolna=sreda+1;
        }if(a[sreda]>=n){
            gorna=sreda;
        }
    }
    return dolna;
}

int dvoichnog(int n){
    int dolna=0,gorna=N-1;
    long long sreda;
    while(dolna<gorna){
        sreda=(gorna+dolna)/2;
        if(a[sreda]<=n){
            dolna=sreda+1;
        }if(a[sreda]>n){
            gorna=sreda;
        }
    }
    if(a[dolna]>n){
    return dolna-1;
    }
    else{
        return dolna;
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    sort(a,a+N);
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>x>>y;
        long long gorenindeks=dvoichnog(y);
        long long dolenindeks=dvoichnom(x);
        if(a[dolenindeks]>y or a[gorenindeks]<x){
           cout<<0<<"\n";

        }else{
        cout<<gorenindeks-dolenindeks+1<<"\n";
        }
    }
    return 0;
}
