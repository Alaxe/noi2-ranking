#include<bits/stdc++.h>
using namespace std;
vector<int> v,vrev;
int n;
vector<int> rev(vector<int> a)
{
    vector<int> aprime;
    for(int i=a.size()-1;i>=0;i--)
    {
        aprime.push_back(a[i]);
    }
    return aprime;
}
void eraseBastards(stack<int>& s, int value)
{
    s.pop();
    while( !s.empty() && value<s.top() )
    {
        s.pop();
    }
    s.push(value);
}
void solve(vector<int> seq,vector<int>& costs)
{
    stack<int> dp;
    for(int i=0;i<n;i++)
    {
        if(dp.empty())
        {
            dp.push(seq[i]);
            //cout<<"1"<<endl;
        }
        else if(seq[i]>dp.top())
        {
            dp.push(seq[i]);
            //cout<<2<<endl;
        }
        else if(seq[i]<= dp.top())
        {
            //cout<<3<<endl;
            eraseBastards(dp,seq[i]);


        }
        costs.push_back(i==0?dp.size():dp.size()>costs.back()?dp.size():costs.back());
    }
}
int finalsolve(vector<int> cost1,vector<int> cost2,vector<int> seq)
{
    int result = 0;
    int currentvalue;
    if(cost1.size() == 1)return 1;
    if(cost1.size() == 0)return 0;
    for(int i=0;i<cost1.size() - 1;i++)
    {
        if(seq[i]==seq[i+1])currentvalue = 1;
        else currentvalue = cost1[i] + cost2[i+1];
        if(result<currentvalue)result = currentvalue;
    }
    return result;
}
int main()
{
    int k;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    vector<int> cost,negcost;
    vrev = rev(v);
    solve(v,cost);
    solve(vrev,negcost);
    negcost = rev(negcost);
    //cout<<"How Many niggers are in my store"<<endl;
    cout<<finalsolve(cost,negcost,v)<<endl;
    return 0;
}
/*
8
1 5 2 5 3 5 4 5

9
1 5 2 5 3 5 2 5 1


*/
