#include<iostream>
#include<cmath>

using namespace std;

bool beautiful(long long int x)
{
    int c;
    int normal=x%10;
    while(x!=0)
    {
        c=x%10;
        x=x/10;
        if(c!=normal)
        {
            return false;
        }
    }
    return true;
}

int main()
{
	long long int N;
	cin>>N;
	long long int br=0;
	for(long long int i=1; i<N; i++)
    {
        if(beautiful(i))
        {
            br++;
        }
    }
    cout<<br<<endl;
    return 0;
}
