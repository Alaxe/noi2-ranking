#include<iostream>
#include<algorithm>
using namespace std ;
long long visochini[128] ;
int main(){
long long n , u , v ;
cin >> n >> u >> v ;
for(int i = 0 ; i < n ; i ++){
    cin >> visochini [i] ;
}
long long rezult = 0 , maxV = visochini[0];
for(int i = 0 ; i < n ; i ++){
    if(visochini [i] > maxV){
        maxV = visochini[i] ;
    }
}
for(int i = 0 ; i < n ; i ++){
    if(i != 0 && i != n - 1){
       if(visochini [i] < visochini [i + 1]){
          if(visochini [i] < visochini [i - 1]){
             if(visochini [i + 1] > visochini [i - 1]){
                visochini [i] = visochini [i - 1] ;
             }
             else
             {
                 visochini [i] = visochini [i + 1] ;
             }
          }
       }
    }
}
for(int i = 0 ; i < n ; i ++){
    rezult += visochini [i] ;
}
rezult -= maxV ;
rezult *= u ;
cout << rezult << endl ;
return 0 ;
}
