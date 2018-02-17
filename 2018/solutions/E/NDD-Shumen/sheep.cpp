#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int l;
    cin>>l;
    int al;
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=l;j++)
        {
            cin>>al;
            if(i>=0&&i<=9&&i!=al)
            {
                maxi=i;
            }
        }
    }
    cout<<maxi<<endl;

return 0;
}