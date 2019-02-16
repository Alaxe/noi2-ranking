#include<iostream>
using namespace std;
int main(){
long long n, m, br, brChisla=0, chislo;
cin>>n>>m;
for(br=n;br<=m;br++){
    chislo=br;
    while(chislo!=0){
        br=br+chislo%10;
        chislo=chislo/10;
    }
    brChisla++;
}
cout<<brChisla;
return 0;
}
