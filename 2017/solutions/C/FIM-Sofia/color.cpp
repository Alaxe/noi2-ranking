#include <iostream>

using namespace std;

int main()
{
    int T, a[100000], b[100000][2];
    cin >> T;
    int otg[T];
    for (int s=0; s<T; s++)
    {
        long long N;
        cin >> N;
        for (int i=0; i<N; i++)
        {
            cin >> a[i];
        }
        for(int i=0; i<N; i++)
        {
            for(int p=0; p<N; p++)
            {
                if(a[i]==a[p] && i!=p)
                {
                    b[i][1]=a[i];
                    b[i][2]++;
                }
            }
        }
        int max1=b[0][2];
        for(int i=1; i<N; i++)
        {
            if(max1<b[i][2])
            {
                max1=b[i][2];
            }
        }
        otg[s]=max1+2;
    }
    for(int i=0; i<T; i++)
    {
        cout << otg[i] << endl;
    }
}
