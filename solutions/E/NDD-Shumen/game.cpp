#include <iostream>
using namespace std;
int main ()
{
    long long int m,k;
    cin>>m>>k;
    int a;
    long long int num=1;
    long long int pos=0;
    long long int sum=0;
    do
    {
        cin>>a;
        pos++;
        if(a%2==0)sum=sum+a;
        if(a==m||a+1==m||a-1==m||a+2==m||a-2==m)
        {
            num=pos;
        }

    }while(sum<=k);
    cout<<num<<" "<<sum<<endl;

return 0;
}
