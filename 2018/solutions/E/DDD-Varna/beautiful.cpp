#include<iostream>
using namespace std;
int main()
{
    int n,k;
    long long a=1;
    cin>>n>>k;
    if(n==1)
    {
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<10)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }
    }
    else if(n==2)
    {
        a=10;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<100)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }
    }
    else if(n==3)
    {
        a=100;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<1000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    else if(n==4)
    {
        a=1000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<10000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }
            a++;
        }

    }
    else if(n==5)
    {
        a=10000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<100000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }
            a++;
        }

    }
    else if(n==6)
    {
        a=100000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<1000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }
            a++;
        }

    }
    else if(n==7)
    {
        a=1000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<10000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }
            a++;
        }

    }
    else if(n==8)
    {
        a=10000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<100000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    else if(n==9)
    {
        a=100000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<1000000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    else if(n==10)
    {
        a=1000000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<10000000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    else if(n==11)
    {
        a=10000000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<100000000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    else if(n==12)
    {
        a=100000000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<1000000000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    else if(n==13)
    {
        a=1000000000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<10000000000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    else if(n==14)
    {
        a=10000000000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<100000000000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    else if(n==15)
    {
        a=100000000000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<1000000000000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    else if(n==16)
    {
        a=1000000000000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<10000000000000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }
    }
    else if(n==17)
    {
        a=1000000000000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<100000000000000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    else if(n=18)
    {
        a=10000000000000000;
        if(k>=10*a) cout<<"NO"<<endl;
        while(a<1000000000000000000)
        {
            if(a%k==0)
            {
                cout<<a<<endl;
                break;
            }

            a++;
        }

    }
    return 0;
}
