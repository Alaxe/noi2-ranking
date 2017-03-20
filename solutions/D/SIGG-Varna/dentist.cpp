#include <iostream>
#include <algorithm>
using namespace std;

struct Dentist{

    int pristig;
    int lek;

};

bool cmp (Dentist a, Dentist b){
    return a.pristig < b.pristig;
}

int main (){

    Dentist dentist[1000] = {0};
    int i = 0, sum = 0;
    bool flag = false;
    while (cin){
        cin >> dentist[i].pristig;
        cin >> dentist[i].lek;
        ++i;
    }

    sort (dentist, dentist + i - 1, cmp);

    for (int j = 0; j < i - 1; ++j){

        if (dentist[j].pristig + dentist[j].lek < dentist[j + 1].pristig)
            sum = dentist[j + 1].pristig;

    }

    for (int j = 0; j < i - 1; ++j){

        if (dentist[j].pristig + dentist[j].lek > dentist[j+1].pristig){
            sum = dentist[j].lek + sum;
            flag = true;
        }

    }

    if (flag == true)
        cout << sum - dentist[i-2].pristig << endl;
    else
        cout << dentist[i-2].lek << endl;



    return 0;
}
