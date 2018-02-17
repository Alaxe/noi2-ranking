#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class N{
public:
    int value;
    int c;
};
   vector<int> Sums;
    vector<N> v;
    int n;
vector<int> getsums(int i,int sum)
{
    vector<int> sums;
    for(i;i<n;i++)
    {
    for(int br=i+1;br<v.size();br++)
    {
      //  cout<<"summmmmmmmmmm=========     "<<sum<<endl;
       // cout<<"next=========     "<<v[br].value<<endl;
      //  cout<<"now=========     "<<v[i].value<<endl;
      for(int br2=1;br2<=v[br].c;br2++)
      {
          sums.push_back(v[br].value+v[i].value*br2+sum);
      }
      vector<int> moreSums=getsums(br,v[br].value+v[i].value+sum);
      for(int br2=0;br2<moreSums.size();br2++)
      {
          sums.push_back(moreSums[br2]);
      }
    }
    }
    return sums;
}
int main()
{
    cin>>n;
    for(int br=0; br<n;br++)
    {
        N a;
        cin>>a.value;
        if(br==0)
        {
        a.c=1;
        v.push_back(a);
        }
        else
        {
             if(a.value!=v[br-1].value)
             {
                 a.c=1;
                 v.push_back(a);
             }
            else
            {
            v[br-1].c++;
            }
        }
    }
    vector<int> sums= getsums(0,0);
    sort(sums.begin(),sums.end());
    int c=0;
      for(int br=0;br<v.size();br++)
    {
        //cout<<v[br].value<<"  "<<v[br].c<<endl;
    }
    for(int br=0;br<sums.size();br++)
    {
       // cout<<sums[br]<<endl;
        if(br==0)
        {
            c++;
        }
        else
        {
            if(sums[br]!=sums[br-1])c++;
        }
    }
    cout<<c<<endl;
}
