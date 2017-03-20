#include <iostream>
using namespace std;
int main ()
{int n,i,ai,bi,poredisa,ai2,bi2;
cin >>n;
if (1<=n && n<=1000000) poredisa =0;
i =1;
ai2 =0; bi2 =0;
while (i<=n)
{cin >>ai>>bi;
if (ai<2 || ai>1000000 || bi<2 || bi>1000000) return 0;
if (ai<=ai2 && bi<=bi2 && ai>0) poredisa++;
if (ai<=bi2 && bi<=ai2) poredisa++;
i++;
if (i<=n && n%2==0) cin >>ai2>>bi2;
else if (i<n && n%2==1) cin >>ai2>>bi2;
if (ai2<2 || ai2>1000000 || bi2<2 || bi2>1000000) return 0;
i++;
if (ai>=ai2 && bi>=bi2) poredisa++;
else if (ai>=bi2 && bi>=ai2) poredisa++;}
cout <<poredisa;
}
