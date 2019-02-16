#include  <bits/stdc++.h>

using namespace std;
int main()
{
	int a,b,s=0,d=0;
	cin>>a>>b;

	for ( int i=a; i<=b; i++ )
	{
	    for ( int c=2; c<=i; c++ )
        {
            if ( i%c==0 ) { break; }
        }

	if ( i!=2 and i!=3 and i%5!=0 and i%2!=0 )
	{
	    s=s+1;
	}

	if ( i==4 )
    {
        s=s+1;
    }

    if ( i==1 )
    {
        s=s+1;
    }
	}
	cout<<s/2<<endl;




return 0;
}
