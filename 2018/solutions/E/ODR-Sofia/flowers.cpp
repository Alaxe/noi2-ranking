#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n, naiVisoko=0;
    cin>>n;
    int visochina[n];
    long long q, kapki=0;
    for(int index=0;index<n;index++)cin>>visochina[index];
    cin>>q;
    for(int index=0;index<n;index++){
        if(naiVisoko<visochina[index])naiVisoko=visochina[index];
    }
    for(int index=0;index<n;index++){
        while(visochina[index]<naiVisoko){
            visochina[index]++;
            kapki+=q;
        }
    }
    cout<<kapki;
    return 0;
}
