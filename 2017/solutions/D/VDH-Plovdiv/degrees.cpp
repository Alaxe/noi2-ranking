#include <iostream>
#include <string>
using namespace std;
string step(string s)
{
    string s1;
    int c=0, c1=0, r=0;
    for (int i=s.size()-1; i>=0; i--)
    {
        c=s[i]-48;
        c1=(c*2)+r;
        if (c1>9)
        {
            r=c1/10;
            c1=c1%10;
        }
        else r=0;
        //cout<<r<<endl;
        char c2=c1+48;
        s1=c2+s1;
    }
    if (r>0) s1=char(r+48)+s1;
    return s1;
}
int main()
{
     string s;
     cin>>s;
     //cout<<step(s)<<endl;
     int br=1, otg=1;
     string s1="2";
     while(s.size()>br)
     {
         string s2=step(s1);
         br+=s2.size();
        // cout<<s2<<" "<<br<<"\n";
         s1=s2;
         otg++;
     }
     cout<<otg<<endl;
}
