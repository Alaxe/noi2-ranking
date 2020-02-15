#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string symbol;
const int maxn = 200005;

vector<int> indexOfBracketInSymbol; /// Индексите на скобите в symbol
int indexOfBracketIn_indexOfBracketInSymbol_[maxn];

int corespondingBracket[maxn]; /// Ако на i има скоба и indexOfBracketInSymbol[i]=j, j ще е индекса на съответната затварящща или отваряща скоба
stack<int> stackIndexCorespondingBracketCalculate; /// За да определим скобите на кои индкси са съответно от една двойка затваряща и отваряща
                                             /// push-ваме индекс на скоба, ако counterSpecial се увеличава
                                             /// Ако counterSpecial намалява, значи скобата, заради която намалява, е съответна затваряща на скобата с индекс, която седи най-отгоре на stak-а
                                             /// т.е. Ако counterSpecial намалява, pop-ваме

bool thereIsAPlusOrAMinus[maxn]; /// Ако има последователни скоби на индекси i и j (i<j), то thereISaPlus[i] = true, ако има + или - между скобите на места i и j

bool importantSign[maxn]; /// За всяка скоба на индекс i, importantSign[i] показва каквъв е знакът преди скобата, ако тя е отваряща, или след скобата, акот тя е затваряща
                          /// importantSign[i] = 0 при + , - или скоба от същия вид
                          /// importantSign[i] = 1 при * или /
                          /// importantSiqn[i] = 1 при - пред отваряща скоба

 bool bracketHasToBePrinted[maxn]; /// скоби, които ще трябва да изпечатаме

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> symbol;

    indexOfBracketInSymbol.push_back(-1); /// в крайната част на задачата ще ни е по-удобно, ако условно сложим -1 вътре
    indexOfBracketIn_indexOfBracketInSymbol_[-1] = indexOfBracketInSymbol.size() - 1;

    for(int i=0; i<symbol.size(); i++){
        if(stackIndexCorespondingBracketCalculate.size() == 0 & symbol[i] != '(') continue; /// Намираме се в място, което е извън всякакви скоби
        else{
            if(symbol[i] == '('){
                indexOfBracketInSymbol.push_back(i);
                indexOfBracketIn_indexOfBracketInSymbol_[i] = indexOfBracketInSymbol.size() - 1;

                stackIndexCorespondingBracketCalculate.push(i);

                if(symbol[i-1] == '*' || symbol[i-1] == '/' || symbol[i-1] == '-'){ /// иначе importantSign[i] си остава 0
                    importantSign[i] = 1;
                }
            }
            if(symbol[i] == '+' || symbol[i] == '-'){
                int previousBracket = indexOfBracketInSymbol[indexOfBracketInSymbol.size()-1];
                thereIsAPlusOrAMinus[previousBracket] = true;
            }
            if(symbol[i] == ')'){
                indexOfBracketInSymbol.push_back(i);
                indexOfBracketIn_indexOfBracketInSymbol_[i] = indexOfBracketInSymbol.size() -1;

                int CurrentCorespondingBracket = stackIndexCorespondingBracketCalculate.top();
                stackIndexCorespondingBracketCalculate.pop();

                corespondingBracket[i] = CurrentCorespondingBracket;
                corespondingBracket[CurrentCorespondingBracket] = i;

                if(symbol[i+1] == '*' || symbol[i+1] == '/'){ /// иначе importantSign[i] си остава 0
                    importantSign[i] = 1;
                }
            }
        }
    }

    for(int i=1; i<indexOfBracketInSymbol.size(); i++){ /// от i=1, за да прескочим -1
        int currentBracket = indexOfBracketInSymbol[i];

        for(int j=indexOfBracketInSymbol[i-1]+1; j<indexOfBracketInSymbol[i]; j++){ /// тук заради първата скоба условно сложихме -1 в масива - за да разпечатам първите символи
            cout << symbol[j];                                        /// всеки друг път просто печатаме символите между скобите, тъй като те трябва да се разпечатат
        }

        if(corespondingBracket[currentBracket] < currentBracket) { /// пресметнали сме какво трябва да стане при отварящата скоба от тази двойка
            if(bracketHasToBePrinted[currentBracket]) cout << ')';
            continue;
        }

        if(importantSign[currentBracket] == 0 & importantSign[corespondingBracket[currentBracket]] == 0 ){ /// скобите не са нужни, след като нито общо са умножени по нещо, нито са разделени

        }
        else{
            int j = i;
            int upperBound = i;
            while(indexOfBracketIn_indexOfBracketInSymbol_[corespondingBracket[indexOfBracketInSymbol[j+1]]] == indexOfBracketIn_indexOfBracketInSymbol_[corespondingBracket[indexOfBracketInSymbol[upperBound]]] - 1){
                if(i==1) cout << "hi" << endl;
                j++;
                upperBound--;
            }
            for(j; indexOfBracketInSymbol[j]<corespondingBracket[indexOfBracketInSymbol[upperBound]]; j++){
                if(thereIsAPlusOrAMinus[indexOfBracketInSymbol[j]]){ /// скобите ще бъдат нужни - ще имамаме сбор или разлика в скобни, умножен или разделен на нещо
                    cout << '('; /// печатаме отварящата скоба
                    bracketHasToBePrinted[corespondingBracket[currentBracket]] = true; /// отбелязваме, че затварящата трябва да бъде разпечатана
                    break;
                }
                if(j == indexOfBracketIn_indexOfBracketInSymbol_[corespondingBracket[currentBracket]]-1){
                    break;
                }
                if(j != i){
                    j = indexOfBracketIn_indexOfBracketInSymbol_[corespondingBracket[indexOfBracketInSymbol[j]]] - 1; /// прескачаме това, което е в двйоиката скоби, знаците в там ни интересуват
                }
                else{
                    if(indexOfBracketInSymbol[j+1]!=0){
                        j = indexOfBracketIn_indexOfBracketInSymbol_[corespondingBracket[indexOfBracketInSymbol[j+1]]] - 1;
                    }
                }
            }
        }
    }

    for(int i = indexOfBracketInSymbol[indexOfBracketInSymbol.size()-1] + 1; i<symbol.size(); i++){
        cout << symbol[i]; /// крайните симболи, които по-горе не разпечатахме
    }

    cout << endl;

    return 0;
}

