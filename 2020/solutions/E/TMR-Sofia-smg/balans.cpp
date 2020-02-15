#include <iostream>
#include <string>
using namespace std;

int main(){

int n,i,sum,sum2,j,max,min;
char a,b,c,d,s;
a='a';
b='b';
c='c';
d='d';
sum=0;
sum2=0;
cin >> n;
for (i=0;i<n;i++){
    cin >> s;
    if (s==a || s==b){
        sum++;
    }
    else if (s==c || s==d){
        sum2++;
    }
}
//
    if (sum==sum2){
        cout << n;
    }
    else if (n==3 || n==2 || n==1){
    cout << "0";
    }
    else if (sum!=sum2){
    while (sum!=sum2){
        if (sum>sum2){
            max=sum;
            min=sum2;
        }
        else{
            max=sum2;
            min=sum;
        }
        break;
    }
    cout << max;
    }
//cout << sum << endl << sum2;
}


