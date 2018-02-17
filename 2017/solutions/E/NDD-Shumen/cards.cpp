#include <iostream>
using namespace std;
int main ()
{
    long long int n;
    cin>>n;
    long long int ai,bi;
    cin>>ai>>bi;
    long long int s1=ai*bi;
    long long int br=0;
    long long int max=0;
    for(int i=1;i<n;i++)
    {
        int s2=ai*bi;
        if(s1>=s2)br++;
        if(br>max)
        {
            max=br;
        }
        cin>>ai>>bi;
    }
    if(br>max)max=br;
    cout<<max<<endl;

return 0;
}
