#include <iostream>
using namespace std;
long long rec(long long broi,long long delimost,long long gotovochislo){
	if(gotovochislo%delimost==0 && gotovochislo>=10){
		return gotovochislo;
	}else{
		rec(broi,delimost,gotovochislo+1);
	}
}
int main()
{
   long long broi,delimost;
   cin>>broi>>delimost;
	cout<<rec(broi,delimost,0)<<endl;
    return 0;
}
