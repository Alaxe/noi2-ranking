#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<deque>
#include<stack>
#include<vector>
#include<math.h>
#include<utility>
using namespace std;
vector<int>a[27];
unsigned long long comb[27]={0,0,1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253,276,300};
int i,k,c,j,maks=-1,l=0,o=0;
pair<int,int>h[1000];
unsigned long long otg=0;
string n;
void func()
{
    for(int ii=0;ii<=maks;ii++)
    {
        for(int jj=1;jj<a[i].size();jj++)
        {
            otg+=(a[ii][jj]-a[ii][jj-1]-1);
        }
    }
}
void nach()
{
    for(i=0;i<=maks;i++)
    {
        for(j=0;j<a[i].size();j++)
        {
            for(int jj=j+1;jj<a[i].size();jj++)
            {
                h[l].first=a[i][j]-1;
                h[l].second=a[i][jj]+1;
                otg+=(a[i][jj]-a[i][j]-1);
                l++;
            }
        }
    }
}
int main()
{
    //freopen("zad2.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    k=n.size();
    for(i=0;i<k;i++)
    {
        c=n[i]-'0';
        //cout<<c<<endl;
        if(c-48>maks) maks=c-48;
        a[c-48].push_back(i);
        
    }
    /*for(i=0;i<=maks;i++)
    {
        for(j=0;j<a[i].size();j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }*/
    otg=k;
    for(i=0;i<=maks;i++)
    {
        otg+=comb[a[i].size()];
    }
    nach();
    /*cout<<"l= "<<l<<endl;
    
    for(int ii=0;ii<l;ii++)
        cout<<h[ii].first<<" "<<h[ii].second<<endl;
        */
    for(i=0;i<=maks;i++)
    {
        for(j=0;j<a[i].size();j++)
        {
            for(int jj=j+1;jj<a[i].size();jj++)
            for(o=0;o<l;o++)
            {
                //cout<<"prov: "<<a[i][j]<<" "<<a[i][jj]<<endl;
                if(a[i][j]==h[o].first && a[i][jj]==h[o].second)
                {
                    //cout<<"vliza"<<endl;
                    otg+=h[o].second-h[o].first-2;
                }
            }
        }
    }
    cout<<otg<<endl;
    return 0;
}
