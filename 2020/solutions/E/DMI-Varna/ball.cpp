#include<iostream>
using namespace std;
int main ()
{
    int n,x,a=0,b=1,c=2;
    cin >> n;
    cin >> x;
    int k=x;
    for(int br=n; br<=1; br--)
    {
        if(k==a && br%2==1)
            k=1;
        else if(k==b && br%2==1)
            k=0;
        else if(k==c && br%2==1)
            k=2;
        else if(k==a && br%2==0)
            k=0;
        else if(k==b && br%2==0)
            k=2;
        else if(k==c && br%2==0)
            k=1;
    }
    cout << k << endl;
    return 0;
}
