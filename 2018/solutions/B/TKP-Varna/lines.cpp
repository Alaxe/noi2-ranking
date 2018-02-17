#include <iostream>
using namespace std;

int d(int ax, int ay)
{
    int det;
    int dxa = ax;
    int dxb = ax;
    int dya = ay;
    int dyb = 0;
    det = dxa*dyb - dxb*dya;
    return det;
}

int main()
{
    int n;
    cin >>n;
    int coord[1002][2];

    for(int i = 0; i < n; i++)
        cin >>coord[i][0] >>coord[i][1];


    cout<<"Determinanti: "<<endl;
    for(int i = 0; i < n; i++)
        cout<<i<<" "<<d(coord[i][0], coord[i][1])<<endl;
}

/**

input:
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
output:
4

*/
