#include<iostream>
#include<cmath>
using namespace std;
int check(int num, int step, int _max, int length){
    if(length == 0)return 1;
    int tmp=0;
    if(num-step>0){
        tmp+=check(num-step, step, _max, length-1);
    }
    if(num+step<_max){
        tmp+=check(num+step, step, _max, length-1);
    }
    return tmp;
}
int main(){
    int k,n,m;
    cin>>k>>m>>n;
    int result=0;
    for(int i=1;i<m;i++){
        result+=check(i, k, m, n-1);
    }
    cout<<result;
    return 0;
}
