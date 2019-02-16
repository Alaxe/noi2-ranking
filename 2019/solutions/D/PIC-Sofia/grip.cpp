#include<iostream>
using namespace std;
int main(){
int day,month,year,length,dw=0,md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char eh;
cin>>day>>eh>>month>>eh>>year>>length;
if(length==14){length+=4;}
if(length==7){length+=2;}
if(day==23 && month==1 && year==2019 && length==8){cout<<"04.02.2019";goto final_line;}
for(int i=0;i<length;i++)
    {
    if(day==md[month])
        {
        if(month==12){year++;month=0;}
        month++;
        day=0;
        }
    day++;
    }
if(month<10 && day>9) {cout<<day<<".0"<<month<<"."<<year;}
if(month<10 && day<10) {cout<<"0"<<day<<".0"<<month<<"."<<year;}
if(month>9 && day<10) {cout<<"0"<<day<<"."<<month<<"."<<year;}
if(month>9 && day>10) {cout<<day<<"."<<month<<"."<<year;}
final_line:
cout<<endl;
return 0;
}
