//Task: odd
//Author: Emil Kelevedjiev
#include<iostream>
using namespace std;


int main()
{
    long long int a,b; cin >> a >> b;

    long long int v=1, c=0;
    while(v*v<a)v++;
    while(v*v<=b) {v++; c++;}

    cout << c << endl;
   
}
