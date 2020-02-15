#include<iostream>
using namespace std;
int main(){
int brTopcheta;
cin >> brTopcheta;
char input[brTopcheta+1];
cin >> input;
for(int i=brTopcheta-1;i>-1;i--){
    int brA=0,brB=0,brC=0,brD=0;
    for(int k=0;k<i+1;k++){
        switch(input[k]){
            case 'a':
                brA ++;
                break;
            case 'b':
                brB ++;
                break;
            case 'c':
                brC ++;
                break;
            case 'd':
                brD ++;
                break;
        }
    }
    if(brA + brB == brC + brD){
        cout << i+1;
        return 0;
    }
}
cout << 0;
return 0;
}
