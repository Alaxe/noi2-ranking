#include<iostream>
using namespace std;
unsigned short int a[100000];
long long int br = 0;
int main()
{
    //23 procenta sa si 23 procenta, kot takoa
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < n-1; i++)
        if(a[i] > a[i+1])
        {
            cout<<a[i]-a[i+1]<<endl;
            return 0;
        }
    cout<<0<<endl;
    return 0;
}
