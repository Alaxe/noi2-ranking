#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int br=0;
    for(int i=a;i<=b;i++)
    {
        int del=0;
        for(int l=1;l<=i;l++)
       {
        if(i%l==0)del++;
       }
       if(del%2!=0)br++;
    }
    cout<<br<<endl;
}
