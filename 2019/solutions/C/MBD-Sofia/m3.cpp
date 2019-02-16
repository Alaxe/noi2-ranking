#include<iostream>
using namespace std;
int main(){
    long long S,K,kwo;
    int a,b,c,d;
    cin >> S >> K >> a >> b >> c >> d;
    kwo=K%(d*4);
    if(kwo==0){
        cout << d << ".000 " << d << ".000 " << d << ".000 " << d << ".000" << endl;
        return 0;
    }
    if(K/(d*4)>S*4){
        cout << d << ".000 " << d << ".000 " << d << ".000 " << d << ".000" << endl;
        return 0;
    }
    int ws=(K/(d*4)+1)%4;
    if(ws==1){
        if(kwo<=a){
            cout << kwo << ".000 0.000 0.000 0.000" << endl;
        }else if(kwo<=a+a){
            cout << a << ".000 " << kwo-a << ".000 0.000 0.000" << endl;
        }else if(kwo<=c+c){
            if(kwo%2==1){
                cout << kwo/2 << ".500 " << kwo/2 << ".500 0.000 0.000" << endl;
            }else{
                cout << kwo/2 << ".000 " << kwo/2 << ".000 0.000 0.000" << endl;
            }
        }else if(kwo<=2*c+b){
            cout << c << ".000 " << c << ".000 " << kwo-2*c << ".000 0.000" << endl;
        }else if(kwo<=2*(c+b)){
            cout << c << ".000 " << c << ".000 " << b << ".000 " << kwo-2*c-b << ".000" << endl;
        }else if(kwo<=4*c){
            cout << c << ".000 " << c << ".000 ";
            if((kwo-2*c)%2==1){
                cout << (kwo-2*c)/2 << ".500 " << (kwo-2*c)/2 << ".500" << endl;
            }else{
                cout << (kwo-2*c)/2 << ".000 " << (kwo-2*c)/2 << ".000" << endl;
            }
        }else{
            if(kwo%4==1){
                cout << kwo/4 << ".250 " << kwo/4 << ".250 " << kwo/4 << ".250 " << kwo/4 << ".250" << endl;
            }else if(kwo%4==2){
                cout << kwo/4 << ".500 " << kwo/4 << ".500 " << kwo/4 << ".500 " << kwo/4 << ".500" << endl;
            }else if(kwo%4==3){
                cout << kwo/4 << ".750 " << kwo/4 << ".750 " << kwo/4 << ".750 " << kwo/4 << ".750" << endl;
            }else if(kwo%4==0){
                cout << kwo/4 << ".000 " << kwo/4 << ".000 " << kwo/4 << ".000 " << kwo/4 << ".000" << endl;
            }
        }
    }else if(ws==2){
        if(kwo<=b){
            cout << kwo << ".000 0.000 0.000 0.000" << endl;
        }else if(kwo<=b+a){
            cout << b << ".000 " << kwo-b << ".000 0.000 0.000" << endl;
        }else if(kwo<=b+2*a){
            cout << b << ".000 " << a << ".000 " << kwo-b-a << ".000 0.000" << endl;
        }else if(kwo<=b*3){
            cout << b << ".000 ";
            if((kwo-b)%2==1){
                cout << (kwo-b)/2 << ".500 " << (kwo-b)/2 << ".500 0.000" << endl;
            }else{
                cout << (kwo-b)/2 << ".000 " << (kwo-b)/2 << ".000 0.000" << endl;
            }
        }else if(kwo<=3*c){
            if(kwo%3==1){
                cout << kwo/3 << ".333 " << kwo/3 << ".333 " << kwo/3 << ".333 0.000" << endl;
            }else if(kwo%3==2){
                cout << kwo/3 << ".666 " << kwo/3 << ".666 " << kwo/3 << ".666 0.000" << endl;
            }else if(kwo%3==0){
                cout << kwo/3 << ".000 " << kwo/3 << ".000 " << kwo/3 << ".000 0.000" << endl;
            }
        }else if(kwo<=4*c){
            cout << c << ".000 " << c << ".000 " << c << ".000 " << kwo-3*c << ".000" << endl;
        }else{
            if(kwo%4==1){
                cout << kwo/4 << ".250 " << kwo/4 << ".250 " << kwo/4 << ".250 " << kwo/4 << ".250" << endl;
            }else if(kwo%4==2){
                cout << kwo/4 << ".500 " << kwo/4 << ".500 " << kwo/4 << ".500 " << kwo/4 << ".500" << endl;
            }else if(kwo%4==3){
                cout << kwo/4 << ".750 " << kwo/4 << ".750 " << kwo/4 << ".750 " << kwo/4 << ".750" << endl;
            }else if(kwo%4==0){
                cout << kwo/4 << ".000 " << kwo/4 << ".000 " << kwo/4 << ".000 " << kwo/4 << ".000" << endl;
            }
        }
    }else if(ws==3){
        if(kwo<=b){
            cout << kwo << ".000 0.000 0.000 0.000" << endl;
        }else if(kwo<=b+b){
            cout << b << ".000 " << kwo-b << ".000 0.000 0.000" << endl;
        }else if(kwo<=c+c){
            if(kwo%2==1){
                cout << kwo/2 << ".500 " << kwo/2 << ".500 0.000 0.000" << endl;
            }else{
                cout << kwo/2 << ".000 " << kwo/2 << ".000 0.000 0.000" << endl;
            }
        }else if(kwo<=2*c+a){
            cout << c << ".000 " << c << ".000 " << kwo-2*c << ".000 0.000" << endl;
        }else if(kwo<=2*(c+a)){
            cout << c << ".000 " << c << ".000 " << a << ".000 " << kwo-2*c-a << ".000" << endl;
        }else if(kwo<=4*c){
            cout << c << ".000 " << c << ".000 ";
            if((kwo-2*c)%2==1){
                cout << (kwo-2*c)/2 << ".500 " << (kwo-2*c)/2 << ".500" << endl;
            }else{
                cout << (kwo-2*c)/2 << ".000 " << (kwo-2*c)/2 << ".000" << endl;
            }
        }else{
            if(kwo%4==1){
                cout << kwo/4 << ".250 " << kwo/4 << ".250 " << kwo/4 << ".250 " << kwo/4 << ".250" << endl;
            }else if(kwo%4==2){
                cout << kwo/4 << ".500 " << kwo/4 << ".500 " << kwo/4 << ".500 " << kwo/4 << ".500" << endl;
            }else if(kwo%4==3){
                cout << kwo/4 << ".750 " << kwo/4 << ".750 " << kwo/4 << ".750 " << kwo/4 << ".750" << endl;
            }else if(kwo%4==0){
                cout << kwo/4 << ".000 " << kwo/4 << ".000 " << kwo/4 << ".000 " << kwo/4 << ".000" << endl;
            }
        }
    }else{
        if(kwo<=c){
            cout << kwo << ".000 0.000 0.000 0.000" << endl;
        }else if(kwo<=c+a){
            cout << c << ".000 " << kwo-c << ".000 0.000 0.000" << endl;
        }else if(kwo<=c+2*a){
            cout << c << ".000 " << a << ".000 " << kwo-c-a << ".000 0.000"<< endl;
        }else if(kwo<=c+b*2){
            cout << c << ".000 ";
            if((kwo-c)%2==1){
                cout << (kwo-c)/2 << ".500 " << (kwo-c)/2 << ".500 0.000" << endl;
            }else{
                cout << (kwo-c)/2 << ".000 " << (kwo-c)/2 << ".000 0.000" << endl;
            }
        }else if(kwo<=c+3*b){
            cout << c << ".000 " << b << ".000 " << b << ".000 " << kwo-c-2*b << ".000" << endl;
        }else if(kwo<=4*c){
            cout << c << ".000 ";
            if((kwo-c)%3==1){
                cout << (kwo-c)/3 << ".333 " << (kwo-c)/3 << ".333 " << (kwo-c)/3 << ".333" << endl;
            }else if((kwo-c)%3==2){
                cout << (kwo-c)/3 << ".666 " << (kwo-c)/3 << ".666 " << (kwo-c)/3 << ".666" << endl;
            }else if((kwo-c)%3==0){
                cout << (kwo-c)/3 << ".000 " << (kwo-c)/3 << ".000 " << (kwo-c)/3 << ".000" << endl;
            }
        }else{
            if(kwo%4==1){
                cout << kwo/4 << ".250 " << kwo/4 << ".250 " << kwo/4 << ".250 " << kwo/4 << ".250" << endl;
            }else if(kwo%4==2){
                cout << kwo/4 << ".500 " << kwo/4 << ".500 " << kwo/4 << ".500 " << kwo/4 << ".500" << endl;
            }else if(kwo%4==3){
                cout << kwo/4 << ".750 " << kwo/4 << ".750 " << kwo/4 << ".750 " << kwo/4 << ".750" << endl;
            }else if(kwo%4==0){
                cout << kwo/4 << ".000 " << kwo/4 << ".000 " << kwo/4 << ".000 " << kwo/4 << ".000" << endl;
            }
        }
    }
    return 0;
}
