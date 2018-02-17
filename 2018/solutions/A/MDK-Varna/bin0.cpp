#include<iostream>
using namespace std;
int main(){
int s,t,z;
int vc = 0;
cin>>s>>t>>z;
while(s <= t)
{
    int current = s;
    int S = 0;
    while(current > 0)
    {
        if(current % 2 == 0) S++;
        current = current / 2;
    }
    if( S == z) vc++;
    s++;
}
cout<<vc;

return 0;
}
