#include <iostream>
using namespace std;
int main ()
{
    int m,k,memoryk,prch,memory,blizo,kblizo,memblizo;
    cin >>m>>k;
    if (0<k && m<=100000) memoryk =0;
    memory =0;
    blizo =0;
    kblizo =10000;
    while (memory<=k)
    {
        cin >>prch;
        memory++;
        if (m-prch<kblizo && m-prch>0) {kblizo =m-prch;
        blizo =memory;}
       if (prch%2==0) memoryk =memoryk+prch;
    if (memoryk>k || memory==200) cout <<blizo<<" "<<memoryk;}
}
