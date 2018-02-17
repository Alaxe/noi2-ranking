#include<iostream>
#include<cstring>

using namespace std;

char redica[160000];

int main(){

  long long n_stepen, duljina, br_cifri;
  cin >> redica;

  duljina=strlen(redica);

  for(long long i=1; i<=3; i++){
    duljina--;
    if(duljina==0){
      //cout << i << '\n';
      return 0;
    }
  }
  //cout << duljina;
  n_stepen=3;

  for(br_cifri=2; duljina>0; br_cifri++){
    duljina-=(3*br_cifri);
    n_stepen+=3;
    if(br_cifri%3==1){
      duljina-=br_cifri;
      n_stepen++;
    }
  }

  if(duljina<0){
    for(br_cifri--; duljina<0; n_stepen--){
      duljina+=br_cifri;
    }
  }

  cout << n_stepen << '\n';

  return 0;
}
