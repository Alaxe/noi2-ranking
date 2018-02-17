#include <iostream>
using namespace std;
int main()
{
int n,q,a,b,c,d,e;
cin >>n;
if(L=5){cin>>a>>b>>c>>d>>e;
cin >>q;
swap d,e
swap c,d
swap b,c
swap a,b
cout <<(a-b+a-c+a-d+a-e)*25<<endl;
}
else if(L=4){cin>>a>>b>>c>>d;
cin q;
swap c,d;
swap b,c;
swap a,b;
cout <<(a-b+a-c+a-d)*q<<endl;}
 else if(L=3){cin>>a>>b>>c;
cin q;
swap b,c;
swap a,b;
cout <<(a-b+a-c)*q<<endl;}
else if(L=2){cin>>a>>b;
cin q;
swap a,b;
cout <<(a-b)*q<<endl;}
 else if(L=1){cin>>a;
cin q;
cout <<a<<endl;}
return 0;
}
