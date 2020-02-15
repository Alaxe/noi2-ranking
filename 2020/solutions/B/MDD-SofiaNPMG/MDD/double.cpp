#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string symbol;
const int maxn = 200005;

vector<int> indexOfBracketInSymbol; /// ��������� �� ������� � symbol
int indexOfBracketIn_indexOfBracketInSymbol_[maxn];

int corespondingBracket[maxn]; /// ��� �� i ��� ����� � indexOfBracketInSymbol[i]=j, j �� � ������� �� ����������� ���������� ��� �������� �����
stack<int> stackIndexCorespondingBracketCalculate; /// �� �� ��������� ������� �� ��� ������ �� ��������� �� ���� ������ ��������� � ��������
                                             /// push-���� ������ �� �����, ��� counterSpecial �� ���������
                                             /// ��� counterSpecial ��������, ����� �������, ������ ����� ��������, � ��������� ��������� �� ������� � ������, ����� ���� ���-������ �� stak-�
                                             /// �.�. ��� counterSpecial ��������, pop-����

bool thereIsAPlusOrAMinus[maxn]; /// ��� ��� �������������� ����� �� ������� i � j (i<j), �� thereISaPlus[i] = true, ��� ��� + ��� - ����� ������� �� ����� i � j

bool importantSign[maxn]; /// �� ����� ����� �� ������ i, importantSign[i] ������� ������ � ������ ����� �������, ��� �� � ��������, ��� ���� �������, ���� �� � ���������
                          /// importantSign[i] = 0 ��� + , - ��� ����� �� ����� ���
                          /// importantSign[i] = 1 ��� * ��� /
                          /// importantSiqn[i] = 1 ��� - ���� �������� �����

 bool bracketHasToBePrinted[maxn]; /// �����, ����� �� ������ �� ����������

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> symbol;

    indexOfBracketInSymbol.push_back(-1); /// � �������� ���� �� �������� �� �� � ��-������, ��� ������� ������ -1 �����
    indexOfBracketIn_indexOfBracketInSymbol_[-1] = indexOfBracketInSymbol.size() - 1;

    for(int i=0; i<symbol.size(); i++){
        if(stackIndexCorespondingBracketCalculate.size() == 0 & symbol[i] != '(') continue; /// �������� �� � �����, ����� � ����� �������� �����
        else{
            if(symbol[i] == '('){
                indexOfBracketInSymbol.push_back(i);
                indexOfBracketIn_indexOfBracketInSymbol_[i] = indexOfBracketInSymbol.size() - 1;

                stackIndexCorespondingBracketCalculate.push(i);

                if(symbol[i-1] == '*' || symbol[i-1] == '/' || symbol[i-1] == '-'){ /// ����� importantSign[i] �� ������ 0
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

                if(symbol[i+1] == '*' || symbol[i+1] == '/'){ /// ����� importantSign[i] �� ������ 0
                    importantSign[i] = 1;
                }
            }
        }
    }

    for(int i=1; i<indexOfBracketInSymbol.size(); i++){ /// �� i=1, �� �� ��������� -1
        int currentBracket = indexOfBracketInSymbol[i];

        for(int j=indexOfBracketInSymbol[i-1]+1; j<indexOfBracketInSymbol[i]; j++){ /// ��� ������ ������� ����� ������� �������� -1 � ������ - �� �� ���������� ������� �������
            cout << symbol[j];                                        /// ����� ���� ��� ������ �������� ��������� ����� �������, ��� ���� �� ������ �� �� ����������
        }

        if(corespondingBracket[currentBracket] < currentBracket) { /// ����������� ��� ����� ������ �� ����� ��� ���������� ����� �� ���� ������
            if(bracketHasToBePrinted[currentBracket]) cout << ')';
            continue;
        }

        if(importantSign[currentBracket] == 0 & importantSign[corespondingBracket[currentBracket]] == 0 ){ /// ������� �� �� �����, ���� ���� ���� ���� �� �������� �� ����, ���� �� ���������

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
                if(thereIsAPlusOrAMinus[indexOfBracketInSymbol[j]]){ /// ������� �� ����� ����� - �� ������� ���� ��� ������� � ������, ������� ��� �������� �� ����
                    cout << '('; /// �������� ���������� �����
                    bracketHasToBePrinted[corespondingBracket[currentBracket]] = true; /// �����������, �� ����������� ������ �� ���� �����������
                    break;
                }
                if(j == indexOfBracketIn_indexOfBracketInSymbol_[corespondingBracket[currentBracket]]-1){
                    break;
                }
                if(j != i){
                    j = indexOfBracketIn_indexOfBracketInSymbol_[corespondingBracket[indexOfBracketInSymbol[j]]] - 1; /// ���������� ����, ����� � � ��������� �����, ������� � ��� �� �����������
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
        cout << symbol[i]; /// �������� �������, ����� ��-���� �� ������������
    }

    cout << endl;

    return 0;
}

