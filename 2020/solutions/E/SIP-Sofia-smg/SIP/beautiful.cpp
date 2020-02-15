#include<iostream>
using namespace std;
short brCifri(long long num){
    if(num == 0){
        return 1;
    }else{
        int bC = 0;
        while(num != 0){
            num = num / 10;
            bC ++;
        }
        return bC;
    }
}
bool beautiful(long long num){
    short lenght = brCifri(num);
    short cifri[lenght];
    bool f_num = true;
    short z_num = 0;
    for(int i=0;i<lenght;i++){
        cifri[i] = num%10;
        num = num / 10;
        if(f_num == true){
            z_num = cifri[i];
            f_num = false;
        }else{
            if(z_num != cifri[i]){
                return false;
            }
        }
    }
    return true;
}
int main(){
long long brStranici;
cin >> brStranici;
long long brKrasivi = 0;
for(int i=1;i<=brStranici;i++){
    if(beautiful(i) == true){
        brKrasivi = brKrasivi + 1;
    }
}
cout << brKrasivi;
return 0;
}
