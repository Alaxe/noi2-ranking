#include<iostream>
#include<string>
using namespace std;
string s, temp="2";
int len=1, l, i=0;
string pro(string k)
{
    int dig, pr=0, size=k.size();
    string result="";
    for(int i=size-1;i>=0;i--)
    {
        dig=((k[i]-'0')*2)%10;
        pr=((k[i]-'0')*2)/10;
        result=(char)(dig+'0')+result;
    }
    while(pr)
    {
        dig=pr%10;
        result=(char)(dig+'0')+result;
        pr/=10;
    }
    return result;
}
int main()
{
    cin>>s;
    l=s.size();
    while(len<=l)
    {
        temp=pro(temp);
        len+=temp.size();
        i++;
    }
    cout<<i<<endl;
    return 0;
}
