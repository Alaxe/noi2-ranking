#include<iostream>
using namespace std;
long long doKolko, otg = 0,z, minalaCifra;
int main(){
    cin>>doKolko;
    for(int i = 1; i <= doKolko; i++){
        if(i <= 9){
            otg++;
        }else{
            z = i;
            minalaCifra = z % 10;
            z/=10;
            while(z > 9){
                if(z%10 == minalaCifra){
                    minalaCifra = z%10;
                    z /= 10;
                }else{
                    break;
                }
            }
            if(z <= 9 && z == minalaCifra){
                otg++;
            }
        }
    }
    cout<<otg<<endl;
    return 0;
}
