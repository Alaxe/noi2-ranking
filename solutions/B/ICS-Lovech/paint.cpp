#include <iostream>

using namespace std;

int main()
{
   int w,h,w1,h1,w2,h2,x,y,n,t,k,j,k1,j1,k2,j2,o,p,o1,p1,o2,p2,o3,p3,s,a,b,a1,b1,a2,b2;
   cin>>x>>y;
   cin>>n;

        cin>>a>>b>>w>>h;
        k=a+w;
        j=b+h;
        cin>>a1>>b1>>w1>>h1;
        k1=a1+w1;
        j1=b1+h1;
        cin>>a2>>b2>>w2>>h2;
        k2=a2+w2;
        j2=b2+h2;
        cin>>t;
        cin>>o>>p;
        cin>>o1>>p1;
        cin>>o2>>p2;
        cin>>o3>>p3;
        cout<<(w1*h1)<<endl;
        cout<<((w*h)-(w1*h1))<<endl;
        cout<<((x*y)-((w*h)+(w2*h2)))<<endl;
        cout<<(w2*h2)<<endl;
    return 0;

}
