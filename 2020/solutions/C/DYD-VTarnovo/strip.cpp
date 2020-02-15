#include<iostream>
using namespace std;
int n, k;
int a[1000];
int visited[100];
int broi = 0;
int k1;
int dyljina;
int ans = 0;
int broiSreshtaniq[1000];
string converted;
bool validnoLiE(){
    if(a[k1] != 1) {return false;}
    for(int i = 0;i < k;++i){
        broiSreshtaniq[a[i]] = 0;
    }
    for(int i = 0;i < k;++i){
        broiSreshtaniq[a[i]]++;
        if(broiSreshtaniq[a[i]] > 1){
            return false;
        }
    }
     bool found = false;
    int i = k1;
    int posoka = 0;
    int broiStypki = 0;

    return true;
}
void print(){
    for(int i = 0;i < k;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void varGen(int p){
    if(p == k){
        //print();
        if(validnoLiE()){ans++;}
        return;
    }
    for(int i = 1;i <= n;++i){
        if(visited[i] == 0){
            visited[i] = 1;
            a[p] = i;
            varGen(p+1);
        }
        visited[i] = 0;
    }
}
int main(){
    cin>>dyljina;
    cin>>k1;
    k = dyljina;
    n = k;
    k1--;
    varGen(0);
    cout<<ans-3<<endl;
    return 0;
}
