#include<iostream>
using namespace std;

const int MAXN=1e5+5;
int a[MAXN];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int otg=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            otg+=(a[i-1]-a[i]);
            a[i-1]=a[i];
        }
    }
    cout<<otg<<"\n";
    return 0;
}
