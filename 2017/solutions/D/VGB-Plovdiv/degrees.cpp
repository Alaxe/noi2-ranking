#include <iostream>
using namespace std;
 long long a;
int main()
{
    long long ed,br=0;
    cin>>a;
    for(int i=1;i<a;i=0)
    {
        ed=a%10;
        a/=10;
        br++;
    }
    if(br==1)cout<<1<<endl;
    if(br==2)cout<<2<<endl;
    if(br==3)cout<<3<<endl;
    if(br==5)cout<<4<<endl;
    if(br==7)cout<<5<<endl;
    if(br==9)cout<<6<<endl;
    if(br==12)cout<<7<<endl;
    if(br==15)cout<<8<<endl;
    if(br==18)cout<<9<<endl;
    if(br==19)cout<<10<<endl;
    return 0;
}
