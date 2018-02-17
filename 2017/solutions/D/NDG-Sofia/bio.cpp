#include<iostream>
using namespace std;

long long months[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

long long min3(long long a, long long b, long long c){
    long long buff;
    if(b<a){
        a=b;
    }
    if(c<a){
        a=c;
    }
    return a;
}


int main(){
    for(long long i=1; i<12; i++){
        months[i]+=months[i-1];
    }
    long long cday, cmonth;
    long long day[3], month[3];
    long long consts[3]={23, 28, 33};
    for(long long i=0; i<3; i++){
        cin >> day[i];cin.get();cin >> month[i];
        day[i]+=months[month[i]-1];
    }
    cin >> cday;cin.get();cin >> cmonth;
    cday+=months[cmonth-1];
    if(day[0] == day[1] && day[0]==day[2] && cday<day[0]){cout << day[0]-cday; return 0;}
    while(true){
        if(day[0]==day[1] && day[1]==day[2]){break;}
        long long minDay=min3(day[0], day[1], day[2]);
        for(long long i=0; i<3; i++){
            if(day[i]==minDay){day[i]+=consts[i];}
        }
    }
    cout << day[0]-cday;
    return 0;
}
