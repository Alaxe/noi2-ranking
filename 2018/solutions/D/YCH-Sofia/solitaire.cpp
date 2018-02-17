#include<iostream>
using namespace std;
int main(){
    int N,br=0,s,d;
    cin>>N;
    char mas[N][N];
    long long mas2[N][N];
    s=N-1;
    d=0;
    for(int i=0;i<N;i++){
        for(int q=0;q<N;q++){
            char a;
            cin>>mas[i][q]>>a;
             if(mas[i][q]=='A'){
            mas2[i][q]=1;
        }else{
            if(mas[i][q]=='2'){
            mas2[i][q]=2;
        }else{
            if(mas[i][q]=='3'){
            mas2[i][q]=3;
        }else{
            if(mas[i][q]=='4'){
            mas2[i][q]=4;
        }else{
            if(mas[i][q]=='5'){
            mas2[i][q]=5;
        }else{
            if(mas[i][q]=='6'){
            mas2[i][q]=6;
        }else{
            if(mas[i][q]=='7'){
            mas2[i][q]=7;
        }else{
            if(mas[i][q]=='8'){
            mas2[i][q]=8;
        }else{
            if(mas[i][q]=='9'){
            mas2[i][q]=9;
        }else{
            if(mas[i][q]=='T'){
            mas2[i][q]=10;
        }else{
            if(mas[i][q]=='J'){
            mas2[i][q]=11;
        }else{
            if(mas[i][q]=='Q'){
            mas2[i][q]=12;
        }else{
            if(mas[i][q]=='K'){
            mas2[i][q]=13;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
    }
br=mas2[N-1][0];
        for(int i=0;i<(2*N)-3;i++){
                //cout<<s<<" "<<d<<endl;
        //cout<<br<<endl;
            if(mas2[s-1][d]>=mas2[s][d+1]){
                br+=mas2[s-1][d];
                s--;
            }else{
                br+=mas2[s][d+1];
                d++;
            }
        }
cout<<br+mas2[0][N-1];
return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/

