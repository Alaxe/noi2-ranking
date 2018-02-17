#include<iostream>
//#include<deque>
using namespace std;
/*deque<int> chislo;
void outputlong(deque<int> A){
    int sizefindcopy,cifri=0;
    cout << A[0];
    if(A.size()>1){
        for(int i=1;i<A.size();i++){
            sizefindcopy=A[i];
            while(sizefindcopy>0){
                sizefindcopy/=10;
                cifri++;
            }
            for(int k=0;k<8-cifri;k++){
                cout<<"0";
            }
            cifri=0;
            cout<<A[i];
        }
    }
}*/
int main(){
    /*ool dasprali=0;
    chislo.push_front(99999990);
    while(!dasprali){
        outputlong(chislo);
        if(chislo[0]==1&&chislo[1]==111){
            dasprali=1;
        }
        cout<<endl;
        if(!(chislo[0]<99999999)){
            chislo[0]=0;
            chislo.push_front(0);
            chislo[0]++;
        }
        chislo[chislo.size()-1]++;
    }*/
    int n, k,start=10,ennd=9,curent;
    cin>>n;
    for(int j=0;j<n-2;j++){
        start*=10;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n-2;j++){

        }
    }
    cout<<start<<" "<<ennd;
    return 0;
}

