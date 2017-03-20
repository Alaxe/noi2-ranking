#include<iostream>
#include<cstring>
using namespace std;

long long variants[4]={2,4,8,6};
long long cVariant=0;
char input[160000];
int main(){
    cin >> input;
    long long n=0;
    for(long long i=0; i<strlen(input); i++){
        if(input[i]-'0'==variants[cVariant]){
            n++;
            cVariant++;
            cVariant%=4;
        }
    }
    cout << n;
    return 0;
}
