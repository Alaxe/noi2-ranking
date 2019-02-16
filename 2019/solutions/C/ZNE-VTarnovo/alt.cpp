#include <iostream>

using namespace std;

int alt (short k,short m,short n)
{
 	if(n==1) return m-1;
	else return alt(k,m,n-1)*2-2*k;
}

int main()
{
	short k,m,n;
	cin>>k>>m>>n;
    if(n==1) cout<<m-1;
    else
    {
	if(k>=m-1) cout<<0;
	else cout<<alt(k,m,n)<<endl;
	}
    

}

