#include<iostream>
#include<stack>
using namespace std;
#define MAXN 100000
struct pair1
{
    int end,count;
};
stack<int> s1,s2;
int main()
{
    pair1 a1[MAXN],a2[MAXN];
    int n,a[MAXN],i,j,end,max=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        s1.push(i);
        s2.push(i);
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])while(s1.size()>0&&a[s1.top()]<=a[j])s1.pop();
            if(a[i]<a[j])while(s2.size()>0&&a[s2.top()]>=a[j])s2.pop();
            if(a[s1.top()]>a[j])s1.push(j);
            if(a[s2.top()]<a[j])s2.push(j);
        }
        a1[i].count=s1.size();
        a2[i].count=s2.size();
        a1[i].end=s1.top();
        a2[i].end=s2.top();
        s1=stack<int>();
        s2=stack<int>();
    }
    for(i=0;i<n;i++)
    {
        if(max<a1[i].count)max=a1[i].count;
        if(max<a2[i].count)max=a2[i].count;
        if(max<a2[i].count+a1[a2[i].end].count&&a2[i].count+a1[a2[i].end].count<=n)max=a2[i].count+a1[a2[i].end].count;
    }
    cout<<max<<endl;
    return 0;
}
