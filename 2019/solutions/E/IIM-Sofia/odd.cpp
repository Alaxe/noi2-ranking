#include<iostream>
using namespace std;
int main ()
{
    long long a,b,i,brdeliteli,brchislasnechetenbrdeliteli=0;
    cin>>a>>b;
    for(i=a; i<b; i++)
    {
        if(i%a==0)
        {
            brdeliteli++;
        }
        if(brdeliteli%2!=0)
        {
            brchislasnechetenbrdeliteli++;
        }
    }
    cout<<brchislasnechetenbrdeliteli/2<<endl;
    return 0;
}
