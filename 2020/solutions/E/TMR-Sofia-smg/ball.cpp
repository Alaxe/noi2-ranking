#include <iostream>
using namespace std;

int main(){

int n,x,i,a,b,c,ball;
a=0;
b=1;
c=2;
ball=0;
cin >> n >> x;
for (i=1;i<=n;i++){
    if (i%2!=0){
        a++;
        b--;
        ball++;
    }
    else if (i%2==0){
        b++;
        c--;
        ball--;
    }
}
//cout << a << endl << b << endl << c;
cout << b;
}
