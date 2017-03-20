#include<iostream>
using namespace std;
int main ()
{
    string t;
    int i=1,a;
    cin>>t;
    a=t.size();
    if(a<=3)cout<<a<<endl;
    else
    {
        while (a/i>=3)
        {
            a-=i*3;
            i++;
        }
        i--;
        a+=i*3;
        if(a==0)cout<<i*3<<endl;
        else cout<<i*2+a/3<<endl;
    }
}
