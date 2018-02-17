#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <algorithm>

#define N 20
using namespace std;
int main () {
  int A[N] = {5, 12, 17, 19, 25, 29,
              31, 52, 66, 73, 89, 100,
              231, 356, 483, 512, 669, 999, 2706, 9998};
  char fname[50];

  for (int i=0; i<N; i++){
    sprintf(fname,"sdnf.%02d.in",i+1);
    ofstream f(fname);
    f<<A[i]<<endl;
    f.close();
    sprintf(fname,"sdnf<sdnf.%02d.in>sdnf.%02d.sol",i+1,i+1);
    system(fname);
  }
  return 0;
}

