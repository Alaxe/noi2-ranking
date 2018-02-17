#include <iostream>
using namespace std;
int main()
 {
  int M , N , i , j , x , y;
  char A[200][200];

  for ( i = 0 ; i <= 150 ; i ++)
    for ( j = 0 ; j <= 150 ; j ++) A[i][j] = '#';

  cin >> M >> N;

  for ( i = 2 ; i <= M+1 ; i ++)
    for ( j = 2 ; j <= N+1 ; j ++) cin  >> A[i][j];

  for ( i = 2 ; i <= M+1 ; i ++)
    for ( j = 2 ; j <= N+1 ; j ++) if ( A[i][j] == 'E' ) { y = i ; x = j ; break;}

  if ( A[x][y-1] == '#' && A[x][y+1] == '#' && A[x-1][y] == '#' && A[x+1][y] == '#' && A[x][y-2] == '#' && A[x][y+2] == '#' && A[x-2][y] == '#' && A[x+2][y] == '#' && A[x-1][y-1] == '#' && A[x+1][y+1] == '#' && A[x-1][y+1] == '#' && A[x+1][y-1] == '#') cout << -1;
  else cout << (M+N)/2 + 2;
  return 0;
 }

