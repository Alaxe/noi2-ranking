#include<iostream>
using namespace std;
int main (){
long long i,j,y,s,N,a[100000],b[100000],redichka[50000];
cin>>N;
for(i=0;i<N;i++){
    cin>>a[i]>>b[i];
    redichka[i]=0;
}
for(j=1;j<=N;j++){
    if(b[j-1]>=a[j] && a[j-1]>=b[j] || b[j-1]>=b[j] && a[j-1]>=a[j]){
        redichka[j]++;
    }
}
for(y=0;y<=50000;y++){
    for(s=1;s<=50000;s++){
        if(redichka[y]<redichka[s]){
            swap(redichka[y],redichka[s]);
        }
    }
}
cout<<redichka[0];
return 0;
}
