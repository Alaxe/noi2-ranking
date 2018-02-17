#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long A,B,n,k;
vector<string> p;
vector<char> d;
vector<string> generate(vector<string> prev,vector<char>digits)
{
    vector<string>next;
    for(int i=0;i<digits.size();i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<prev.size();j++)
            {
                next.push_back(digits[i]+prev[j]);
            }
        }
        else
        {
                for(int j=prev.size()-1;j>=0;j--)
                {
                    next.push_back(digits[i]+prev[j]);
                }
        }
    }
    return next;
}
string higher(vector<string>curr)
{
    vector<string>results;
    for(int i=A;i<=B;i++)
    {
        results.push_back(curr[i]);
    }
    sort(results.begin(),results.end());
    return results.back();
}
long long hire(vector<string> curr)
{
    long long result=0;
    vector<long long>acent;
    int br=0;
    for(int i=A;i<=B;i++)
    {

        acent.push_back(0);
        for(int j=0;j<curr[i].size();j++)
        {
            long long help=curr[i][j]-'0';
            acent[br]+=help;
        }
        br++;
    }
    for(int i=0;i<acent.size()-1;i++)
    {
        long long just=acent[i]-acent[i+1];
        if(just<0)
        {
            just*=-1;
        }
        if(result<just)result=just;
    }
    return result;
}
int main()
{
    cin>>n>>k>>A>>B;
    A--;
    B--;
    for(int i=0;i<n;i++)
    {
        char f;
        string f2;
        cin>>f2;
        f=f2[0];
        d.push_back(f);
        p.push_back(f2);
    }

    for(int i=0;i<k-1;i++)
    {
        p=generate(p,d);
    }

    //cout<<endl;
    cout<<higher(p)<<" ";
    cout<<hire(p)<<endl;
    return 0;
}
/*
3 2 3 5
7 1 5
*/
