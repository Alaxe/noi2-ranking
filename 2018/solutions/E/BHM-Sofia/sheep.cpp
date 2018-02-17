#include<iostream>
using namespace std;
int main(){
long long N,L,i,nGNomer;
cin>>N>>L;
long long lipstvat[L];
for(i=0;i<L;i++){
    cin>>lipstvat[i];
}
    nGNomer=N;
        for(i=0;i<L;i++){
            if(lipstvat[i]==nGNomer%10 or lipstvat[i]==nGNomer/10){
                nGNomer++;
        }
        }
cout<<nGNomer*2<<"\n";
return 0;
}
