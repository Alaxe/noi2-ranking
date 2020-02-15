#include<iostream>
using namespace std;
int main()
{
    unsigned long long n,x,a=0,b=0,c=0,d=0;
    cin >> n >> x;
    if(x==0)a=10;
    else if(x==1)b=10;
    else c=10;
    for (int i=1;i<=n;n--)
    {
        if(n%2){d=a;a=b;b=d;}
        else {d=b;b=c;c=d;}
    }
    if (a==10) cout << "0" << endl;
    else if (b==10) cout << "1" << endl;
    else cout << "2" << endl;
}
