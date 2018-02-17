#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int a,b=0,br=0;
    cin>>a;
    for(;a>b;br++){
    b=b*pow(10,(br/3)+1)+pow(2,br);
    }
    cout<<br-1;
    return 0;
}
