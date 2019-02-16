#include<bits/stdc++.h>
using namespace std;

int n, power;

int numbers[10005];

int primes[14]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
int mapedPrimes[50];


int nok[20];
int newNok[20];

long long celing(long long a, long long b){
    if(a%b==0)return a/b;
    return a/b+1;
}

long long poweR(long long a, long long b){
    long long ans=1;
    for(int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

int main(){
    ///
    mapedPrimes[2]=0;mapedPrimes[3]=1;mapedPrimes[5]=2;mapedPrimes[7]=3;mapedPrimes[11]=4;mapedPrimes[13]=5;mapedPrimes[17]=6;mapedPrimes[19]=7;mapedPrimes[23]=8;mapedPrimes[29]=9;mapedPrimes[31]=10;mapedPrimes[37]=11;mapedPrimes[41]=12;mapedPrimes[43]=13;
    ///
    cin>>n>>power;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int j=0;j<20;j++){
            newNok[i]=0;
        }
        for(int j=0;j<14;j++){
            while(a%primes[j]==0){
                newNok[j]++;
                a/=primes[j];
            }
            nok[j]=max(nok[j], newNok[j]);
        }
    }
    unsigned long long ans=1;
    for(int i=0;i<20;i++){
        if(nok[i]==0)continue;
        nok[i]=celing(nok[i],power);
        ans*=poweR(primes[i], nok[i]);
    }
    cout<<ans<<endl;
}
/**

**/
