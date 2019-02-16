#include<iostream>
using namespace std;
int kolkoDniImaMeseca2019(int mesec) {
    if (mesec==2) {
        return 28;
    }
    if (mesec<= 7  && mesec%2==0) {
        return 30;
    }
    if (mesec<= 7  && mesec%2==1) {
        return 31;
    }
    if (mesec> 7  && mesec%2==1) {
        return 30;
    }
    if (mesec> 7 && mesec%2==0) {
        return 30;
    }
}
int kolkoDniImaMeseca2020(int mesec) {
    if (mesec==2) {
        return 29;
    }
    if (mesec<= 7  && mesec%2==0) {
        return 30;
    }
    if (mesec<= 7  && mesec%2==1) {
        return 31;
    }
    if (mesec> 7  && mesec%2==1) {
        return 30;
    }
    if (mesec> 7 && mesec%2==0) {
        return 30;
    }
}
int main() {
    string vhod;
    int dni;
    cin >> vhod >> dni;
    int Startday,Startmonth,calender[12][31],denOtSedmicata=1,brDni=0,StartYear;
    if (vhod.size()==10) {
        Startday=(vhod[0]-'0')*10 + (vhod[1]-'0');
        Startmonth=(vhod[3]-'0')*10 + (vhod[4]-'0');
        StartYear=(vhod[6]-'0')*1000 + (vhod[7]-'0')*100 + (vhod[8]-'0')*10 + vhod[9]-'0';
    }
    if (vhod[1]=='/' && vhod.size()== 9) {
        Startday=vhod[0]-'0';
        Startmonth=(vhod[2]-'0')*10 + (vhod[3]-'0');
        StartYear=(vhod[5]-'0')*1000 + (vhod[6]-'0')*100 + (vhod[7]-'0')*10 + vhod[8]-'0';

    }
    if (vhod[2]=='/' && vhod.size()== 9) {
        Startday=(vhod[0]-'0')*10 + (vhod[1]-'0');
        Startmonth=vhod[3]-'0';
        StartYear=(vhod[5]-'0')*1000 + (vhod[6]-'0')*100 + (vhod[7]-'0')*10 + vhod[8]-'0';
    }
    if (vhod.size()== 8) {
        Startday=vhod[0]-'0';
        Startmonth=vhod[2]-'0';
        StartYear=(vhod[4]-'0')*1000 + (vhod[5]-'0')*100 + (vhod[6]-'0')*10 + vhod[7]-'0';

    }

    for (int i=0; i<12; i++) {
        for (int j = 0; j < 31; j++) {
            calender[i][j]=-1;
        }
    }
    if (StartYear==2019) {
        for (int i = 0; i < 31; i++) {
            calender[0][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }

        for (int i = 0; i < 28; i++) {
            calender[1][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[2][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 30; i++) {
            calender[3][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[4][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 30; i++) {
            calender[5][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[6][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[7][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 30; i++) {
            calender[8][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[9][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 30; i++) {
            calender[10][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[11][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        while (brDni <dni) {
            for (int i=Startday+1; i <= kolkoDniImaMeseca2019(Startmonth); i++) {
                if (calender[Startmonth-1][i-1]<5) {
                    brDni++;
                    if (brDni==dni) {
                        if (Startmonth<10 && i< 10) {
                            cout << "0" << i  << "." << "0" << Startmonth << "." << 2019;
                            return 0;
                        }
                        if (i< 10) {
                            cout << "0" << i << "." << Startmonth << "." << 2019;
                            return 0;
                        }
                        if (Startmonth<10) {
                            cout << i  << "." << "0" << Startmonth << "." << 2019;
                            return 0;
                        }


                        cout << i << "." << Startmonth<< "." << 2019;
                        return 0;
                    }

                }
            }
            Startday=0;
            Startmonth++;

        }
        cout << Startday << "." << Startmonth << "." << 2019;
        return 0;
    }
    else {
        denOtSedmicata=2;
         for (int i = 0; i < 31; i++) {
            calender[0][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }

        for (int i = 0; i < 28; i++) {
            calender[1][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[2][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 30; i++) {
            calender[3][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[4][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 30; i++) {
            calender[5][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[6][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[7][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 30; i++) {
            calender[8][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[9][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 30; i++) {
            calender[10][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        for (int i = 0; i < 31; i++) {
            calender[11][i]=denOtSedmicata;
            if (denOtSedmicata==6) {
                denOtSedmicata=0;
            } else {
                denOtSedmicata++;
            }
        }
        while (brDni <dni) {
            for (int i=Startday+1; i <= kolkoDniImaMeseca2020(Startmonth); i++) {
                if (calender[Startmonth-1][i-1]<5) {
                    brDni++;
                    if (brDni==dni) {
                        if (Startmonth<10 && i< 10) {
                            cout << "0" << i  << "." << "0" << Startmonth << "." << 2020;
                            return 0;
                        }
                        if (i< 10) {
                            cout << "0" << i << "." << Startmonth << "." << 2020;
                            return 0;
                        }
                        if (Startmonth<10) {
                            cout << i  << "." << "0" << Startmonth << "." << 2020;
                            return 0;
                        }

                        cout << i << "." << Startmonth << "." << 2020;
                        return 0;
                    }

                }
            }
            Startday=0;
            Startmonth++;
        }
        cout << Startday << "." << Startmonth << "." << 2020;
        return 0;
    }
}
