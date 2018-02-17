#include <iostream>
using namespace std;
int main () {

long long n,k,chislo=1, kopchislo=0, cifri=0, kopn;

cin>>n>>k;
kopn=n;
while( kopn>1 ){

    chislo=chislo*10;
    kopn--;
}
kopchislo=chislo;
while( kopchislo>0 ){

        kopchislo=kopchislo/10;

        cifri++;
    }





for( ; (chislo % k) != 0 and cifri == n ; chislo++){
    cifri=0;
     kopchislo=chislo;
    while( kopchislo>0 ){

        kopchislo=kopchislo/10;

        cifri++;
    }
}
cout<<chislo;

return 0;
}
