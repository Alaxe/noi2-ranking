#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

const int MAX_N = 5000;
vector<vector<int> > A;
int n, k;
bool sochesthi[MAX_N];


int main(){


    ios::sync_with_stdio(0);
    cin.tie(0);

    int brsocheshti = 0;
    int brBoth = 0;
    //int n, k;
    cin >> n >> k;
    int socheshti[MAX_N] = {false};
    A.resize(n);

    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        if(b > 0) brsocheshti++;
        for(int k = 0; k < b; k++){
            int j;
            cin >> j;
            A[j-1].push_back(i+1);
            socheshti[i] = true;
        }
    }


    int brNesocheshti = 0;
    for(int i = 0; i < n; i++){
        if(A[i].size() != 0 && socheshti[i]){
          brBoth++;


        }
        if(!A[i].size()) brNesocheshti++;
    }

    int rez = brBoth;
    if(brNesocheshti > 0){
        rez += 1;
    }
    if(n - brsocheshti > 0){
     rez += 1;
    }
    cout << pow(2,rez-1) * k;

}
