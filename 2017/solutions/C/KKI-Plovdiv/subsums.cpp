#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int n,mas[1001];
bool used[1000000],neg[1000000];
void output()
{
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<endl;
}
void gate(int k)
{
    //cout<<k<<endl;
    if(k>=0)
    {
        if(used[k]==0)
        {
            v.push_back(k);
            used[k]=1;
        }
    }
    else if(neg[k*-1]==0)
    {
        v.push_back(k);
        neg[k*-1]=1;
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>mas[i];
    gate(mas[0]);
    //output();
    for(int i=1;i<n;i++)
    {
        int m=v.size();
        for(int j=0;j<m;j++)
        {
            //cout<<j<<"<<"<<endl;
           gate(v[j]+mas[i]);
        }
        if(used[mas[i]]!=1)
        {

           gate(mas[i]);
        }
       // output();
        //cin.get();
    }

    cout<<v.size()<<endl;
    return 0;
}
/*
5
1 -2 0 7 7
*/
