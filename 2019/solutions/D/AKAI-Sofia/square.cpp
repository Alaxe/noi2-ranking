#include<bits//stdc++.h>
using namespace std;
int main (){
  int deliteli[13],polzvaneNaDelitel[42],naiIzpolzvanDelitel=0;
  long long izhod=1;
  bool delenie=0;
  deliteli[0]=2;
  deliteli[1]=3;
  deliteli[2]=5;
  deliteli[3]=7;
  deliteli[4]=11;
  deliteli[5]=13;
  deliteli[6]=17;
  deliteli[7]=19;
  deliteli[8]=23;
  deliteli[9]=29;
  deliteli[10]=31;
  deliteli[11]=37;
  deliteli[12]=41;
  for(int i=-1;i<12;){
    i++;
    polzvaneNaDelitel[deliteli[i]]=0;}
  int n;
  cin>>n;
  int chislo[n+1];
  for(int i=-1;i<n-1;){
    i++;
    cin>>chislo[i];}
  for(int m=-1;m<12;){
    m++;
    delenie=0;
    for(int i=-1;i<n-1;){
      i++;
      if(chislo[i]%deliteli[m]==0){delenie=1;chislo[i]/=deliteli[m];}
    }
    if(delenie==1){
      polzvaneNaDelitel[deliteli[m]]++;
      m--;}
  }
  for(int i=-1;i<12;){
    i++;
    if(naiIzpolzvanDelitel<polzvaneNaDelitel[deliteli[i]]){naiIzpolzvanDelitel=polzvaneNaDelitel[deliteli[i]];}
  }
  if(naiIzpolzvanDelitel%2!=0){naiIzpolzvanDelitel++;}
  naiIzpolzvanDelitel/=2;
  for(int i=-1;i<12;){
    i++;
    if(polzvaneNaDelitel[deliteli[i]]!=0){
      for(int m=0;m<naiIzpolzvanDelitel;){
        m++;
        izhod*=deliteli[i];
      }
    }
  }
  cout<<izhod;
  return 0;}
