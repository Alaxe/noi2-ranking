#include<iostream>
using namespace std;
int main()
{
    long long a,b,br=0,k,j=1,i,x=1;
    cin>>a>>b;

    while(x<=a)
    {
        if(x*x>=a){
            br++;
            break;
        }
        else x++;
    }

    while(1){
        x++;
        if(x*x<=b) br++;
        else break;
    }
    cout<<br;


    return 0;
}
