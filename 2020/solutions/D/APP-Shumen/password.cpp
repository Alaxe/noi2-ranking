#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int br=1,len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]==s[i-1])br++;
        else br=1;
        if(br==3)
        {
            br=1;
            if(s[i]=='a')s[i]='b';
            else s[i]='a';
        }
    }
    cout<<s<<endl;
    return 0;
}
