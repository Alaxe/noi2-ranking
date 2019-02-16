#include<iostream>
using namespace std;
long long sborotcifri(long long i){
    long long bs=0,ic=i;
    while(i>=1){
        bs+=i%10;
        i=i/10;
    }
    return bs+ic;
}
int main(){
    int n,m,br=0;
    cin>>n>>m;
    int i=n;
    for(i;i<=m;i=sborotcifri(i))br++;
    cout<<br<<endl;
    return 0;
}
