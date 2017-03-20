#include<iostream>

using namespace std;

long long pacienti[721][2], sortirani_pacienti[721][2];
bool ima_li_pacient[721];

int main(){

  long long koga_idva, kolko_se_lekuva, br_pacienti=0;
  cin >> br_pacienti;
  /**while(cin){
    cin >> pacienti[br_pacienti][0] >> pacienti[br_pacienti][1];
    ima_li_pacient[pacienti[br_pacienti][0]]=true;
    cout << pacienti[br_pacienti][0] << ' ' << pacienti[br_pacienti][1] << '\n';
    br_pacienti++;
    //cout << br_pacienti << '\n
  }

  br_pacienti--;*/
  for(long long i=0; i<br_pacienti; i++){
    cin >> pacienti[i][0] >> pacienti[i][1];
    ima_li_pacient[pacienti[i][0]]=true;
  }
  for(long long i=0, j=0; i<721; i++){
    if(ima_li_pacient[i]){
      sortirani_pacienti[j][0]=i;
      for(long long k=0; k<br_pacienti; k++){
        if(pacienti[k][0]==i){
          sortirani_pacienti[j][1]=pacienti[k][1];
        }
      }
      j++;
    }
  }

  for(long long i=0; i<=br_pacienti; i++){
    cout << sortirani_pacienti[i][0] << ' ' << sortirani_pacienti[i][1] << '\n';
  }

  for(long long i=0; i<br_pacienti; i++){
    for(long long j=i+1; j<br_pacienti; j++){
      if(sortirani_pacienti[j][0]<sortirani_pacienti[i][1]+sortirani_pacienti[i][0]){
        sortirani_pacienti[j][1]+=sortirani_pacienti[i][0]-sortirani_pacienti[j][0];
      }
      else{
        break;
      }
    }
  }

  cout << sortirani_pacienti[br_pacienti-1][1] << '\n';

  return 0;
}

/**
55 15
185 22
130 10
*/


