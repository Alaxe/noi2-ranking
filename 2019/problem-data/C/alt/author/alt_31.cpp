#include <iostream>
using namespace std;


const int N=100;
int k, m, n;

unsigned long long int c;

int p[N+1];

void run(int i)
{
  if(i>n)
  {

    //for(int j=1;j<=n;j++) cout << p[j];
    //cout << endl;

    c++;
    return;
  }

  if(p[i-1]+k<m) {p[i]=p[i-1]+k; run(i+1);}
  if(p[i-1]-k>0) {p[i]=p[i-1]-k; run(i+1);}

}


int main()
{
    cin >> k >> m >> n;
    if (n==1) {cout <<  m-1 << endl; return 0;}

    for(int j=1;j<m;j++)
    {
      p[1]=j;
      run(2);
    }

    cout << c << endl;

}

