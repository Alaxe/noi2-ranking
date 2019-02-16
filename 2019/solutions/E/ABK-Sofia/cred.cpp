#include<iostream>
using namespace std;
int main()
{
    long long chislo,pomalko,cifra[10],i2=0,pom,br=0;
    cin>>chislo>>pomalko;
    pom=chislo;
    while(pom<pomalko)
    { chislo=pom;
        for(long long i=0; chislo>0; i++)
        {

            cifra[i2]=chislo%10;
            pom=pom+cifra[i2];
            chislo=chislo/10;
            i2++;
        }
        if(pom<=pomalko){
            br++;

        }


i2=0;
    }
    cout<<br+1;


    return 0;
}

