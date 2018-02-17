#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n,k,start=1,final=1;

    cin>>n>>k;

 for (int br=1;br<n;br++)
 {
     start=start*10;
     
     }
final=start*10-1;
for (int a=start;a<=final;a++)
{ 
    if (a%k==0) {cout<<a; break;}
}
 
cout<<endl;

system ("PAUSE");
       return EXIT_SUCCESS;
}
