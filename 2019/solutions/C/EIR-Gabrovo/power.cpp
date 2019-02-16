#include <iostream>
#include <cmath>
using namespace std;
int a[10000], n, k, pFactors[50];
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
void read()
{
    cin>>n>>k;
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
}
void factor(int in)
{
    int currFactor;
    for (int i=0; i<14; i++){
        currFactor=0;
        while (in%primes[i]==0){
            if (in==0) break;
            if (in%primes[i]==0){
                currFactor++;
                //cout<<in<<" "<<primes[i]<<endl;
                in/=primes[i];
            }
        }
        if (currFactor>pFactors[primes[i]]) pFactors[primes[i]]=currFactor;
    }
}
int main()
{
    int c=1;
    read();
    for (int i=0; i<n; i++) factor(a[i]);
    /*for (int i=0; i<43; i++){
        if (pFactors[i]>0) cout<<i<<" -> "<<pFactors[i]<<endl;
    }*/
    for (int i=0; i<14; i++){
        if (pFactors[primes[i]]!=0) c*=pow(primes[i], ceil((double)pFactors[primes[i]]/k));
    }
    cout<<c<<endl;

    return 0;
}
/*
4 3
3 4 5 6
*/
