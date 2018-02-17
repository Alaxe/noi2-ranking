# include<iostream>
using namespace std;

int main(){
    long long A[10000],B[10000],wr,i=0,maxa=0,maxab=0;
    while(cin >> A[i] >> B[i]){
        if(A[i]>maxa){
            maxa=A[i];
            maxab=B[i];
        }
        i++;
    }
    cout << maxab << endl;
return 0;
}
