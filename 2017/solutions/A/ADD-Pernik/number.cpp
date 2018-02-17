#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

int n, m;
int main()
{
    scanf("%d %d", &m, &n);
    
    int counter = 0;
    int result;
    for(int i = 1; i <= ceil(sqrt((double)n));i++)
    {
       result= i*(i+1);
       if(result <= n && result >= m){
         //std::cout<<i*(i+1) << " " <<i<<std::endl;
         counter++;
         }
    }
    
    printf("%d", counter);
    return 0;   
}
