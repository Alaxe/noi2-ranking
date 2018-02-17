#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<math.h>

using namespace std;

string sub2str(string a,string b)
{
    int umn = 0;
    string rez = "";
    if(a.size() < b.size())
    {
        while(a.size() != b.size())
        {
            a = '0' + a;
        }
    }
    if(b.size() < a.size())
    {
        while(b.size() != a.size())
        {
            b = '0' + b;
        }
    }
    for(int i = max(b.size() - 1,a.size() - 1);i >= 0;i--)
    {
        rez = char((int(a[i] - '0') + int(b[i] - '0') + umn) % 10 + '0') + rez;
        umn = (a[i] + b[i] - '0' - '0' + umn) / 10;
    }
    if(umn == 1)
    {
        rez = '1' + rez;
    }
    return rez;
}

string izv2(string a,long long b2)
{
    string b = "";
    do
    {
        b = char(b2 % 10 + '0') + b;
        b2 /= 10;
    }
    while(b2 != 0);
    int umn = 0;
    string rez = "";
    if(a.size() < b.size())
    {
        while(a.size() != b.size())
        {
            a = '0' + a;
        }
    }
    if(b.size() < a.size())
    {
        while(b.size() != a.size())
        {
            b = '0' + b;
        }
    }
    for(int i = max(b.size() - 1,a.size() - 1);i >= 0;i--)
    {
        if(a[i] - '0' - umn >= b[i] - '0')
        {
            a[i] = char(((a[i] - '0') - umn - (b[i] - '0')) + '0');
            umn = 0;
        }
        else
        {
            a[i] = char(((a[i] - '0' - umn + 10) - (b[i] - '0')) + '0');
            umn = 1;
            
        }
    }
    
    return a;
}

long long del(string a,string b2)
{
    long long b = 0,a2 = 0,indxf,bp;

    bool tf = false;
    for(int i = 0;i < b2.size();i++)
    {
        b = b * 10 + b2[i] - '0';
    }
    string rez = "";
    for(int i = 0;i < a.size();i++)
    {
        tf = true;
        a2 = 0;
        for(int j = i;j < a.size();j++)
        {
            a2 = a2 * 10 + a[j] - '0';
            if(a2 > b)
            {
                indxf = j;
                tf = false;
                break;
            }
        }
        if(tf)
        {
            return a2;
        }
        a2 %= b;
        for(int j = indxf;j >= 0;j--)
        {
            a[j] = a2 % 10 + '0';
            a2 /= 10;
        }
        
    }
}

int main()
{
    
    string a = "1";
    string b;
    long long n,ost = 0;
    cin>>n>>b;
    for(int i = 1;i < n;i++)
    {
        a = a + '0';
    }
    a = sub2str(a,b);
    ost = del(a,b); 
    if(ost == 0)
    {
        a = "1";
        for(int i = 1;i < n;i++)
        {
            a = a + '0';
        }
    }
    else
    {
        a = izv2(a,ost);
    }
    cout<<a<<endl;
    return 0;
}