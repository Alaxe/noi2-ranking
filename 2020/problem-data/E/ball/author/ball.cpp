//Task: ball
//Author: Zornica Dzhenkova
#include <iostream>
using namespace std;
int main()
{
    long long n,k;
    int x;
    cin>>n>>x;
    int r=n%6;
    switch(r)
    {
    case 0:if(x==0) k=0; else if(x==1) k=1; else if(x==2) k=2; break;
    case 1:if(x==0) k=1; else if(x==1) k=0; else if(x==2) k=2; break;
    case 2:if(x==0) k=1; else if(x==1) k=2; else if(x==2) k=0; break;
    case 3:if(x==0) k=2; else if(x==1) k=1; else if(x==2) k=0; break;
    case 4:if(x==0) k=2; else if(x==1) k=0; else if(x==2) k=1; break;
    case 5:if(x==0) k=0; else if(x==1) k=2; else if(x==2) k=1; break;
    }
    cout<<k<<endl;
}
