#include<iostream>
using namespace std;
int main(){
    long long int a,b,br=1,CH=1,br2=3;
    cin>>a>>b;
    while(CH<a){
        CH+=br2;
        br2+=2;
    }
    while(CH<b){
        CH+=br2;
        if(CH>b)break;
        br++;
        br2+=2;
    }
    cout<<br<<endl;
    return 0;
}
