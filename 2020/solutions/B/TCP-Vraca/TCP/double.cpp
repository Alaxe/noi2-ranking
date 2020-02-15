#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int w1, w2, n;

    cin >> n >> w1 >> w2;

    int a[n];
    int weight11 = 0, weight12 = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if (weight11 + a[i] <= w1) weight11 += a[i];
        else if(weight12 + a[i] <= w2) weight12 += a[i];
    }

    int weight21 = 0, weight22 = 0;

    for(int i = n - 1; i >= 0; i--){
        if (weight21 + a[i] <= w1) weight21 += a[i];
        else if(weight22 + a[i] <= w2) weight22 += a[i];
    }

    if(weight11 + weight12 > weight21 + weight22) cout << weight11 + weight12;
    else cout << weight21 + weight22;


    return 0;
}
