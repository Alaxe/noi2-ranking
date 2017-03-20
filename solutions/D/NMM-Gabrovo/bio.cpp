#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int months[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string d[4];

int n[4];

int tn(string s)
{
    int r=0;

    if(s[1]=='/')
    {
        r+=(s[0]-'0');
        s.erase(0, 2);
    }
    else
    {
        r+=(s[0]-'0')*10+(s[1]-'0');
        s.erase(0, 3);
    }

    int m;

    if(s.size()==1)
    {
        m=(s[0]-'0');
    }
    else
    {
        m=(s[0]-'0')*10+(s[1]-'0');
    }

    for(int i=0;i<m-1;i++)
    {
        r+=months[i];
    }

    return r;
}

int o[3];

int main()
{
    cin>>d[0]>>d[1]>>d[2]>>d[3];

    for(int i=0;i<4;i++)
    {
        n[i]=tn(d[i]);
        //cout<<n[i]<<endl;
    }

    o[0]=n[0]%23;
    o[1]=n[1]%28;
    o[2]=n[2]%33;

    long long ns=n[0]+1;

    while(!((ns-o[0])%23==0 && (ns-o[1])%28==0 && (ns-o[2])%33==0))
    {
        ns++;
    }

    if(n[3]<ns)
        cout<<ns-n[3]<<endl;
    else
    {
        while(n[3]<ns)
        {
            ns+=21252;
        }
        cout<<ns-n[3]<<endl;
    }

    return 0;
}
