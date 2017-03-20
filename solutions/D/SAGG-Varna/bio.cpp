#include <iostream>
using namespace std;
int main ()
{
    int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int in[4]={0};
    for (int i=0;i<4;i++)
    {
        int sb=0,temp1,temp2;
        cin>>temp1;
        cin.ignore();
        cin>>temp2;
        for (int i2=0;i2<temp2-1;i2++)sb+=m[i2];
        in[i]=sb+temp1;
    }
    if (in[0]==in[1]&&in[1]==in[2])
    {
        in[0]+=23;
        in[1]+=28;
        in[2]+=33;
    }
    while (in[0]%23!=in[1]%28&&in[1]%28!=in[2]%33)
    {
        in[0]+=23;
        in[1]+=28;
        in[2]+=33;
    }
    cout<<in[3]-in[0]<<endl;
    return 0;
}
