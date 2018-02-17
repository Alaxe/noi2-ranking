#include <iostream>
using namespace std;
int f(int a, int b=1) {
    for (int x=1;x<=a;x++) {
      b=b*x;
    }
    return b;
}
int main () {
long long n,x,ch=1,s=0;
cin >> n;
ch=f(n);
while (ch!=0) {
    s=s+ch%10;
    ch=ch/10;
}

cout << s<<endl;
return 0;
}
