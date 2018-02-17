#include<iostream>
using namespace std;

int main(){
long long brCvetq,kapkiZaMM,ngVisochina=0,nuzhniKapki=0;
cin>>brCvetq;
long long visochini[brCvetq];
for(long long i=0;i<brCvetq;i++){
    cin>>visochini[i];
}

cin>>kapkiZaMM;
for(long long i=0;i<brCvetq;i++){
    if(visochini[i]>ngVisochina){
        ngVisochina=visochini[i];
    }
}
for(long long i=0;i<brCvetq;i++){
    if(visochini[i]<ngVisochina){
        nuzhniKapki+=(ngVisochina-visochini[i])*kapkiZaMM;
    }
}
cout<<nuzhniKapki<<endl;
return 0;
}
