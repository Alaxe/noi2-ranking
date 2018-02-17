#include<iostream>
#include<string>
using namespace std;

bool pal(long long n)
{
    string a = "",b = "";
    while(n != 0)
    {
        a = a + char((n % 10) + '0');
        b = char((n % 10) + '0') + b;
        n /= 10;
    }
    //cout<<a<<" "<<b<<endl;
    if(a == b)
    {
        //cout<<"yes"<<endl;
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    long long n,res = 0,um = 0,in1 = 0,in2 = 0;
    cin>>n;
    bool tf = false;
    for(long long i = n;i > 0;i--)
    {
        for(long long k = i;k > 0;k--)
        {
            um = i * k;
            //<<i<<" "<<k<<endl;
            if(pal(um) == true)
            {
                //cout<<"yes"<<endl;
                in1 = k;
                res = um;
                in2 = i;
                tf = true;
                break;
            }
        }
        if(tf == true)
        {
            break;
        }
    }
    if(in1 > in2) swap(in1,in2);
    cout<<in1<<" "<<in2<<endl<<res<<endl;
    return 0;
}