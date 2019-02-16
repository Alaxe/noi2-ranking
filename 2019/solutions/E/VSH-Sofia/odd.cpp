#include<iostream>
using namespace std;
int main(){

long long ch1,ch2,poG=0,other=0,iM,mejd[10000],probvanDelitel,broi=0,kolko=0; cin>>ch1>>ch2;
if(ch1>ch2){
        poG=ch1;
      other=ch2;
}else{if(ch2>ch1){poG=ch2;other=ch1;}}

for(iM=other;iM<=poG;iM=iM+1){


for(probvanDelitel=1;probvanDelitel<=iM;probvanDelitel=probvanDelitel+1){

      if(iM%probvanDelitel==0){

broi=broi+1;
      if(probvanDelitel==iM){


if(broi%2==1){
        kolko=kolko+1;
}
broi=0;
      }

}
}
}
cout<<kolko<<endl;
return 0;
}
