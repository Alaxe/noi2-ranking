#include <iostream>
using namespace std;
int main()
{
int n,u,v,s[100],ob=0,br,p;
cin>>n>>u>>v;
for(int i=0;i<n;i++)
    cin>>s[i];
for(int i=0;i<n;i++)
{
    if(s[i+1]>s[i] || i==n-1)ob=ob+(s[i]*u*v);
    else
    {
        br=1;
        for(int j=i+1;j<n;j++)
            {
                if(s[j-1]>s[j]){br++;i++;}
                else {p=j;break;}
            }
        ob=ob+(br*u*v*s[p]);
        i++;
    }
}
cout<<ob<<endl;
return 0;
}
