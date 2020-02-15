#include <iostream>
#include <cstdio>
using namespace std;

string s;
bool a[30];
int mn[30],mx[30];

int main()
{
int i;
    cin>>s;
    int d = s.size();
    for(i=0;i<d;i++){
        a[s[i]-'A'+1]=1;
    }
    int nom=1;
    for(i=1;i<=26;i++){
        if(a[i] == 1)mn[i]=nom, nom++;
    }
    nom=26;
    for(i=26;i>=1;i--){
        if(a[i] == 1)mx[i]=nom, nom--;
    }
    for(i=0;i<d;i++){
        char c = mn[s[i]-'A'+1] + 'A' - 1;
        //cout<<c;
        printf("%c", c);
    }
    //cout<<endl;
    printf("\n");
    for(i=0;i<d;i++){
        char c = mx[s[i]-'A'+1]+'A'-1;
        //cout<<c;
        printf("%c", c);
    }
    //cout<<endl;
    printf("\n");




    return 0;
}
