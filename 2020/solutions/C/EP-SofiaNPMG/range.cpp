#include <iostream>
using namespace std;
unsigned int allcounters[100000],allvalues[100000];
int main(){
    unsigned int n,thenumbers[100000],m;
    cin>>n;
    for(unsigned int i=0;i<n;i++){
        cin>>thenumbers[i];
        allvalues[thenumbers[i]]++;
    }
    cin>>m;
    for(unsigned int i=0;i<m;i++){
        unsigned int a,b;
        cin>>a>>b;
        for(unsigned int j=a;j<=b;j++){
            allcounters[i]+=allvalues[j];
        }
    }
    for(unsigned int i=0;i<m;i++){
        cout<<allcounters[i]<<endl;
    }
    return 0;
}
