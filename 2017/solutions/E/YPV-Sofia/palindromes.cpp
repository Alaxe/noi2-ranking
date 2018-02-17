#include<iostream>
using namespace std;
int main(){
    long long N, vtoroChislo, purvoChislo, maximum=0, max1, max2, obratno=0, chislo, a;
    cin>>N;
    for(vtoroChislo=N-1;vtoroChislo>0;vtoroChislo--){
        for(purvoChislo=vtoroChislo-1;purvoChislo>0;purvoChislo--){
            chislo=vtoroChislo*purvoChislo;
            while(chislo>0){
                obratno=obratno*10+(chislo%10);
                chislo=chislo/10;
            }
            if(vtoroChislo*purvoChislo==obratno){
                if(obratno>=maximum){
                    max1=purvoChislo;
                    max2=vtoroChislo;
                    maximum=obratno;
                }
            }
            obratno=0;
        }
    }
    cout<<max1<<" "<<max2<<endl;
    cout<<maximum;
    cout<<endl;
return 0;
}
