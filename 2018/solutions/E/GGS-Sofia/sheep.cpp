#include <iostream>
using namespace std;
int main ()
{

long long ovce,brZagubeniPechati,zagubeniPechati[3],segNomer=0,cifra,isegNomer;
bool krai=true;
cin >> ovce >> brZagubeniPechati;

zagubeniPechati[0]=0;
zagubeniPechati[1]=0;
zagubeniPechati[2]=0;

for (int i=0;i<brZagubeniPechati;i++){
    cin >> zagubeniPechati[i];
}

while (ovce!=0){
    segNomer++;
    isegNomer=segNomer;
    krai=true;

    while(isegNomer!=0 && krai==true){
    cifra = isegNomer%10;
    if (cifra!=0 && (cifra==zagubeniPechati[0] || cifra==zagubeniPechati[1] || cifra==zagubeniPechati[2])){
        krai=false;
    }
    isegNomer=isegNomer/10;
}

    if (krai==true){
        ovce--;
    }

}
cout << segNomer << endl;

return 0;
}
