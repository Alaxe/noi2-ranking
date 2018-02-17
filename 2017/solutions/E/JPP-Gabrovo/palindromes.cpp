#include<iostream>
using namespace std;

int x[1000];

int main()
{
    long long n;
    cin >> n;

    long long maxpal=0,a=0,b=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            long long pro=i*j;
            long long t=pro;
            int br=0;
            while(t>0)
            {
                br++;
                t=t/10;
            }
            long long r=1;
            for(int k=1; k<br; k++)
                r=r*10;
            long long y=pro;
            int z=0;
            while(r>0)
            {
                x[z]=y/r;
                y=y%r;
                r=r/10;
                z++;
            }
            int l=0,h=br-1;
            while(l<=h)
            {
                if(x[l]==x[h]) {l++; h--;}
                if(x[l]!=x[h]) break;
            }
            if((br%2==0 && l==br/2) || (br%2!=0 && l==(br/2)+1))
            {
                if(pro>maxpal)
                {
                    maxpal=pro;
                    a=i;
                    b=j;
                }
            }
        }
    }

    cout << a << " " << b << endl << maxpal << endl;

    return 0;
}
