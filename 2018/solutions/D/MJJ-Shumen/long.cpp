#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main() {
    unsigned long long n,k,ob=0,ob1=0;
    cin>>n>>k;
    ob1=n*k;
    for(int i=1;i<=n-1;i++)
    {
    ob=ob1*(i*k);
    
    }
    if(ob%k==0)
        cout<<ob<<endl;
    return 0;
}
