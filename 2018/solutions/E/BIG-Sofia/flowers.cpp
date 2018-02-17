#include<iostream>
using namespace std;
int main(){
long long n;
cin>>n;
long long visochini[n],kapkiZaMM,naiVisoko=-1,index,obshtoKapki=0;

for(index=0;index<n;index++){
    cin>>visochini[index];
    if(visochini[index]>naiVisoko){
        naiVisoko=visochini[index];
    }
}
cin>>kapkiZaMM;
for(index=0;index<n;index++){
    obshtoKapki=obshtoKapki+(naiVisoko-visochini[index])*kapkiZaMM;
}
cout<<obshtoKapki;
return 0;
}
