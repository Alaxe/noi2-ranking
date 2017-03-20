#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int tpr, tlek;
    int pac[360] = {0};
    int pactime[360] = {0};

    while(true)
    {
        int i = 0;
        cin >> tpr >> tlek;
        pac[i] = tpr;
        pactime[i] = tlek;
        i++;
    }

    for(int i = 0; pac[i] != 0; i++)
    {
        int j = i;
        while(pac[j] > pac[j+1])
        {
            swap(pac[j], pac[j+1]);
            swap(pactime[j], pactime[j+1]);
        }
    }

    cout<<endl;
    for(int i = 0; pac[i] != 0; i++)
    {
        cout<<pac[i]<<" "<<pactime[i]<<endl;
    }
}
