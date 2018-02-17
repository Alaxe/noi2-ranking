#include <iostream>
using namespace std;

int main()
{
    int n;
    long long k=1,r=0;

    cin>>n;

    for(int i=1; i<=n; i++){
        k*=i;
    }

    while(k>0){
        r+=k%10;
        k/=10;

    }

    cout<<r<<endl;

    return 0;
}
