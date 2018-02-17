#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector< vector<int> > v;
int results[21];
int main()
{
    int t;
    int n,k;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
          for(int j=0;j<n;j++)
        {
            vector<int> p;
            v.push_back(p);

        }
        for(int j=0;j<n;j++)
        {
            cin>>k;
            v[k-1].push_back(j);
            v[j].push_back(k-1);
        }
         int maxsize=0;
            for(int j=0;j<v.size();j++)
            {
                if(maxsize<v[j].size())maxsize=v[j].size();
            }
            results[i]=maxsize;
            vector<vector<int> >l;
            v=l;
    }
    for(int i=0;i<t;i++)
    {
        cout<<results[i]<<endl;
    }
    return 0;
}
/*
2
4
4 1 2 3
5
4 1 2 3 4
*/
