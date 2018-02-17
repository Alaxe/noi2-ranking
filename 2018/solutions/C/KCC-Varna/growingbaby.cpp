#include<bits/stdc++.h>
using namespace std;
int moneti[3],m,n,p,q,dev[550000],brrazb;
void razb(int m, int br)
{
    if(m>0)
    {
        for(int i=0; i<2; i++)
        {
            if(i==1)
            {
                if(dev[br-1]==p)
                {
                    dev[br]=moneti[i];
                    razb(m-moneti[i],br+1);
                }
            }
            else
            {
                dev[br]=moneti[i];
                razb(m-moneti[i],br+1);
            }
        }
    }
    else brrazb++;
    return ;
}
int main()
{
	cin >> m >> n >> p >> q;
    moneti[0]=p;
    moneti[1]=-q;
    n-=m;
    dev[0]=p;
    razb(n-p,1);
    cout << brrazb << endl;
	return 0;
}
/**
4500 4560 20 7
*/
