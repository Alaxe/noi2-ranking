#include<iostream>
#include<stack>
using namespace std;
stack <int> s;
int x,a[160001],n=0;
int main()
{
    int i,h=0;short br=0;
    cin>>x;
    h=x;
    while(h!=0)
    {
        h=h/10;
        n++;
    }
    cout<<n<<endl; return 0;
    /*for(i=0;i<n;i++)
    {
        a[i]=x%10;
        x=x/10;
        s.push(a[i]);
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
    /*h=s.top();
    s.pop();
    br++;
    if(s.empty()==true)
    {
        cout<<br<<endl;
        return 0;
    }
    while(s.empty()==false)
    {
        h=h*2;
        while(h!=0)
        {
            s.pop();
            h=h/10;
        }
            br++;
    }*/



}
