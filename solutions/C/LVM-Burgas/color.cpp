#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool sort1(int x,int y){return x>y;}
int main()
{
    int t;
    cin>>t;
    vector<int> res;
    for(int brr=0;brr<t;brr++)
    {
     int n;
     cin>>n;
     vector<int> v;
     for(int br=0;br<n;br++)
     {
         v.push_back(0);
     }
    for(int br=0;br<n;br++)
    {
     int x;
     cin>>x;
     v[x-1]++;
     v[br]++;
    }
     sort(v.begin(),v.end(),sort1);
     res.push_back(v[0]);
    }
    for(int br=0; br<res.size();br++)
    {
        cout<<res[br]<<endl;
    }
}
