#include<iostream>
using namespace std;
string rot(string s)
{
    s = s.substr(1,s.size())+s.substr(0,1);
    return s;
}
long long to_int(string s)
{
    int curr=1;
    int otg =s[0]-'0';
    for(int i=1;i<s.size();i++)
    {
        otg*=10;
        otg+=s[i]-'0';
    }
    //cout<<otg<<endl;
    return otg;
}
string to_srt(long long a)
{
    string str="";
    while(a>0)
    {
        str+=(a%10+'0');
        a/=10;
    }
    for(int i=0;i<str.size()/2;i++)
    {
        swap(str[i], str[str.size()-i-1]);
    }
    return str;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
   /* //cout<<rot("123");
    cout<<to_int(rot("12")) - to_int("12")<<endl;
    cout<<to_int(rot("13")) - to_int("13")<<endl;
    cout<<to_int(rot("14")) - to_int("14")<<endl;
    cout<<to_int(rot("15")) - to_int("15")<<endl;
    cout<<to_int(rot("157")) - to_int("157")<<endl;
    cout<<to_int(rot("658")) - to_int("6358")<<endl;
    cout<<to_int(rot("659")) - to_int("659")<<endl;
    cout<<to_int(rot("660")) - to_int("660")<<endl;*/
    long long a;
    cin>>a;
    for(int i=0;i<4;i++)
    {
        cin>>a;
        if(a%9!=0)
            cout<<0<<endl;
        else
        {
            for(long long j=a; j>=0;j--)
            {
                if(to_int(rot(to_srt(j)))-j==a)
                {
                    cout<<j<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
