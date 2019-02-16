#include <bits/stdc++.h>
using namespace std;
char chirche;
int days_of_week[32][13][2023];
int d,m,y,prod,day_of_week=1;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool visok(int gdin){
    if(gdin%4==0){
        if(gdin%100==0){
            return false;
        }else{
            return true;
        }
    }
    if(gdin%400==0){
        return true;
    }
    return false;
}
void wek_s(){
    for(int i1=1900;i1<2022;i1++){
        if(visok(i1)){
            days[2]=29;
        }
        for(int i2=1;i2<13;i2++){
            for(int i3=1;i3<=days[i2];i3++){
                days_of_week[i3][i2][i1]=day_of_week;
                day_of_week++;
                if(day_of_week==8){
                    day_of_week=1;
                }
               // cout<<"A";
            }

        }
        days[2]=28;
    }
}
int main(){
    bool m_t=1, d_t=1;
    cin>>d>>chirche>>m>>chirche>>y>>prod;
    wek_s();
    for(int i1=y;;i1++){
        for(int i2=1;i2<12;i2++){
            if(m_t){
                i2=m;
                m_t=0;
            }
            for(int i3=1;i3<=days[i2];i3++){
                if(d_t){
                    i3=d;
                    d_t=0;
                }
                if(days_of_week[i3][i2][i1]==6 or days_of_week[i3][i2][i1]==7){
                    prod++;
                }
                prod--;
                if(prod==0){
                    if(i3<10){
                        cout<<"0";
                    }
                    cout<<i3<<".";
                    if(i2<10){
                        cout<<"0";
                    }
                    cout<<i2<<"."<<i1;
                    break;
                }
            }
        }
    }
    return 0;
}
