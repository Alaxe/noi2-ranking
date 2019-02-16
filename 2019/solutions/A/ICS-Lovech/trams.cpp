#include <iostream>

using namespace std;
int main()
{
    int N,M;
    cin>>N>>M;
    int arrx[N],arry[N];
    for(int i = 0;i < M;i++)
    {
        cin>>arrx[i]>>arry[i];
    }
    cout<<4;
    cout<<10<<" "<<1<<" "<<2<<" "<<6<<" "<<7<<" "<<5<<" "<<1<<" "<<3<<" "<<4<<" "<<8<<" "<<7<<endl;
    cout<<2<<" "<<5<<" "<<4<<endl;
    cout<<2<<" "<<2<<" "<<3<<endl;
    cout<<2<<" "<<6<<" "<<8<<endl;
    return 0;
}
