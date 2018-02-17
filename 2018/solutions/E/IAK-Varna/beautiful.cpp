#include <iostream>
using namespace std;
int main()
{
    int n,k,brc=0;
    long long a;
    cin>>n>>k;
    if(k>0 && n>0)
    {
        while(n>0)
        {
            n--;
            brc++;
        }

        cout<<a<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}

