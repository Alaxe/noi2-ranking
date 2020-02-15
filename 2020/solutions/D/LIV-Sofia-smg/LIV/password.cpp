#include<iostream>
#include<cstring>
using namespace std ;
char password[5001] , alphabet [30];
long long ascii[256]  ;
int main(){
cin >> password ;
long long n = strlen(password) , iA = 0;
for(int i = 0 ; i < 26 ; i ++){
    alphabet [i] = char(i + 97) ;
}
for(int i = 0 ; i < n ; i ++){
    if(i != n - 2){
      if(password [i] == password [i + 1] && password [i + 1] == password [i + 2]){
          password [i + 2] = (alphabet [iA]) ;
          iA ++ ;
      }
    }
}
for(int i = 0 ; i < 256 ; i ++){
    ascii [int(password [i])] ++ ;
}
ascii [0] = 0 ;
long long maxA = ascii[0] , iM , razlika = 0;
for(int i = 0 ; i < 256 ; i ++){
    if(ascii [i] > maxA){
        maxA = ascii [i] ;
        iM = i ;
    }
}
if(maxA > (n / 2)){
    razlika = maxA - (n / 2) ;
}
for(int i = 0 ; i < n ; i ++){
    if(password [i] == char(iM)){

        password [i] = 'z' ;
        razlika -- ;
    }
    if(razlika == 0){
        break ;
    }
}
cout << password << endl ;
return 0 ;
}
