#include<iostream>
using namespace std;
int main(){
long long chislo1,chislo2,chisla1,chisla2;
cin>>chislo1>>chislo2;
if(chislo1>chislo2){
    chisla1=(chislo1-chislo2)-1;
}
if(chislo2>chislo1){
    chisla2=(chislo2-chislo1)-1;
}
cout<<chisla1;
cout<<chisla2;
return 0;
}
