#include<iostream>
using namespace std;
int main(){
    long int br = 0, m, n;
    cin>>m>>n;
    while(m>=n){
        cout<<"M trqbva da e po malko ot N."<<endl;
        cin>>m>>n;
    }
    for(int i = m;i<=n;i++)
        for(int j = 1;j<=i/2;j++)
            if(i%j==0&&i%(j+1)==0)
                if(i==(j*(j+1)))br++;
    cout<<br;
    return 0;
}