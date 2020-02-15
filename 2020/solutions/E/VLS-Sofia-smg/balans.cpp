#include<iostream>
using namespace std;
long long br,otg = 0;
char cv[100005];
int kolkoPuti(char b){
    int ret = 0;
    for(int i = 0; i < br; i++){
        if(cv[i] == b){
            ret++;
        }
    }
    return ret;
}
int main(){
    cin>>br;
    cin>>cv;
    int brA,brB,brC,brD;
    brA = kolkoPuti('a');
    brB = kolkoPuti('b');
    brC = kolkoPuti('c');
    brD = kolkoPuti('d');
    while(brA > 0 && brB > 0 && brC > 0 && brD > 0){
        if(brA + brB == brC + brD){
            cout<<brA + brB + brC + brD<<endl;
            return 0;
        }else{
            if(brA > brC || brA > brD){
                brA--;
            }else if(brB > brC || brB > brD){
                brB--;
            }else if(brC > brA || brC > brB){
                brC--;
            }else if(brD > brA || brD > brB){
                brD--;
            }
        }
    }
    cout<<0;
    return 0;
}
