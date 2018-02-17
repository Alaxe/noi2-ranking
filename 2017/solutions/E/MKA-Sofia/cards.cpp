#include<iostream>
using namespace std;
int main () {
    long long kartoncheta,kdnxskudxkus,kdnxskudxkusb,strani[2][1000],ng,izhod=0,ngb;
    cin>>kartoncheta;
    ng=0;
    for(kdnxskudxkus=0;kdnxskudxkus!=kartoncheta;kdnxskudxkus++){
        cin>>strani[0][kdnxskudxkus]>>strani[1][kdnxskudxkus];
        //cout<<"gggggg ";
    }
    for(kdnxskudxkus=0;kdnxskudxkus!=kartoncheta;kdnxskudxkus++){
        //cout<<"gggggg ";
    for(kdnxskudxkusb=0;kdnxskudxkusb!=kartoncheta;kdnxskudxkusb++){
            //cout<<"gggggg ";
        if(strani[0][kdnxskudxkus]>=ng&&strani[1][kdnxskudxkus]>=ng){
            ng=kdnxskudxkus;
            ngb=ng;
        }
    }
    strani[0][ng]=0;
    strani[1][ng]=0;
    if(ngb==ng){
    izhod=izhod+1;
    }
    ngb=ngb+1;
    }
    cout<<izhod-1;
return 0;
}

