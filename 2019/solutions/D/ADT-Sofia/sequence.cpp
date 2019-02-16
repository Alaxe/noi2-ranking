#include <iostream>
using namespace std;

int main () {

ios_base::sync_with_stdio(false);
cin.tie(NULL);
ios_base::sync_with_stdio(false);
cout.tie(NULL);


long long doKoe=1, kolkoPati,
            koeChislo, brPovtoreniq=0, kolkoHoda=0;
cin>>koeChislo>>kolkoPati;
while( brPovtoreniq!=kolkoPati ){
    for( long long i=1; i<doKoe ; i++){
        kolkoHoda++;
     ///   cout<<"WParviqForSum";
    /// cout<<i;
        if( i==koeChislo ){
            brPovtoreniq++;
            if( brPovtoreniq==kolkoPati ){
                cout<< kolkoHoda<<endl;
                return 0;
            }
        }
    }
///cout<<endl<<brPovtoreniq<<endl;
    for( long long i=doKoe; i!=0 ;i-- ){
///            cout<<i;
        kolkoHoda++;
   ///     cout<<"WWtoriqFoeSum";
        if( i==koeChislo ){
            brPovtoreniq++;
            if( brPovtoreniq==kolkoPati ){
                cout<<kolkoHoda<<endl;
                return 0;

            }
        }
    }
///cout<<endl<<brPovtoreniq<<endl;
    doKoe++;
}
cout<<kolkoHoda<<endl;
    return 0;
}
