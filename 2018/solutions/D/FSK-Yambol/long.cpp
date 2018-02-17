#include <iostream>
using namespace std;
int main()
{
    int n,k,i,o=0;
    cin>>n>>k;
    long long a=1;
    for(i=1;i<n;i++)
    {
        a=a*10;
    }
    for(i=1;o==0;i++)
    {
        if(a%k==0)
        {
            o=1;
            break;
        }
        a++;
    }
    cout<<a<<endl;
}
