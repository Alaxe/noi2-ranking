#include<iostream>
using namespace std;

int broiPredmeti;
int capacitetParvi;
int capacitetVtori;
int predmeti[205];

int priTolkova[205][205][205];

void nuliraneNaRekursivnoto(){
    for(int i = 0; i <= broiPredmeti; i++){
        for(int j = 0; j <= capacitetParvi; j++){
            for(int k = 0; k <= capacitetVtori; k++){
                priTolkova[i][j][k] = -1;
            }
        }
    }
}
int maksimalnoTegloKoetoMozhemDaVzemem(int indexNaKoitoSme, int mqstoVParviq, int mqstoVavVtoriq){
    if(mqstoVParviq < 0 || mqstoVavVtoriq < 0){
        return -300000;
    }
    if(indexNaKoitoSme == 0){
        return 0;
    }

    if(priTolkova[indexNaKoitoSme][mqstoVParviq][mqstoVavVtoriq] > -1){
        return priTolkova[indexNaKoitoSme][mqstoVParviq][mqstoVavVtoriq];
    }

    int akoToziNeGoVzemem = maksimalnoTegloKoetoMozhemDaVzemem(indexNaKoitoSme - 1, mqstoVParviq, mqstoVavVtoriq);
    int akoToziGoSlozhimvParviq = predmeti[indexNaKoitoSme] +
        maksimalnoTegloKoetoMozhemDaVzemem(indexNaKoitoSme - 1, mqstoVParviq - predmeti[indexNaKoitoSme], mqstoVavVtoriq);
    int akoToziGoSlozhimVavVtoriq = predmeti[indexNaKoitoSme] +
        maksimalnoTegloKoetoMozhemDaVzemem(indexNaKoitoSme - 1, mqstoVParviq, mqstoVavVtoriq - predmeti[indexNaKoitoSme]);

    int naiDobrotoTegloTuk = max(akoToziNeGoVzemem, max(akoToziGoSlozhimvParviq, akoToziGoSlozhimVavVtoriq));

    priTolkova[indexNaKoitoSme][mqstoVParviq][mqstoVavVtoriq] = naiDobrotoTegloTuk;
    return naiDobrotoTegloTuk;
}

int maksimalTegloPriTolkova[205][205][205];

int maxTeglo(int koiIndex, int tegloNaParviq, int tegloNaVtoriq){
    for(int i = 1; i <= koiIndex; i++){
        for(int j = 0; j <= tegloNaParviq; j++){
            for(int k = 0; k <= tegloNaVtoriq; k++){

                int akoNeGoVzemem = maksimalTegloPriTolkova[i - 1][j][k];
                int akoGoVzememVParviqKonteiner = 0;
                int akoGoVzememVavVtoriqKonteiner = 0;
                if(j - predmeti[i] >= 0){
                    akoGoVzememVParviqKonteiner = predmeti[i] + maksimalTegloPriTolkova[i - 1][j - predmeti[i]][k];
                }
                if(k - predmeti[i] >= 0){
                    akoGoVzememVavVtoriqKonteiner = predmeti[i] + maksimalTegloPriTolkova[i - 1][j][k - predmeti[i]];
                }

                int naiDobrotoTuk = max(akoNeGoVzemem, max(akoGoVzememVParviqKonteiner, akoGoVzememVavVtoriqKonteiner));

                maksimalTegloPriTolkova[i][j][k] = naiDobrotoTuk;
            }
        }
    }

    return maksimalTegloPriTolkova[koiIndex][tegloNaParviq][tegloNaVtoriq];
}

int main(){
    cin>>broiPredmeti>>capacitetParvi>>capacitetVtori;

    for(int i = 1; i <= broiPredmeti; i++){
        cin>>predmeti[i];
    }

    //nuliraneNaRekursivnoto();

    //int naiDobroTeglo = maksimalnoTegloKoetoMozhemDaVzemem(broiPredmeti, capacitetParvi, capacitetVtori);

    int naiDobroTeglo = maxTeglo(broiPredmeti, capacitetParvi, capacitetVtori);

    cout<<naiDobroTeglo<<endl;

    return 0;
}
