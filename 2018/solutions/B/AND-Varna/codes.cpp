#include<bits/stdc++.h>
using namespace std;
vector<string> gen(vector<string> prev, vector<char> digits)
{
    vector<string> next;
    for (int i = 0; i < digits.size(); i++)
    {
        if(i%2 == 0)
        {
            for(int j=0; j < prev.size(); j++)
                next.push_back(digits[i] + prev[j]);
        }
        else
        {
            for(int j=prev.size()-1; j >= 0; j--)
                next.push_back(digits[i] + prev[j]);
        }
    }
    return next;
}
vector<char> dig;
vector<string> code;
long long n, k, a, b, i, raz=0;
string mx;
char ch;
long long sum(string t)
{
    long long ans=0;
    for(int j=0;j<t.size();j++)
    {
        ans+=t[j]-'0';
    }
    return ans;
}
int main()
{
    cin>>n>>k>>a>>b;
    for(i=0; i<n; i++)
    {
        cin>>ch;
        dig.push_back(ch);
        mx=ch;
        code.push_back(mx);
    }
    for(i=1; i<k; i++)
    {
        code = gen(code, dig);
    }
    //for(i=0;i<code.size();i++)cout<<code[i]<<" ";//!
   // cout<<"\n";//!
    mx=code[a-1];
    for(i=a; i<b; i++)
    {
    	//cout<<mx<<" "<<code[i]<<"\n";
        if(mx<code[i])mx=code[i];
        //cout<<i<<"\n";
        raz=max(raz, abs(sum(code[i])-sum(code[i-1])));
        //cout<<raz<<"\n";
    }
        cout<<mx<<" "<<raz<<"\n";
    return 0;
}
/*
3 2 3 5
7 1 5

3 3 10 16
7 1 5
*/
