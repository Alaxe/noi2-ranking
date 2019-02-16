#include<iostream>
using namespace std;
int main(){
long long a, b, broi = 0, odd = 0;
cin >> a >> b;

for(long long i = a; i <= b; i++){
    broi = 0;
    for(long long deliteli = 1; deliteli <= i; deliteli++){
        if(i % deliteli == 0){
            broi++;
        }
    }
    if(broi % 2 == 1){
        odd++;
    }
}

cout << odd;

return 0;
}
