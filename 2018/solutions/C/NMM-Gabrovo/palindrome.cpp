#include<iostream>
#include<string>
using namespace std;

bool check(string a)
{
    int p1, p2, l=a.length();

    if(l%2==0)
    {
        p1=l/2-1;
        p2=l/2;
    }
    else
    {
        p1=l/2-1;
        p2=l/2+1;
    }

    bool r=true;

    for(int i=p1;i>=0;i--)
    {
        if(a[i]!=a[p2])
        {
            r=false; break;
        }

        p2++;
    }

    return r;
}

int main()
{
    string n;
    cin>>n;

    bool y=false;

    while(!y)
    {
        int p=n.length()-1;

        while(n[p]=='9' && p>=0)
        {
            n[p]='0';
            p--;
        }

        if(p==0)
        {
            n='1'+n;
        }
        else n[p]++;

        if(check(n))
        {
            cout<<n<<endl;
            return 0;
        }
    }

    return 0;
}
