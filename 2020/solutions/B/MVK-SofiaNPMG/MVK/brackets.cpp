#include<iostream>
#include<string>
using namespace std;

string izraz;

int naTaziSkobaKadeIESaotvetstvashatata[200010];

int main(){
    cin>>izraz;

    for(int i = 0; i < izraz.size(); i++){
        if(izraz[i] == '('){
            int broiOtvoreni = 1;
            for(int j = i + 1; j < izraz.size() + 1; j++){
                if(broiOtvoreni == 0){
                    naTaziSkobaKadeIESaotvetstvashatata[i] = j - 1;
                    naTaziSkobaKadeIESaotvetstvashatata[j - 1] = i;
                    break;
                }

                if(izraz[j] == '('){
                    broiOtvoreni++;
                }
                if(izraz[j] == ')'){
                    broiOtvoreni--;
                }
            }
        }else{
            if(izraz[i] != ')'){
                naTaziSkobaKadeIESaotvetstvashatata[i] = -1;
            }
        }
    }

    for(int i = 0; i < izraz.size(); i++){
        if(izraz[i] == '('){
            int broiIta = 0;
            int broiSkobi = 0;
            for(int j = i; j <= naTaziSkobaKadeIESaotvetstvashatata[i]; j++){
                if(izraz[j] == '(' || izraz[j] == ')'){
                    broiSkobi++;
                }
                if(izraz[j] == '&'){
                    broiIta++;
                }
            }
            if(broiSkobi > broiIta){
                izraz[i] = 0;
                izraz[naTaziSkobaKadeIESaotvetstvashatata[i]] = 0;
            }
        }
    }

    for(int i = 0; i < izraz.size(); i++){
        if(izraz[i] == '('){
            char predSkobata = 0;
            char sledSkobata = 0;
            for(int k = i - 1; k >= 0; k--){
                if(izraz[k] != 0 && izraz[k] != '(' && izraz[k] != ')'){
                    predSkobata = izraz[k];
                    break;
                }
            }
            for(int k = naTaziSkobaKadeIESaotvetstvashatata[i]; k < izraz.size(); k++){
                if(izraz[k] != 0 && izraz[k] != '(' && izraz[k] != ')'){
                    sledSkobata = izraz[k];
                    break;
                }
            }

            if((predSkobata == '+' || predSkobata == 0) && sledSkobata != '*' && sledSkobata != '/'){
                izraz[i] = 0;
                izraz[naTaziSkobaKadeIESaotvetstvashatata[i]] = 0;
            }
        }
    }

    for(int i = 0; i < izraz.size(); i++){
        if(izraz[i] == '('){
            bool samoPlusoveLiSa = true;
            bool samoMinusiLiSa = true;
            bool samoPotaLiSa = true;
            bool samoDeleniqLiSa = true;
            for(int j = i + 1; j < naTaziSkobaKadeIESaotvetstvashatata[i]; j++){
                if(izraz[j] == '(' || izraz[j] == ')'){
                    samoPlusoveLiSa = false;
                    samoMinusiLiSa = false;
                    samoPotaLiSa = false;
                    samoDeleniqLiSa = false;
                    break;
                }
                if(izraz[j] != '&'){
                    if(izraz[j] != '+'){
                        samoPlusoveLiSa = false;
                    }
                    if(izraz[j] != '-'){
                        samoMinusiLiSa = false;
                    }
                    if(izraz[j] != '*'){
                        samoPotaLiSa = false;
                    }
                    if(izraz[j] != '/'){
                        samoDeleniqLiSa = false;
                    }
                }
            }

            if(samoDeleniqLiSa || samoPotaLiSa){
                izraz[i] = 0;
                izraz[naTaziSkobaKadeIESaotvetstvashatata[i]] = 0;
            }

            if(samoPlusoveLiSa){
                char predSkobata = 0;
                char sledSkobata = 0;
                for(int k = i - 1; k >= 0; k--){
                    if(izraz[k] != 0 && izraz[k] != '(' && izraz[k] != ')'){
                        predSkobata = izraz[k];
                        break;
                    }
                }
                for(int k = naTaziSkobaKadeIESaotvetstvashatata[i]; k < izraz.size(); k++){
                    if(izraz[k] != 0 && izraz[k] != '(' && izraz[k] != ')'){
                        sledSkobata = izraz[k];
                        break;
                    }
                }

                if((predSkobata == '+' || predSkobata == 0) && sledSkobata != '*' && sledSkobata != '/'){
                    izraz[i] = 0;
                    izraz[naTaziSkobaKadeIESaotvetstvashatata[i]] = 0;
                }
            }

            if(samoMinusiLiSa){
                char predSkobata = 0;
                char sledSkobata = 0;
                for(int k = i - 1; k >= 0; k--){
                    if(izraz[k] != 0 && izraz[k] != '(' && izraz[k] != ')'){
                        predSkobata = izraz[k];
                        break;
                    }
                }
                for(int k = naTaziSkobaKadeIESaotvetstvashatata[i]; k < izraz.size(); k++){
                    if(izraz[k] != 0 && izraz[k] != '(' && izraz[k] != ')'){
                        sledSkobata = izraz[k];
                        break;
                    }
                }

                if((predSkobata == '+' || predSkobata == 0) && sledSkobata != '*' && sledSkobata != '/'){
                    izraz[i] = 0;
                    izraz[naTaziSkobaKadeIESaotvetstvashatata[i]] = 0;
                }
            }
        }
    }

    for(int i = 0; i < izraz.size(); i++){
        if(izraz[i] != 0){
            cout<<izraz[i];
        }
    }

    return 0;
}
