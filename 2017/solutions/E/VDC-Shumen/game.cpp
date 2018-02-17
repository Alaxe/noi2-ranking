#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <cstring>
using namespace std;
int main()
{
    int m,k;
    cin>>m>>k;
    int sum=0,max=0,br=0,num=100001,a;
    while(sum<k)
    {
        br++;
        cin>>a;
        if(a%2==0)sum=sum+a;
        if(m>a)
        {
            max=m-a;
        }
        else max=a-m;
        if(br<m)
        {
            max=br;
            num=br;
        }
    }
   cout<<num<<" "<<sum<<endl;
    return 0;
}
