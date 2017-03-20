#include<iostream>
using namespace std;

int main(){

string s;

cin>>s;

int sSize=s.size();
int i=0;
int checker=0;
int adder=1;
int br=0;

while(i!=sSize){
i+=adder;
br++;
checker++;
if(checker%3==0){
    adder++;
}
}
cout<<br<<endl;
return 0;
}

