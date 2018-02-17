#include<iostream>
using namespace std;
int main(){
    long long N,q,NG,S=0;
    cin>>N;
    long long visochini[N];
    for(int i=0;i<N;i++){
        cin>>visochini[i];
    }
    cin>>q;
    NG=visochini[0];
    for(int i=0;i<N;i++){
        if(visochini[i]>NG){
            NG=visochini[i];
        }
    }
    for(int i=0;i<N;i++){
        S=S+(NG-visochini[i])*q;
    }
    cout<<S;
    return 0;
}
