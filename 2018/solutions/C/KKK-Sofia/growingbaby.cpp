#include<iostream>
#define MOD 1<<30
unsigned long long n,m,p,q;
unsigned long long ways[10000];
unsigned long long calc(unsigned long long current){
    if(current>=n){
        return 1;
    }
    if(ways[current]>0){
        return ways[current];
    }
    unsigned long long cWays=0;
    if(current+p<n){
        cWays+=calc(current+p-q);
    }
    cWays+=calc(current+p);
    cWays%=MOD;
    ways[current]=cWays;
    return cWays;
}
int main(){
    //std::cout<<(1<<30);
    std::cin>>m>>n>>p>>q;
    std::cout<<calc(m)<<std::endl;
    return 0;
}
