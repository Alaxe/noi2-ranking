#include <iostream>
using namespace std;
int main()              ///GRESHNO!!!
{
    int neshto[50], k, m, n;
    cin>>k>>m>>n;
    neshto[0]=m-1;
    for (int i=1; i<n; i++){
        neshto[i]=neshto[i-1]*2-2*k;
    }
    cout<<neshto[n-1]<<endl;
    for (int i=0; i<n; i++){
        cout<<neshto[i]<<" ";
    }

    return 0;
}
