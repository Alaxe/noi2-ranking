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


    int n;
    cin >> n;

    if(n < 24){
    ull sum = 0;
    ull fact = 1;
    for(int j = 2; j <= n; j++)
    {
    fact = fact * j;
    ull fact1 = fact;
    while(fact % 10 == 0){
        fact = fact / 10;
    }
    }
    while(fact > 1){
        sum = sum + fact%10;
        fact = fact / 10;
    }
    cout << sum << endl;
    return 0;
    }


/*

    ull sum = 0;
    ull sumfac, fact1 = 1, fact2 = 1, fact = 1;

    for(int j = 2; j < 24; j++)
    {
    fact = fact * j;

    while(fact % 10 == 0){
        fact = fact / 10;
    }
    }

    fact1 = fact / 10000000000;
    fact2 = fact % 10000000000;

    for(int i = 24; i <= n; i++){
        fact1 = fact1 * 24;
        fact2 = fact2 * 24;
        if()
        while(fact > 1){
            sum = sum + fact % 10;
            fact = fact / 10;
        }
    }*/

    return 0;
}
/*
ull fact = 1;
    for(int n = 1; n <= 23; n++)
    {
    ull sum = 0;
    fact = fact * n;
    int br = 0;
    ull fact1 = fact;
    while(fact1 > 1){
        sum = sum + fact1%10;
        fact1 = fact1 / 10;
        br++;
    }
    cout << n << " " << fact << " " << sum << endl;

    }
*/
// do 22 raboti
