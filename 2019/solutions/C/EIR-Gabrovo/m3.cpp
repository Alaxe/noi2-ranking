#include <iostream>
using namespace std;
int sectors, water, waterLeft, a, b, c, d;
void read()
{
    cin>>sectors>>water;
    cin>>a>>b>>c>>d;
}
int tankType()
{
    int sectorV;
    sectorV=4*d;
    if (water>sectorV*sectors) return -1;
    if (water%sectorV==0){
        waterLeft=sectorV;
        return -2;
    }
    waterLeft=water%sectorV;
    return (water/sectorV+1)%4;
}
string to3digit(double in)
{
    string outStr="";
    int outInt;
    outInt=in*10000;
    if (outInt%10>=5) outInt=outInt/10+1;
    else outInt=outInt/10;
    while (outInt>0){
        outStr=(char)(outInt%10+48)+outStr;
        outInt/=10;
    }
    while (outStr.size()<4) outStr+="0";
    return outStr;
}
int main()
{
    int type;
    double sec1, sec2, sec3, sec4;
    read();
    type=tankType();
    if (type==-2){
        sec1=(double)waterLeft/4;
        sec2=sec1;
        sec3=sec1;
        sec4=sec1;
    }
    if (type==-1){
        sec1=(double)water/(sectors*4);
        sec2=sec1;
        sec3=sec1;
        sec4=sec1;
    }
    if (type==1){           ///А
        if (waterLeft<=a){
            sec1=waterLeft;
            sec2=0;
            sec3=0;
            sec4=0;
        }
        else {
            if (waterLeft-a<=a){
                sec1=a;
                sec2=waterLeft-a;
                sec3=0;
                sec4=0;
            }
            else {
                if ((double)waterLeft/2<=c){
                    sec1=(double)waterLeft/2;
                    sec2=sec1;
                    sec3=0;
                    sec4=0;
                }
                else {
                    if (waterLeft-2*c<=b){
                        sec1=c;
                        sec2=c;
                        sec3=waterLeft-2*c;
                        sec4=0;
                    }
                    else {
                        if (waterLeft-2*c-b<=b){
                            sec1=c;
                            sec2=c;
                            sec3=b;
                            sec4=waterLeft-2*c-b;
                        }
                        else {
                            if ((double)(waterLeft-2*c)/2<=c){
                                sec1=c;
                                sec2=c;
                                sec3=(double)(waterLeft-2*c)/2;
                                sec4=sec3;
                            }
                            else {
                                sec1=(double)waterLeft/4;
                                sec2=sec1;
                                sec3=sec1;
                                sec4=sec1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (type==2){           ///Б
        if (waterLeft<=b){
            sec1=waterLeft;
            sec2=0;
            sec3=0;
            sec4=0;
        }
        else {
            if (waterLeft-b<=a){
                sec1=b;
                sec2=waterLeft-b;
                sec3=0;
                sec4=0;
            }
            else {
                if ((double)(waterLeft-b)/2<=b){
                    sec1=b;
                    sec2=(double)(waterLeft-b)/2;
                    sec3=sec2;
                    sec4=0;
                }
                else {
                    if ((double)waterLeft/3<=c){
                        sec1=(double)waterLeft/3;
                        sec2=sec1;
                        sec3=sec1;
                        sec4=0;
                    }
                    else {
                        if (waterLeft-3*c<=c){
                            sec1=c;
                            sec2=c;
                            sec3=c;
                            sec4=waterLeft-3*c;
                        }
                        else {
                            sec1=(double)waterLeft/4;
                            sec2=sec1;
                            sec3=sec1;
                            sec4=sec1;
                        }
                    }
                }
            }
        }
    }
    if (type==3){           ///В
        if (waterLeft<b){
            sec1=waterLeft;
            sec2=0;
            sec3=0;
            sec4=0;
        }
        else {
            if (waterLeft-b<=b){
                sec1=b;
                sec2=waterLeft-b;
                sec3=0;
                sec4=0;
            }
            else {
                if ((double)waterLeft/2<=c){
                    sec1=(double)waterLeft/2<=c;
                    sec2=sec1;
                    sec3=sec1;
                    sec4=sec1;
                }
                else {
                    if (waterLeft-2*c<=a){
                        sec1=c;
                        sec2=c;
                        sec3=waterLeft-2*c;
                        sec4=0;
                    }
                    else {
                        if (waterLeft-2*c-a<=a){
                            sec1=c;
                            sec2=c;
                            sec3=a;
                            sec4=waterLeft-2*c-a;
                        }
                        else {
                            if ((double)(waterLeft-2*c)/2<=c){
                                sec1=c;
                                sec2=c;
                                sec3=(double)(waterLeft-2*c)/2;
                                sec4=sec3;
                            }
                            else {
                                sec1=(double)waterLeft/4;
                                sec2=sec1;
                                sec3=sec1;
                                sec4=sec1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (type==0){           ///Г
        if (waterLeft<=c){
            sec1=waterLeft;
            sec2=0;
            sec3=0;
            sec4=0;
        }
        else {
            if (waterLeft-c<=a){
                sec1=c;
                sec2=waterLeft-c;
                sec3=0;
                sec4=0;
            }
            else {
                if (waterLeft-c-a<=a){
                    sec1=c;
                    sec2=a;
                    sec3=waterLeft-c-a;
                    sec4=0;
                }
                else {
                    if ((double)(waterLeft-c)/2<=b){
                        sec1=c;
                        sec2=(double)(waterLeft-c)/2;
                        sec3=sec2;
                        sec4=0;
                    }
                    else {
                        if (waterLeft-c-2*b<=b){
                            sec1=c;
                            sec2=b;
                            sec3=b;
                            sec4=waterLeft-c-2*b;
                        }
                        else {
                            if ((double)(waterLeft-c)/3<=c){
                                sec1=c;
                                sec2=(double)(waterLeft-c)/3;
                                sec3=sec2;
                                sec4=sec2;
                            }
                            else {
                                sec1=(double)waterLeft/4;
                                sec2=sec1;
                                sec3=sec1;
                                sec4=sec1;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<to3digit(sec1).substr(0, to3digit(sec1).size()-3)<<"."<<to3digit(sec1).substr(to3digit(sec1).size()-3, 3)<<" ";
    cout<<to3digit(sec2).substr(0, to3digit(sec2).size()-3)<<"."<<to3digit(sec2).substr(to3digit(sec2).size()-3, 3)<<" ";
    cout<<to3digit(sec3).substr(0, to3digit(sec3).size()-3)<<"."<<to3digit(sec3).substr(to3digit(sec3).size()-3, 3)<<" ";
    cout<<to3digit(sec4).substr(0, to3digit(sec4).size()-3)<<"."<<to3digit(sec4).substr(to3digit(sec4).size()-3, 3)<<endl;


    return 0;
}
/**
------------------  //type -2
2 32
1 2 3 4
------------------  //type 2
3 25
1 2 3 5
------------------  //type -1
5 100
1 2 3 4
------------------  //type 1
6 75
1 2 3 4
------------------  //type 3
8 105
1 2 3 4
------------------  //type 4
8 123
1 2 3 4
*/
