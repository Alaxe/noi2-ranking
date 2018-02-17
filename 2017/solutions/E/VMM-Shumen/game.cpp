#include <iostream>

using namespace std;

int main()

{
    int m,k,a[7];
    cin>>m>>k;
    for(int i=0;i<7;i++)
    {
        cin>>a[i];
    }
    int sum=a[7];
    for(int i=0;i<7;i++)
    {
        if(a[i]%2==0)sum=sum+a[i];
    }
    cout<<sum<<endl;

return 0;   
 
}