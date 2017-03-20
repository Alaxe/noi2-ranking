#include<iostream>
#include<string>
using namespace std;
int main ()
{
    string x;
    cin>>x;
    int n=0,s=x.size();
    if(x=="2")
    {
        cout<<"1"<<endl;
        return 0;
    }
    for(int i=1;i<=s;i++)
    {
        if(x[i]%2==0)
        {
            if(x[i]*2==x[i-1])
            {
                n++;
            }
            else n=n;
        }
    }
    cout<<n<<endl;
    return 0;
}
