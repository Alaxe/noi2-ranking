#include <iostream>
using namespace std;
string pr2(string x)
{
    string a;
    int sz=x.size(),i,prenos=false;
    for (i=sz-1;i>=0;i--)
    {
        int tnum=prenos+x[i]+x[i]-'0';
        if (tnum>'9')
        {
            tnum-=10;
            prenos=true;
        }
        else prenos=false;
        //cout<<char(tnum)<<"Tnum"<<endl;
        a=char(tnum)+a;
    }
    if (prenos)a="1"+a;
    return a;
}
int main()
{
    string n;
    cin>>n;
    int sz=n.size(),i=0;
    string x="2";
    int cnt=0;
    while (i<sz)
    {
        i+=x.size();
        x=pr2(x);
        cnt++;
    }
    cout<<cnt<<endl;
return 0;
}
