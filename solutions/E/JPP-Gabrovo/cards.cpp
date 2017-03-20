#include<iostream>
using namespace std;

long long a[100001],b[100001];

int main()
{
    long long n;
    cin >> n;

    for(int i=0; i<n; i++) cin >> a[i] >> b[i];

    long long maxbr=0;
    for(int i=0; i<n-1; i++)
    {
        int j=i,br=1;
        while(((a[j]>=a[j+1] && b[j]>=b[j+1]) || (a[j]>=b[j+1] && b[j]>=a[j+1])) && j<n-1)
        {
            br++;
            j++;
        }
        if(br>maxbr) maxbr=br;
    }

    cout << maxbr << endl;

    return 0;
}
