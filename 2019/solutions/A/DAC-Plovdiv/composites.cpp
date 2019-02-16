#include <iostream>
using namespace std;

long long n, a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    if(n - 26 < 0) a = 0;
    else {
        a = (n - 26) / 30;

        if((n - 26) % 30 != 0)
            a++;
    }

    cout<<a * 30 + 26<<endl;

    return 0;
}
