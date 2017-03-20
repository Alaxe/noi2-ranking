#include<iostream>
using namespace std;
int main()
{
int m,k,a,a1,br=0,min,razl;

cin>> m >> k;
cin >>a1;

min = m-a1;



do{

cin>>a;
if (a%2==0) br=br+a;

if (m-a<min) min=m-a;

}while(br<k);


cout <<min<<" "<< br;

return 0;
}
