#include <iostream>
#include <vector>
using namespace std;
int suma(vector<int> v)
{
    int sum=0;
    for(int i=0; i<v.size(); i++)
    {
        sum+=v[i];
    }
}
int main ()
{
    int n,m,min=1;
    bool b;
    long long br=0;
    vector<int> v1;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        v1.push_back(1);
    }
    br++;
    /*for(int i=0; i<v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;*/
    while(v1[0]<=m&&min<=m)
    {
        for(int i=0; i<v1.size()-1 ; i++)
        {
            if(v1[i]==min)
            {
                v1[i]+=v1[i+1];
                v1.erase(v1.begin()+i+1);
                /*for(int j=0; j<v1.size(); j++)
                {
                    cout<<v1[j]<<" ";
                }*/
                //cout<<endl;
                b=true;
                br++;
                break;
            }
        }
        if(b==false) min++;
        b=false;
    }
    cout<<br<<endl;
    return 0;
}
