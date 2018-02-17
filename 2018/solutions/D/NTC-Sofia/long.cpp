#include<iostream>
using namespace std;

int main()
{
    int n;
    int k;
    int a=0;
    int br=1;
    int b=1;
    cin>>n>>k;
    while(br!=n)
    {
        a=k*b;
        while(a>9)
        {
            a=a/10;
            br++;
        }
    if ( br==n){
        a=k*b;
        cout<<a;
    }
    else{
        br=1;
        b++;
    }
    }
}

