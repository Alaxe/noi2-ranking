#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	long long int n;
	int x;
	cin>>n>>x;
	if(n==1)
    {
        if(x==0)
        {
            cout<<1<<endl;
        }
        else if(x==2)
        {
            cout<<2<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
        return 0;
    }
    if(n==2)
    {
        if(x==1)
        {
            cout<<2<<endl;
        }
        else if(x==2)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
        return 0;
    }
	int y,z;
	if(x==0)
    {
        y=1; z=2;
    }
    else if(x==1)
    {
        y=0; z=2;
    }
    else
    {
        y=0; z=1;
    }
    while(n!=0)
    {
        if(n%2==0)
        {
            if(x<y)
            {
                swap(y,z);
            }
            else
            {
                swap(x,z);
            }
        }
        else
        {
            if(y>x)
            {
                swap(x,y);
            }
            else
            {
                swap(z,y);
            }
        }
        n--;
    }
    cout<<x<<endl;
	return 0;
}
