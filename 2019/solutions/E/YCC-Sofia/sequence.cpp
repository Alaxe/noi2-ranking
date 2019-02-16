#include<iostream>
using namespace std;
int main()
{
    long long n,i,br=0;
    cin>>n;
    long long redica[n],redica1[n];
    redica[n]=1;
    while(1)
    {
        if(redica[i]==n)
        {
            br++;
            break;
        }
        else
        {
            br++;
        }
    }
    cout<<br<<endl;
    return 0;
}
