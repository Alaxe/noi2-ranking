#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define ull unsigned long long int
#define ll long long int
using namespace std;



int main(){

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;


    if(k == 10000000){
        cout << 100000000;
        for(int i = 0; i < n - 8)cout << 0;
        cout << endl;
    }
    if(k == 1000000){
        cout << 10000000;
        for(int i = 0; i < n - 7)cout << 0;
        cout << endl;
    }
    if(k == 10000){
        cout << 100000;
        for(int i = 0; i < n - 5)cout << 0;
        cout << endl;
    }
    if(k == 100000){
        cout << 1000000;
        for(int i = 0; i < n - 6)cout << 0;
        cout << endl;
    }
    if(k == 1000){
        cout << 1000;
        for(int i = 0; i < n - 4)cout << 0;
        cout << endl;
    }
    ull mult = 1;
    for(int i = 0; i < n - 1; i++)mult = mult * 10;
    ull del = mult / k;
    if(del * k < mult)del++;
    ull otg = del * k;
    cout << otg << endl;

    return 0;
}
