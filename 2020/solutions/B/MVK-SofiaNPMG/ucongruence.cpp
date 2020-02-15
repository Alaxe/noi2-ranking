#include<iostream>
#include<vector>
using namespace std;

int broiElementiNaRedicata;
int naiGolqmoDopustimoChislo;

int parvonachalnaRedichka[1000010];

int masivZaStroene[1000010];

vector<int> okNeshta[1000010];
int broiOkNeshta;

int kakviSaTeziDveChisla(int a, int b){
    if(a < b){
        return -1;
    }
    if(a == b){
        return 0;
    }
    if(a > b){
        return 1;
    }
}

bool ucongruentniLiSaRedichkite(int vtoraRedichka[1000010]){
    bool ucongLiSa = true;
    for(int i = 0; i < broiElementiNaRedicata; i++){
        for(int j = 0; j < broiElementiNaRedicata; j++){
            if(j != i){
                int chisloZaParvonachalnata = kakviSaTeziDveChisla(parvonachalnaRedichka[i], parvonachalnaRedichka[j]);
                int chisloZaNapravenataRedichka = kakviSaTeziDveChisla(vtoraRedichka[i], vtoraRedichka[j]);
                if(chisloZaNapravenataRedichka != chisloZaParvonachalnata){
                    ucongLiSa = false;
                    break;
                }
            }
        }
        if(ucongLiSa == false){
            break;
        }
    }

    return ucongLiSa;
}

void praveneNaMasivcheto(int naKoiIndexSme){
    if(naKoiIndexSme == broiElementiNaRedicata){
        if(ucongruentniLiSaRedichkite(masivZaStroene) == true){
            for(int i = 0; i < broiElementiNaRedicata; i++){
                okNeshta[broiOkNeshta].push_back(masivZaStroene[i]);
            }
            broiOkNeshta++;
        }

        return;
    }

    for(int i = 1; i <= naiGolqmoDopustimoChislo; i++){
        masivZaStroene[naKoiIndexSme] = i;
        praveneNaMasivcheto(naKoiIndexSme + 1);
    }
}

int main(){
    cin>>broiElementiNaRedicata>>naiGolqmoDopustimoChislo;

    for(int i = 0; i < broiElementiNaRedicata; i++){
        cin>>parvonachalnaRedichka[i];
    }

    praveneNaMasivcheto(0);

    int koiIndex = (broiOkNeshta + 1)/2 - 1;

    for(int i = 0; i < okNeshta[koiIndex].size(); i++){
        cout<<okNeshta[koiIndex][i]<<" ";
    }

    cout<<endl;

    return 0;
}
