#include<iostream>
using namespace std;
int main(){
    int n,k;
    bool stawali=true;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    long long c=0,b=1;
    while(stawali){
        stawali=false;
        c++;
        b=1;
        for(int j=0;j<k;j++){
            b=b*c;
        }
        for(int i=0;i<n;i++){
            if(b%a[i]!=0){
                stawali=true;
                break;
            }
        }
    }
    cout << c << endl;
    return 0;
}
