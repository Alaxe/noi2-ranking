#include<bits/stdc++.h>
using namespace std;
int dates[32][13][3];
int d[2000];
int m[2000];
int y[2000];
string names[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int days[3][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
                 {0,31,29,31,30,31,30,31,31,30,31,30,31},
                 {0,31,28,31,30,31,30,31,31,30,31,30,31}};
void init(){
    int br=2;
    int year=0;
    for(int month=1;month<13;month++){
        for(int day=1;day<=days[year][month];day++){
            dates[day][month][year]=br;
            d[br]=day;
            m[br]=month;
            y[br]=year;
            br++;
        }
    }
    year++;
    for(int month=1;month<13;month++){
        for(int day=1;day<=days[year][month];day++){
            dates[day][month][year]=br;
            d[br]=day;
            m[br]=month;
            y[br]=year;
            br++;
        }
    }
    year++;
    for(int month=1;month<13;month++){
        for(int day=1;day<=days[year][month];day++){
            dates[day][month][year]=br;
            d[br]=day;
            m[br]=month;
            y[br]=year;
            br++;
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int d1,m1,y1,k,ans;
    char a,b;
    cin>>d1>>a>>m1>>b>>y1>>k;
    //d1=31;m1=12;y1=2020;k=45;
    y1-=2019;
    ans=dates[d1][m1][y1];
    if(dates[d[ans]][m[ans]][y[ans]]%7==6)ans+=2;
    if(dates[d[ans]][m[ans]][y[ans]]%7==0)ans++;
    for(int i=0;i<k;i++){
        ans++;
        if(dates[d[ans]][m[ans]][y[ans]]%7==6)ans+=2;
        if(dates[d[ans]][m[ans]][y[ans]]%7==0)ans++;
    }
    //cout<<ans<<endl;
    if(d[ans]<10)cout<<0;
    cout<<d[ans]<<".";
    if(m[ans]<10)cout<<0;
    cout<<m[ans]<<".";
    cout<<y[ans]+2019<<endl;
    return 0;
}
/// 28/2/2019 1
/// 28/2/2020 1

