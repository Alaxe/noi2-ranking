#include<iostream>
#include<stack>
using namespace std;
stack < int > st;
int main()
{
    unsigned long long s,t,a;
    int z,br=0,brW;
    cin>>s>>t>>z;
    for(unsigned long long i=s;i<=t;i++)
    {
        a=i;
        brW=0;
        while(a!=0)
        {
            if(a%2==0)brW++;
            a/=2;
        }
        if(z==brW)br++;
    }
    cout<<br<<endl;
    return 0;
}
