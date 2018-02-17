#include <iostream>
#include <cmath>
using namespace std;

int daysfromstart(int dd, int mm) {
    int days=0, i;
    for(i=1;i<mm;i++){
        if (i==2) {days+=28;}
        else {
            if (i==4 || i==6 || i==9 || i==11) {days+=30;}
            else {days+=31;}
        }
    }
    days+=dd;
    return days;
}

int date(int days){
    int i, date;
    for (i=0;days>27;i++){
        if(i==2){days-=28;}
        else {
            if (i==4 || i==6 || i==9 || i==11) {
                if (days>29) {days-=30;}
                else {break;}
            }
            else {
                if (days>30) {days-=31;}
                else {break;}
            }
        }
    }

    date=days*100+i+101;
    return date;
}

int triplemax(int day[]){
    int i, r0, r1, r2;

    for(i=23;abs(day[0]-day[1])>10;i=23) {
        if(day[0]>day[1]) {day[0]-=23;}
        else {day[1]-=23;}
    }
    for(i=23;abs(day[1]-day[2])>10;i=23) {
        if(day[1]>day[2]) {day[1]-=23;}
        else {day[2]-=23;}
    }
    for(i=23;abs(day[0]-day[2])>10;i=23) {
        if(day[0]>day[2]) {day[0]-=23;}
        else {day[2]-=23;}
    }

    for(i=0;day[0]!=day[1] || day[1]!=day[2] || day[0]!=day[2];i++){
        day[0]+=23;
        day[1]+=28;
        day[2]+=33;
    }

    return day[0];
}


int main(){
    int dd[5], mm[5], i, r[2], re, trim, day[3];
    char line;
    for (i=0;i<4;i++) {
        cin >> dd[i] >> line >> mm[i];
    }

    day[0]=daysfromstart(dd[0],mm[0]);
    day[1]=daysfromstart(dd[1],mm[1]);
    day[2]=daysfromstart(dd[2],mm[2]);
    trim=triplemax(day);
    trim=date(trim);
    dd[5]=trim/100;
    mm[5]=trim%100;

    r[0]=daysfromstart(dd[3],mm[3]);
    r[1]=daysfromstart(dd[5],mm[5]);
    if (r[0]>r[1]) {re=r[1]+21252-r[0];}
    else {
        if (r[0]==r[1]) {re=21252;}
        else {re=r[0]-r[1];}
    }

    cout << re << endl;
    return 0;
}
