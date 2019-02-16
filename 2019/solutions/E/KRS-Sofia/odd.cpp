#include<iostream>
using namespace std;
int main(){
long long a, b, delitel, br, brQwadratni=0;
cin>>a>>b;
for(br=a;br<=b;br++){
    for(delitel=1;delitel<=br;delitel++){
        if(br/delitel==delitel && br%delitel==0){
            brQwadratni++;
        }
    }
}
cout<<brQwadratni;
return 0;
}
