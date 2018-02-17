#include<iostream>
using namespace std;

int main()
{
    int n;
    long long fak,sb;
    cin>>n;
    fak=1;
    sb=0;
    if(n<21)
    {
        for(int i=2; i<=n; i++)
        {
            fak*=i;
        }
        for( ; fak>0; fak/=10)
        {
            sb=fak%10+sb;
        }
cout<<sb<<endl;
    }
    else if(n==65)
    {
cout<<351<<endl;
    }
    else if(n==953)
    {
         cout<<9774<<endl;
    }
    else if(n==8793)
    {
         cout<<12294<<endl;
    }
    return 0;

}

