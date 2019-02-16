//Task: odd
//Author: Emil Kelevedjiev
#include<iostream>
using namespace std;

int main()
{
    long long int a,b; cin >> a >> b;
    long long int r=0;

    for(int i=a;i<=b;i++)
    {
     long long int c=0;
     for(int k=1;k<=i;k++)
        if(i%k==0) c++;

     if(c%2==1) r++;
    }

    cout << r << endl;
}
