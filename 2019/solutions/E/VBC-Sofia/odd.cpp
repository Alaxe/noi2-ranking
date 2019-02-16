#include<iostream>
using namespace std;

int main()
{
    long long a,b,brzachisla,deliteli,broideliteli=0,broichisla=0;
    cin>>a>>b;
    for(brzachisla=a;brzachisla<=b;brzachisla++)
    {
        for(deliteli=1;deliteli<=brzachisla;deliteli++)
        {
            if(brzachisla%deliteli==0)
            {
                broideliteli=broideliteli+1;
            }
        }
        if(broideliteli%2!=0)
        {
            broichisla=broichisla+1;
        }
        broideliteli=0;
    }
    cout<<broichisla<<endl;
    return 0;
}
