#include<iostream>
using namespace std;
int main() {
    unsigned long long otKolko,doKolko,seg,probvanDelitel,chastno,broiDeliteli,broiDobri=0;
    cin>>otKolko>>doKolko;
    for(seg=otKolko;seg<=doKolko;seg++) {
        chastno=seg;
       // cout<<seg<<" - ";
        broiDeliteli=0;
        for(probvanDelitel=1;probvanDelitel<=doKolko;probvanDelitel++) {
            if(chastno%probvanDelitel==0) {
          //    cout<<probvanDelitel<<" ";
                broiDeliteli++;
            }
        }
        if(broiDeliteli%2==1) {
            broiDobri++;
           // cout<<" - da "<<seg;
        }
      //  cout<<endl<<endl;
    }
    //cout<<endl<<endl;
    cout<<broiDobri<<endl;
return 0;
}
