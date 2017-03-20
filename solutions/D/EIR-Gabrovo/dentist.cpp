#include <iostream>
#include <algorithm>
using namespace std;
struct chovek{
    int chas;
    int vreme;
};
bool cmp(chovek a, chovek b)
{
    if (b.chas>a.chas) return true;
    return false;
}
int main()
{
    int n=4, wait=0, neshto;
    chovek hora[100];
    for (int i=0; i<n; i++){
        cin>>hora[i].chas>>hora[i].vreme;
    }
    sort(hora, hora+n, cmp);
    for (int i=0; i<n-1; i++){
        wait+=hora[i].vreme-(hora[i+1].chas-hora[i].chas);
        if (wait<0) wait=0;
    }
    wait+=hora[n-1].vreme;
    cout<<wait<<endl;
    /*for (int i=0; i<n; i++){
        cout<<hora[i].chas<<" "<<hora[i].vreme<<endl;
    }*/

    return 0;
}
