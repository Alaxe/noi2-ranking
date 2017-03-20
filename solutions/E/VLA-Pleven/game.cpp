#include<iostream>
using namespace std;
int main ()
{
    int k,m,i,n,s=0,a,minr=999999,veli=0;
    cin>>m>>k;
    for(i=1; i>=0; i++)
    {
        cin>>a;
        if(i>200)break;
        if(a<m)
        {
            if(m-a<=minr)
            {
                minr=m-a;
                veli=i;
            }
        }
        else
        {
            if(a-m<=minr)
            {
                minr=a-m;
                veli=i;
            }
        }
        if(a%2==0)s+=a;

        if(s>k)break;
    }
    cout<<veli<<"  "<<s<<endl;








    return 0;
}
