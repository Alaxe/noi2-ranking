#include<iostream>
#include<string>
using namespace std;
string d23,d28,d33,dd;
int MESECI[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int dni[22000];
int toint(string a)
{
    int b=0,c;
    for(int i=0;i<a.size();i++)
    {
        c=int(a[i]-'0');
        b=b*10+c;
    }
    return b;
}
int From_jan1st(int a,int b)
{
    int c=0;
    for(int i=0;i<b-1;i++)
    {
        c+=MESECI[i];
    }
    c+=a;
    return c;
}
int F(string d)
{
    int a;
    int p,p1,p2;
    string s;
    p=d.find('/');
    s=d.substr(0,p);
    p1=toint(s);
    s=d.substr(p+1,d.size()-p-1);
    p2=toint(s);
    a=From_jan1st(p1,p2);
    return a;
}
void Read()
{
    cin>>d23>>d28>>d33>>dd;
}
void Solve()
{
    int a,b,c,d;
    a=F(d23);
    b=F(d28);
    c=F(d33);
    d=F(dd);
    a=a-d;
    b=b-d;
    c=c-d;
    for(int i=a%23;i<=22000;i+=23)
    {
        dni[i]++;
    }
    for(int i=b%28;i<=22000;i+=28)
    {
        dni[i]++;
    }
    for(int i=c%33;i<=22000;i+=33)
    {
        dni[i]++;
    }
    for(int i=1;i<=22000;i++)
    {
        if(dni[i]==3)  {cout<<i<<endl;break;}
    }

}
int main()
{
    Read();
    Solve();
    return 0;
}
