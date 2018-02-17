#include<iostream>
#include<vector>
using namespace std;
int n,tek;
vector<int>vhod,res;
bool ch(int a)
{
    for(int i=0;i<res.size();i++)
    {
        if(res[i]==a)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tek;
        vhod.push_back(tek);
    }
    res.push_back(vhod[0]);
    for(int i=1;i<n;i++)
    {
        int k=res.size();
        for(int j=0;j<k;j++)
        {
            if(ch(vhod[i]+res[j]))
            {
                res.push_back(vhod[i]+res[j]);
            }
            if(ch(vhod[i]))
            {
                res.push_back(vhod[i]);
            }
        }
    }
    cout<<res.size();
    return 0;
}
