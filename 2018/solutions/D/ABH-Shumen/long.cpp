#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int x=n.size();
    while(x%k==0)
    {
        int del=x/k;
        cout<<del<<endl;
    }

return 0;
}
