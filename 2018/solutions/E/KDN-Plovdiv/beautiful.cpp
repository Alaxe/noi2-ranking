#include<iostream>
using namespace std;
int main()
{
    long long n,k,o,br=0;
    cin>>n>>k;
    if(n==1)
    {
        for(o=1;o<=9;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==2)
    {
        for(o=10;o<=99;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==3)
    {
        for(o=100;o<=999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==4)
    {
        for(o=1000;o<=9999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==5)
    {
        for(o=10000;o<=99999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==6)
    {
        for(o=100000;o<=999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==7)
    {
        for(o=1000000;o<=9999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==8)
    {
        for(o=10000000;o<=99999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==9)
    {
        for(o=100000000;o<=999999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==10)
    {
        for(o=1000000000;o<=9999999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==11)
    {
        for(o=10000000000;o<=99999999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==12)
    {
        for(o=100000000000;o<=999999999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==13)
    {
        for(o=1000000000000;o<=9999999999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==14)
    {
        for(o=10000000000000;o<=99999999999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==15)
    {
        for(o=100000000000000;o<=999999999999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==16)
    {
        for(o=1000000000000000;o<=9999999999999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==17)
    {
        for(o=10000000000000000;o<=99999999999999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            break;}
            if(o%k==0) br++;
        }
    }
    if(n==18)
    {
        for(o=100000000000000000;o<=999999999999999999;o++)
        {
            if(o%k==0){ cout<<o<<endl;
            continue;}
            if(o%k==0) br++;
        }
    }
    if(n==1&&k>9)cout<<"NO"<<endl;
    if(n==2&&k>99)cout<<"NO"<<endl;
    if(n==3&&k>999)cout<<"NO"<<endl;
    if(n==4&&k>9999)cout<<"NO"<<endl;
    if(n==5&&k>99999)cout<<"NO"<<endl;
    if(n==6&&k>999999)cout<<"NO"<<endl;
    if(n==7&&k>9999999)cout<<"NO"<<endl;
    if(n==8&&k>99999999)cout<<"NO"<<endl;
    if(n==9&&k>999999999)cout<<"NO"<<endl;
    if(n==10&&k>9999999999)cout<<"NO"<<endl;
    if(n==11&&k>99999999999)cout<<"NO"<<endl;
    if(n==12&&k>999999999999)cout<<"NO"<<endl;
    if(n==13&&k>9999999999999)cout<<"NO"<<endl;
    if(n==14&&k>99999999999999)cout<<"NO"<<endl;
    if(n==15&&k>999999999999999)cout<<"NO"<<endl;
    if(n==16&&k>9999999999999999)cout<<"NO"<<endl;
    if(n==17&&k>99999999999999999)cout<<"NO"<<endl;
    if(n==18&&k>999999999999999999)cout<<"NO"<<endl;
    return 0;
}

