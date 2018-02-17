#include <iostream>
using namespace std;
int main (){
long long flowers,water,sum=0,a,b;
cin >> flowers;
long long high[flowers];
for (int i = 0 ; i < flowers; i++){
cin >> high[i];
}
cin >> water;
for (int i = 0 ; i < flowers; i++){
    for(int j = 0 ; j< flowers; j++){
        if (high[j] > high[i]){
            a =high[i];
            high[i]= high[j];
            high[j]=a;
        }
    }
}
for (int i = 0; i<flowers;i++){
    b=high[flowers-1]-high[i];
    sum = sum + b;
}
cout << sum *water;
return 0;
}

