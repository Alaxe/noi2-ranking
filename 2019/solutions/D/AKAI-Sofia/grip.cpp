#include<bits//stdc++.h>
using namespace std;
int main (){
  int dd,mm,yyyy,schoolDays,differenceInDays,smh=0;
  char smth;
  cin>>dd>>smth>>mm>>smth>>yyyy>>schoolDays;
  for(int i=schoolDays;i>0;){
    dd++;
    differenceInDays=(yyyy-2019)*365;
    if(dd==29&&mm==2||mm==3){differenceInDays+=1;}
    differenceInDays+=dd-5;
    for(int mm2=mm-1;mm2>=1;){
      if(mm2==11||mm2==9||mm2==6||mm2==4){differenceInDays+=30;}
      else{
          if(mm2==2){differenceInDays+=28;}
          else{differenceInDays+=31;}
      }
      mm2--;
    }
    if(differenceInDays%7!=0&&differenceInDays%7!=1){
      i--;
    }
    if(mm==11||mm==9||mm==6||mm==4){if(dd>30){dd=1;mm+=1;}}
    else{
        if(mm==2){
          if(yyyy==2020){
            if(dd>29){dd=1;mm+=1;}
          }
          else{
            if(dd>28){dd=1;mm+=1;}
          }
        }
        else{if(dd>31){dd=1;mm+=1;}}
    }
    if(mm>12){mm=1;yyyy++;}
  }
  if(differenceInDays%7==6){
      dd+=3;
  }
  if(mm==11||mm==9||mm==6||mm==4){if(dd>30){dd=1;mm+=1;}}
  else{
    if(mm==2){
      if(yyyy==2020){
        if(dd>29){dd=1;mm+=1;}
      }
      else{
        if(dd>28){dd=1;mm+=1;}
      }
    }
    else{if(dd>31){dd=1;mm+=1;}}
  }
  if(mm>12){mm=1;yyyy++;}
  if(dd<10){cout<<"0"<<dd<<".";}
  else{cout<<dd<<".";}
  if(mm<10){cout<<"0"<<mm<<".";}
  else{cout<<mm<<".";}
  cout<<yyyy<<endl;
  return 0;}
