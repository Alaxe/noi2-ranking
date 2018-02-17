#include<iostream>
using namespace std;

int main()
{
    long long m,k;
    cin >> m >> k;

    long long s,sum=0,mindiv=1000000000,br=0,number;
    while(sum<k && s!=200)
    {
        cin >> s;
        br++;
        if(s%2==0) sum=sum+s;
        if(s<=m)
        {
            if(m-s<=mindiv)
            {
                mindiv=m-s;
                number=br;
            }
        }
        if(s>m)
        {
            if(s-m<=mindiv)
            {
                mindiv=s-m;
                number=br;
            }
        }
    }

    cout << number << " " << sum << endl;

    return 0;
}
