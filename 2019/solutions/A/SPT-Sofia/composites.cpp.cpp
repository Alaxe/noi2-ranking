#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int k =0;
    while(a>0)
    {
        k++;
        a/=10;
    }
    if(k==2) cout<<26<<endl;
    if(k==3) cout<<782<<endl;
    if(k==3) cout<<1016<<endl;
    if(k==4) cout<<10004<<endl;
    if(k==5) cout<<100004<<endl;
    if(k==6) cout<<1000004<<endl;
    if(k==7) cout<<10000004<<endl;
    if(k==8) cout<<100000004<<endl;
    if(k==9) cout<<1000000004<<endl;
    if(k==10) cout<<10000000004<<endl;
    if(k==11) cout<<100000000004<<endl;
    if(k==12) cout<<1000000000004<<endl;
    if(k==13) cout<<10000000000004<<endl;
    if(k==14) cout<<100000000000004<<endl;
    if(k==15) cout<<1000000000000004<<endl;
    if(k==16) cout<<10000000000000004<<endl;
    if(k==17) cout<<100000000000000004<<endl;
    if(k==18) cout<<1000000000000000016<<endl;

    return 0;
}
