#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,br=1,a,b,maxi,mini,broi[1000002];
void Read()
{
    vector <int> s;
    int x;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        s.push_back(x);
    }
    cin>>m;
    sort(s.begin(),s.end());
    for (int i=0;i<n;i++)
    {
        broi[s[i]]=br;
        br++;
    }
    maxi=s[n-1];
    mini=s[0];
    return ;
}
int main()
{
    Read();
    vector <int> iz;
    for (int i=0;i<m;i++)
    {
        cin>>a>>b;
        if (b<mini) {iz.push_back(0);continue;}
        if (a>maxi) {iz.push_back(0);continue;}
        if (a<mini && b>maxi) {iz.push_back(n);continue;}
        if (a<mini && b>=mini) {iz.push_back(broi[b]-broi[mini]+1);continue;}
        if (a>=mini && b<=maxi) {iz.push_back(broi[b]-broi[a]+1);continue;}
        if (a<=maxi && b>maxi) {iz.push_back(broi[maxi]-broi[a]+1);continue;}
    }
    for (int i=0;i<m;i++)
    {
        cout<<iz[i]<<endl;
    }
    return 0;
    //O(n) ,Max 0,8Mb
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/
