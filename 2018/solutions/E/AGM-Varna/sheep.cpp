#include <iostream>
using namespace std;
int main ()
{
    long long O,ch=0;
    int L,L1[3];
    cin>>O;
    cin>>L;
    for(int i=0; i<L; i++)
    {
        cin>>L1[i];
    }
    for (long long n=0,N=1; n!=O ; N++)
    {
        if (L=1)
        {
            if ((N/100000 && N/10000%10 && N/1000%10 && N/100%10 && N/10%10 && N%10) != L1[0])n++,ch=N;
        }

        if (L=2)
        {
            if ((N/100000 and N/10000%10 and N/1000%10 and N/100%10 and N/10%10 and N%10)!=(L1[0] and L1[1]))n++,ch=N;
        }

        if (L=3)
        {
            if ((N/100000 and N/10000%10 and N/1000%10 and N/100%10 and N/10%10 and N%10)!=(L1[0] and L1[1] and L1[2]))n++,ch=N;
        }
        cout<<N<<endl;
    }

    cout<<ch<<endl;

    return 0;
}
