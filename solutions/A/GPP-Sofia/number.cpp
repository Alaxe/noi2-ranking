#include<iostream>
using namespace std;


int main()
{
    long long broi=0;
    long long m,n;
    cin>>m>>n;

    for(long long i=m/2;i*(i+1)<=n;i++)
    {

        if(i*(i+1)>=m && i*(i+1)<=n)
        {
            broi++;
        }
    }

    cout<<broi;
}
