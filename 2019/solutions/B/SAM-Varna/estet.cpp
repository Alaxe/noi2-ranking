#include<iostream>
#include<stack>
using namespace std;
int a[100000],n;
int a1[100000];
int a2[100000];
stack<int> s;
stack<int> z;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        while(s.size()!=0)
        {
            if(s.top()<a[i]) break;
            s.pop();
        }
        s.push(a[i]);
        a1[i]=s.size();
    }
    for(int i=n-1;i>=0;i--)
    {
        while(z.size()!=0)
        {
            if(z.top()<a[i]) break;
            z.pop();
        }
        z.push(a[i]);
        a2[i]=z.size();
    }
    int ms=0;
    for(int i=0;i<n;i++)
    {
        ms=max((a1[i]+a2[i]),ms);
    }
    ms--;
    cout<<ms<<endl;
    return 0;
}
