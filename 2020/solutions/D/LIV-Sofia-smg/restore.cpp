#include<iostream>
#include <cstring>
using namespace std ;
long long a[100001] , b[100001] , kolko[100001] , chisla[100001];
int main(){
long long n,k = 0 , x = 0;
cin >> n ;
for(int i = 0 ; i < n ; i ++){
    cin >> b [i] ;
}
for(int i = 0 ; i < n ; i ++){
    kolko [i] = (n - i) - 1 ;
}
for(int i = 0 ; i < n ; i ++){
    x = 0 ;
    while(b[i] != kolko [k]){
        k ++ ;
        x ++ ;
    }
    a [i] = x ;
    kolko[k] = 0 ;
    k = 0 ;
}
bool edno = false ;
for(int i = 0 ; i < n ; i ++){
    if(edno){
        cout << " " ;
    }
    cout << a [i] ;
    edno = true ;
}
return 0 ;
}
