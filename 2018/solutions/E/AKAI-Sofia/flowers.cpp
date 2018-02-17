#include<iostream>
using namespace std;
int main (){
    int n,postN,q,tallness[10000],tallest=0,broiQTaNuxen=0,broiKapkiNuxen;
    cin>>n;
    postN=n;
    while(postN>0){
        postN--;
        cin>>tallness[postN];}
    cin>>q;
    postN=n;
    tallest=tallness[postN--];
    while(postN>0){
        postN--;
        if(tallest<=tallness[postN]){tallest=tallness[postN];}
    }
    postN=n;
    while(postN>0){
        postN--;
        broiQTaNuxen+=tallest-tallness[postN];}
    broiKapkiNuxen=broiQTaNuxen*q;
    cout<<broiKapkiNuxen<<endl;
    return 0;}
