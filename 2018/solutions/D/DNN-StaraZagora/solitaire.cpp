#include <iostream>
using namespace std;

int main(){

    int N;
    cin>>N;
    char solitaire[N][N], charr;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j=j){
            cin>>charr;
            if ((charr==' ') || (charr=='C') || (charr=='D') || (charr=='H') || (charr=='S')) j=j;
            else {
                solitaire[i][j] = charr;
                j++;
            }
        }
    }
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++){
            cout<<solitaire[i][j]<<endl;
        }
    }
    int current[2] = {N-1, 0}, sum=0;
    switch (solitaire[N-1][0]){
    case 'A': sum+=1; break;
    case 'T': sum+=10; break;
    case 'J': sum+=11; break;
    case 'Q': sum+=12; break;
    case 'K': sum+=13; break;
    default: sum+=solitaire[N-1][0] - '0' + 1; break;
    }
//cout<<sum<<endl;
//cout<<current[0]<<current[1]<<endl;
    int currenttop = 0, currentright=0;
    while ((current[0] != 0) && (current[1] != N-1))
    {
        if ((current[0] != 0) && (current[1] != N-1))
        {
            switch (solitaire[current[0]-1][current[1]]){
            case 'A': currenttop=1; break;
            case 'T': currenttop=10; break;
            case 'J': currenttop=11; break;
            case 'Q': currenttop=12; break;
            case 'K': currenttop=13; break;
            default: currenttop=solitaire[current[0]-1][current[1]] - '0' + 1; break;
            }
            
            switch (solitaire[current[0]][current[1]+1]){
            case 'A': currentright=1; break;
            case 'T': currentright=10; break;
            case 'J': currentright=11; break;
            case 'Q': currentright=12; break;
            case 'K': currentright=13; break;
            default: currentright=solitaire[current[0]][current[1]+1] - '0' + 1; break;
            }
            
            if (currenttop>currentright){
                current[0] -= 1;
                sum+=currenttop;
            }
            
            if (currentright>currenttop){
                current[1] += 1;
                sum+=currentright;
            }
            if (currentright==currenttop){
                if (N-1 - current[1] < 0 + current[0])
                {
                    current[0] -= 1;
                    sum+=currenttop;
                }
                else {
                    current[1] += 1;
                    sum+=currentright;
                }
            }
        }
        else if ((current[0] != 0) && (current[1] == N-1))
        {
            switch (solitaire[current[0]-1][current[1]]){
            case 'A': currenttop=1; break;
            case 'T': currenttop=10; break;
            case 'J': currenttop=11; break;
            case 'Q': currenttop=12; break;
            case 'K': currenttop=13; break;
            default: currenttop=solitaire[current[0]-1][current[1]] - '0' + 1; break;
            }
            
            current[0]++;
            sum+=currenttop;
        }
        else if ((current[0] == 0) && (current[1] != N-1)) {
            switch (solitaire[current[0]][current[1]+1]){
            case 'A': currentright=1; break;
            case 'T': currentright=10; break;
            case 'J': currentright=11; break;
            case 'Q': currentright=12; break;
            case 'K': currentright=13; break;
            default: currentright=solitaire[current[0]][current[1]+1] - '0' + 1; break;
            }
            
            current[1]++;
            sum+=currentright;
        }
    }
    cout<<sum<<endl;
return 0;
}