#include <iostream>
using namespace std;
long long triangleline(int line,int col){
    long long res;
    if(line==0 or line==1 or col==line or col==1){
        return 1;
    }
    res=triangleline(line-1,col)+triangleline(line,col-1);
    return res;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<triangleline(n,k)<<endl;
    return 0;
}
