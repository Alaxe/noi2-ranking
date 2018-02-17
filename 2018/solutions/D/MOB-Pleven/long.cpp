#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int n,k;
cin>>n>>k;
int n1=n;
int s=1;
n--;
while(n!=0)
{
    if(s<k){s*=10;n--;}
     s=s%k;
}
if(s==0)for(int i=0;i<n1;i++){if(i==0)cout<<1;else cout<<0;}
else {
    string s1;
    int l=0;
    s=k-s;
    while(s!=0)
    {
        s1+=s%10+48;
        s/=10;
        l++;
    }
    reverse(s1.begin(),s1.end());
    if(s1.size()==n1)cout<<s1;
    else {
        cout<<1;
        for(int i=0;i<n1-1-s1.size();i++)
        {
            cout<<0;
        }
        cout<<s1;

    }
}
return 0;
}
