#include <bits/stdc++.h>
using namespace std;
int main()
 {int a,b;
cin>>a>>b;
int suma=0;
for(int i=a;i<=b;i++)
{
    for(int c=2;c<=i-1;c++)
    {
        if(i%c==0)
        {
         break;
          }
        }
        if(i!=2  and i!=3 and i%5!=0 and i%2!=0)
       {
           suma=suma+1;
       }



    if(i==4)
        {
            suma=suma+1;
        }
if(i==1)
        {
            suma=suma+1;
        }

}

cout<<suma/2<<endl;

return 0;
}
