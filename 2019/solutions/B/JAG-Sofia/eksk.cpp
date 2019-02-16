#include <iostream>
using namespace std;
int main()
{
     int A[200000] , B[200000] , i , N;
     cin >> N;
     for (i = 0 ; i < N ; i ++) cin >> A[i] >> B[i];
     cout << N/3;
  return 0;
}
