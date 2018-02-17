#include <iostream>
using namespace std;
int main() {
    unsigned short m,n,x,y;
    unsigned int w=1;
    cin>>n>>m;
    if(m>n)m=n;
    while(m>1)
    {
        x=n-m+1;
        y=(n/m)+1;
        if(n%m==0)y--;
        w=w+1+x-y;
        m--;
    }
    cout<<w<<endl;
return 0;
}
