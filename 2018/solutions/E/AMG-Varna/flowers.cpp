#include <iostream>
using namespace std;
int main()
{
int n,q,a,b,c,d,e;
cin>>n>>a>>b>>c>>d>>e>>q;
if (a<b) swap (a,b);
if (a<c) swap (a,c);
if (a<d) swap (a,d);
if (a<e) swap (a,e);
if (b<c) swap (b,c);
if (b<d) swap (b,d);
if (b<e) swap (b,e);
if (c<d) swap (c,d);
if (c<e) swap (c,e);
if (d<e) swap (d,e);
cout<<((a-b)+(a-c)+(a-d)+(a-e))*q<<endl;
return 0;
}
