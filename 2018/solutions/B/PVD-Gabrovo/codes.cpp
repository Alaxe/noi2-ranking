#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

vector<string> generate(vector<string> prev, vector<char> digits)
{
    vector<string> next;
    for(int i=0; i<digits.size(); i++)
    {
        if(i%2==0)
        {
            for(int j=0; j<prev.size(); j++)
                next.push_back(string()+digits[i]+prev[j]);
        }
        else
        {
            for(int j=prev.size()-1; j>=0; j--)
                next.push_back(string()+digits[i]+prev[j]);
        }
    }
    return next;
}

int64_t n, k, a, b;
vector<char> digits;
vector<string> cur;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>a>>b;
    digits.resize(n);
    cur.resize(n);
    for(int64_t i=0; i<n; i++)
    {
        cin>>digits[i];
        cur[i]=string()+digits[i];
    }
}

int64_t s(const string &s)
{
    int64_t res=0;
    for(int64_t i=0; i<s.size(); i++)
        res+=(s[i]-'0');
    return res;
}

void solve()
{
    string max_num=cur[a-1];
    for(uint64_t i=a; i<b; i++)
    {
        if(cur[i]>max_num)max_num=cur[i];
    }
    cout<<max_num<<' ';
    int64_t max_dif=0, cur_dif;
    for(uint64_t i=a-1; i<b-1; i++)
    {
        cur_dif=abs(s(cur[i])-s(cur[i+1]));
        if(cur_dif>max_dif)max_dif=cur_dif;
    }
    cout<<max_dif<<endl;
}

int main()
{
    init();
    for(int64_t i=0; i<k-1; i++)
    {
        cur=generate(cur, digits);
    }
    //cout<<"ASD"<<endl;
    /*for(int64_t i=0; i<cur.size(); i++)
        cout<<cur[i]<<' ';
    cout<<endl;*/
    //cout<<cur.size()<<endl;
    solve();


    return 0;
}
