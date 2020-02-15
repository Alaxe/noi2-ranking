#include<iostream>
using namespace std;
int main(){
long long brDeistviq;
short podChasha;
cin >> brDeistviq >> podChasha;
short momentnaChasha = podChasha;
for(int i=brDeistviq;i>0;i--){
    if(i%2 == 0){
        if(momentnaChasha == 1){
            momentnaChasha = 2;
        }else if(momentnaChasha == 2){
            momentnaChasha = 1;
        }
    }else{
        if(momentnaChasha == 0){
            momentnaChasha = 1;
        }else if(momentnaChasha == 1){
            momentnaChasha = 0;
        }
    }
}
cout << momentnaChasha;
return 0;
}
