#include<iostream>
using namespace std;
int main(){
long long nomer,nov=0,chislo=1;
cin>>nomer;

    for(long long i=0;i<nomer-1;i++){
             nov=nov+chislo;

        chislo=chislo+2;

    }

cout<<nov+nomer;









return 0;
}

