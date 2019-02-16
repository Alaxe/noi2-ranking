#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

const int MAX_N = 200000;
int Inf = 200001;
vector<vector<int> > v;
int A1, B1;
int n;

int A[MAX_N]; /// ot A do vseki
int B[MAX_N]; /// ot B do vseki

void dijkstraA(int from){
    for(int i = 0; i < v[from-1].size(); i++){
        if(A[v[from-1][i]-1] > (A[from-1] + 1))
        {
            A[v[from-1][i]-1] = A[from-1] + 1;
            dijkstraA(v[from-1][i]);
        }
    }
}

void dijkstraB(int from){
    for(int i = 0; i < v[from-1].size(); i++){
        if(B[v[from-1][i]-1] > (B[from-1] + 1))
        {
            B[v[from-1][i]-1] = B[from-1] + 1;
            dijkstraB(v[from-1][i]);
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;

    if(n < 4) {cout << 0; return 0;}

    v.resize(n);

    for(int i = 0; i < n-1; i++){
        int from, to;
        cin >> from >> to;

        v[from-1].push_back(to);
        v[to-1].push_back(from);
    }

    cin >> A1 >> B1;

    int br = 0;

    for(int i = 0; i < v[A1-1].size(); i++){
        for(int k = 0; k < v[B1-1].size(); k++){
            if(v[A1-1][i] == v[B1-1][k]) br++;
        }
    }
    if(br == v[A1-1].size() && br == v[B1-1].size()){
        cout << 0;
        return 0;
    }

    for(int i = 0; i < n; i++) A[i] = Inf;
    for(int i = 0; i < n; i++) B[i] = Inf;

    A[A1-1] = 0;
    A[B1-1] = 0;
    dijkstraA(A1);
    B[A1-1] = 0;
    B[B1-1] = 0;
    dijkstraB(B1);


    sort(A, A+n);
    sort(B, B+n);

    for(int i = n-1; i >= 0; i--){
        for(int k = n-1; k >= 0; k--){
            if(A[i] == B[k] && A[i] != 0 && A[i] != 200001) {cout << A[i]+1; return 0;}
        }
    }
}
