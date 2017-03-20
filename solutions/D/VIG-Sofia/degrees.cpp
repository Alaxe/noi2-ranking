#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int log10(int a){
    int res=1;
    while(a>10){
        res++;
        a/=10;
    }
    return res;
}

int main(){
    char input[160000];
    cin >> input;
    int len = strlen(input);
    int stageof2=1;

    while(len>0){
        len-=log10(pow(2,stageof2));
        stageof2++;
    }

    cout << stageof2-1 << endl;
    return 0;
}
