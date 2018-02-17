#include <iostream>
#include <cmath>
using namespace std;
string s;int res=0;
int y;
int check(int i,int j)
{
    if(j-i<=0)
    {
        y=res;
        res=0;
        return y;
    }
    if(s[i]==s[j])
            {
                res++;
                if(s[i-1]==s[j+1])res=res+2;
                if(j-i>0)
                {
                    return check(i+1,j-1);
                }
            }
    else if(s[i]!=s[j])
    {
        res=res+(j-i+1);
        return check(i+1,j-1);
    }
}
int solve()
{
    int ans=s.size();
    for(int i=0;i<s.size();i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            if(s[i]==s[j])
            {
                ans=ans+check(i,j);
            }
        }
    }
    return ans;
}
int main()
{
    cin>>s;
    cout<<solve()<<endl;
    return 0;
}
