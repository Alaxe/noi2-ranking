#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

const int MAX_N = 100000;
bool A[MAX_N+1];
bool B[MAX_N+1];
int C[MAX_N+1];
int maxA = 0;
int n;
int indexNaZapochvane = 0;

int Rastqshta(bool b)
{
    int krai =  n;
    int br = 1;
    if(b){
        krai = indexNaZapochvane;
    }

    int prev = C[0];
    A[0] = true;

    for(int i = 1; i <= krai; i++){
        if(C[i] > prev) {
            A[i] = true;
            prev = C[i];
            br++;
        }
        else A[i] = false;
    }

    return br;
}

int Namalqvashta(bool b){
    int nachalo = 1;
    int br = 1;
    if(b){
        br = 0;
        nachalo = indexNaZapochvane+1;
    }

    int prev = C[nachalo-1];
    B[nachalo-1] = true;

    for(int i = nachalo; i < n; i++){
        if(C[i] < prev){
            B[i] = true;
            prev = C[i];
            br++;
        }
        else B[i] = false;
    }

    return br;
}

int treti(){

    int br1 = Rastqshta(true);
    int br2 = Namalqvashta(true);

    return br1 + br2;
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        C[i] = a;

        if(a > maxA) maxA = a;

        if(a > C[indexNaZapochvane]) indexNaZapochvane = i;
    }

    int br = treti();

    cout << br;
}
