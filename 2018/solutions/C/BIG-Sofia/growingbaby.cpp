#include<iostream>
using namespace std;
long long m, n, p, q, pNap, izh, k;

void backtracking(int mass, bool c)
{
    if(mass>=n){
        izh++;
        izh=izh%k;
        return;
    }
    if(c){
        backtracking(mass+p, 0);
        return;
    }
    backtracking(mass+p, 0);
    backtracking(mass-q, 1);
}

int main(){
    k=1;
    for(int i=0;i<30;i++){
        k=k*2;
    }
    cin>>m>>n>>p>>q;
    backtracking(m+p, 0);
    cout<<izh%k<<endl;
return 0;
}

/**
4500 4560 20 7
*/
