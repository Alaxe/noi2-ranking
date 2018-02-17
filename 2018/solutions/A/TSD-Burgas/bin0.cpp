#include<iostream>
using namespace std;
long int s,t,zap;
int z,br,brvs=0;
int main()
{   int i;
    cin>>s>>t>>z;
    for(i=s;i<=t;i++)
    {   zap=i;br=0;
        while(zap)
        {   if(zap%2==0)br++;
            zap/=2;
            if(br>z){break;}
        }
        if(br==z)brvs++;
    }
    cout<<brvs<<endl;
    return 0;
}
