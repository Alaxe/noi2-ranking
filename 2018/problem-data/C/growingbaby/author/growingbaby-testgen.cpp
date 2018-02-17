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
  int A[N*4] = {
    4500,4501,2,1,
    4500,4590,30,10,
    4450,4550,50,25,
    4450,4610,20,3,
    3250,5000,99,43,
    3100,5250,73,19,
    3050,6666,83,29,
    2999,6890,33,32,
    2871,5007,47,15,
    2780,6767,55,33,
    2605,7001,65,15,
    2590,7300,99,1,
    2400,7800,89,78,
    2300,8000,72,24,
    2200,8400,5,1,
    2100,4600,22,13,
    2000,8900,58,31,
    2000,9000,3,2,
    2000,10000,100,1,
    2000,10000,100,99
  };
  char fname[100];

  for (int i=0; i<N; i++){
    sprintf(fname,"growingbaby.%02d.in",i+1);
    ofstream f(fname);
    f<<A[4*i]<<' '<<A[4*i+1]<<' '<<A[4*i+2]<<' '<<A[4*i+3]<<endl;
    f.close();
    sprintf(fname,"growingbaby<growingbaby.%02d.in>growingbaby.%02d.sol",i+1,i+1);
    system(fname);
  }
  return 0;
}

