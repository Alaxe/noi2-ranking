#include<iostream>
using namespace std;
int main()
{
    long long n,counter,otg=0;
    cin>>n;
    long long a[n],b[n];
    for(counter=0; counter<n; counter++)
    {
        cin>>a[counter]>>b[counter];
        if((a[counter]<=a[counter-1] && b[counter]<=b[counter-1])||(a[counter]<=b[counter-1] && b[counter]<=a[counter-1])){
        otg++;
        }
        }
        cout<<otg;
    return 0;
}
