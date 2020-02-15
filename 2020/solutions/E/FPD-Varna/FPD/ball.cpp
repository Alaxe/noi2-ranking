#include<iostream>
using namespace std;
int main()
{
    long long pos;
    long long n;
    cin>>n;
    n%=6;
    cin>>pos;
    if(n==0)
    {
        if(pos==0)
            cout << 0 << endl;
        if(pos==1)
            cout << 1 << endl;
        if(pos==2)
            cout << 2 << endl;
    }
    if(n==1)
    {
        if(pos==0)
            cout << 1 << endl;
        if(pos==1)
            cout << 0 << endl;
        if(pos==2)
            cout << 2 << endl;
    }
    if(n==2)
    {
        if(pos==0)
            cout << 1 << endl;
        if(pos==1)
            cout << 2 << endl;
        if(pos==2)
            cout << 0 << endl;
    }
    if(n==3)
    {
        if(pos==0)
            cout << 2 << endl;
        if(pos==1)
            cout << 1 << endl;
        if(pos==2)
            cout << 0 << endl;
    }
    if(n==4)
    {
        if(pos==0)
            cout << 2 << endl;
        if(pos==1)
            cout << 0 << endl;
        if(pos==2)
            cout << 1 << endl;
    }
    if(n==5)
    {
        if(pos==0)
            cout << 0 << endl;
        if(pos==1)
            cout << 2 << endl;
        if(pos==2)
            cout << 1 << endl;
    }
    return 0;
}
