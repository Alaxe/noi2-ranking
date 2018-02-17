#include<iostream>
using namespace std;
int main()
{
    int n;   
    cin>>n;
    int a,b,c,d,e,f,g,h,i,k,l,m;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>k>>l>>m;
    int n1=a*b;
    int n2=c*d;
    int n3=e*f;
    int n4=g*h;
    int n5=i*k;
    int n6=l*m;
    if(n1>=n2)
    {
        br++;
    }
    if(n2>=n3)
    {
        br++;
    }
    if(n3>=n4)
    {
        br++;
    }
    if(n4>=n5)
    {
        br++;
    }
    if(n5>=n6)
    {
        br++;
    }
    cout<<br+1<<endl;

    


return 0;    
}
