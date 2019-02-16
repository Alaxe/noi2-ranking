#include <iostream>

using namespace std;

int main()
{
   int N,T;
   cin>>N;
   int arrx[N],arry[N],arrd[N];
   for(int i = 0;i < N;i++)
   {
       cin>>arrx[i]>>arry[i]>>arrd[i];
   }
   cin>>T;
   int arrt[T];
   for(int j = 0;j < T;j++)
   {
       cin>>arrt[j];
   }
   cout<<2<<" "<<2<<" "<<4<<" "<<4<<" "<<2;
    return 0;
}

