#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int m,k,a,i=0,sum=0,razl,np,razl1;

    cin>>m>>k;

    razl=fabs(a-k);

    while(sum<k && i<200)
    {
        cin>>a;

        if(a%2==0)sum+=a;

        razl1=fabs(a-k);

        if(razl1<razl)
        {
            np=i;

            razl=razl1;
        }

        i++;
    }

    if(sum>k){np=np+2;cout<<np<<" "<<sum<<endl;}

    else {cout<<np<<" "<<sum<<endl;}

    return 0;
}
