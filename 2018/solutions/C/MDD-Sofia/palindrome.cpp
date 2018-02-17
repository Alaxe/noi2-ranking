#include <iostream>
#include <string>

using namespace std;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    bool gotSmaller =false;
    bool isthesame =true;
    if(s.size()%2==0){
        for(int i=0; i<((s.size()-1)/2); i++){
            if(s[i]>s[s.size()-1-i]){
               gotSmaller  = false;
               isthesame =false;
            }
            if(s[i]<s[s.size()-1-i]){
                gotSmaller  = true;
                isthesame =false;
            }
            s[s.size()-1-i]= s[i];
        }
        if(s[s.size()/2-1]!=s[s.size()/2]){
            isthesame = false;
            int first=s[s.size()/2-1]-'0';
            int second=s[s.size()/2]-'0';
            s[s.size()/2-1]= max(first, second)+'0';
            s[s.size()/2] = max(first, second)+'0';
        }
        else{
            if(gotSmaller || isthesame){
                int first=s[s.size()/2-1]-'0';
                if(first==9){
                    first =0;
                    int k = s[s.size()/2-2] - '0';
                    k++;
                    s[s.size()/2-2]=k+'0';

                    k = s[s.size()/2+1] - '0';
                    k++;
                    s[s.size()/2+1]=k+'0';

                    s[s.size()/2] = first+'0';
                    s[s.size()/2-1]= first+'0';
                }
                else{
                    s[s.size()/2] = first+1+'0';
                    s[s.size()/2-1]= first+1+'0';
                }
            }
        }
    }
    else{
        for(int i=0; i<((s.size()-1)/2); i++){
            if(s[i]>s[s.size()-1-i]){
               gotSmaller  = false;
               isthesame= false;
            }
            if(s[i]<s[s.size()-1-i]){
                gotSmaller  = true;
                isthesame= false;
            }
            s[s.size()-1-i]= s[i];
        }
        if(gotSmaller || isthesame){
            int numb = s[(s.size()-1)/2]-'0';
            if(numb==9){
                numb =0;
                int k = s[(s.size()-1)/2-1] - '0';
                k++;
                s[(s.size()-1)/2-1]=k+'0';

                k = s[(s.size()-1)/2+1] - '0';
                k++;
                s[(s.size()-1)/2+1]=k+'0';

                s[(s.size()-1)/2]=numb+'0';
            }
            else{
                numb++;
                s[(s.size()-1)/2]=numb+'0';
            }
        }
    }
    cout << s << endl;
    return 0;
}
