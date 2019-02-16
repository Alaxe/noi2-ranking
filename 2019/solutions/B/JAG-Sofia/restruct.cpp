#include <iostream>
using namespace std;
int main()
{
  int N , K , i , a , j , k , l , curr = 0 , maxi , depth ,  tar ,checksum = 0 , length , br;
  int Depth[10000] , Choice[10000], Most[10000] , Arr[10000] , Count[10000] , Check[10000];
  cin >> N >> K;
  for (i = 0 ; i < N ; i++)
  {
   cin >> Choice[i];
   Choice[i] += curr;
   for (j = curr ; j < Choice[i]; j++) {cin >> Arr[j]; Count[Arr[j]]++; }
   curr = Choice[i];
  }
  length = curr;
  maxi = 0;
  Choice[-1] = 0;
  for (i = 1 ; i <= N; i++) if (Count[i] > maxi) maxi = Count[i];
  for (i = 1 ; i <= N; i++) if (Count[i] == maxi) {Depth[i] = 1; tar = i; Check[i-1] = 1 ; checksum ++; break;}

  while (checksum <= N)
  {
      for (i = 0 ; i < N ; i++)
      {
        if (Check[i] == 0)
        {
         for (j = Choice[i-1]; j < Choice[i]; j++) if(Arr[j] == tar) {Depth[i+1] = Depth[tar] + 1; Check[i] = 1; checksum++; break;}
        }
      }
      maxi = 0 ;
      for (i = 1 ; i <= N; i++) if (Count[i] > maxi) maxi = Count[i];
      for (i = 1 ; i <= N; i++) if (Count[i] == maxi) {Depth[i+1] = 1; tar = i; Check[i] = 1 ; checksum ++; break;}
  }
  br = N;
  for (i = 1 ; i <= N ; i ++) {br+= Depth[i];}
  cout << br*K;
  return 0;
}
