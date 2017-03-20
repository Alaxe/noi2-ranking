#include<iostream>
#include<cstring>
using namespace std;


int main() {
    ///720 - максималният брой пациенти
    long long broi,zapisvane[720],vreme[720],i;
    cin >>broi;
    for(i=0;i<broi;i++){
        cin >> zapisvane[i] >> vreme[i];
    }

    long long zakusnenie=0;

    for(i=0;i<broi;i++){
        for(long long j=0;j<broi;j++){
            if(zapisvane[i]>zapisvane[j]){
                swap(zapisvane[i],zapisvane[j]);
                swap(vreme[i],vreme[j]);
            }
        }
    }

    for(i=broi-1;i>0;i--){
        if(zapisvane[i]+vreme[i]>zapisvane[i-1]){
            zakusnenie=zapisvane[i]+vreme[i]-zapisvane[i-1];
            zapisvane[i-1]+=zakusnenie;
        }
    }

    cout << zakusnenie+vreme[0] << endl;

    return 0;
}
