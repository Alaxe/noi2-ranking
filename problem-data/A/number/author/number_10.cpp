#include<iostream>
using namespace std;

long long int M, N;

int main()
{
    cin >> M >> N;
    long long int br=0;
    long long int j=1;
    while(j*j+j<M) j++;
    while(j*j+j<=N) {br++;j++;}
    cout << br << endl;
}
