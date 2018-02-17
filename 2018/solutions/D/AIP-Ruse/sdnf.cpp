#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<math.h>

using namespace std;

string izv1(string a)
{
    bool tf = false;
    if(a[a.size() - 1] == '0')
    {
        for(int i = a.size() - 1;i >= 0;i--)
        {
            if(a[i] != '0')
            {
                a[i] = a[i] - 1;
                tf = true;
                break;
            }
            else
            {
                a[i] = '9';
            }
        }
    }
    else
    {
        a[a.size() - 1] = a[a.size() - 1] - 1;
        tf = true;
    }
    if(tf == false)
    {
        a = "yes";
    }
    return a;
}

string adder(string a)
{
    bool tf = false;
    if(a[a.size() - 1] == '9')
    {
        for(int i = a.size() - 1;i >= 0;i--)
        {
            if(a[i] != '9')
            {
                a[i] = a[i] + 1;
                tf = true;
                break;
            }
            else
            {
                a[i] = '0';
            }
        }
    }
    else
    {
        a[a.size() - 1] = a[a.size() - 1] + 1;
        tf = true;
    }
    if(tf == false)
    {
        a = '1' + a;
    }
    return a;
}


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

string umndoseg(string a,string b)
{
    string rez = "0";
    b = izv1(b);
    while(b != "yes")
    {
        rez = sub2str(rez,a);
        b = izv1(b);
    }
    
    return rez;
}

int main()
{
    int n,sb = 0;
    string rez = "1";
    string mqsto = "2";
    cin>>n;
    for(int i = 1;i < n;i++)
    {
        rez = umndoseg(rez,mqsto);
        if(i != n - 1)
        {
            mqsto = adder(mqsto);
        }
    }
    
    for(int i = 0;i < rez.size();i++)
    {
        sb += rez[i] - '0';
    }
    cout<<sb<<endl;
    return 0;
}