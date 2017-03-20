#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

long bound = 1000000007;
int n, k;
long first, mul, add, mod;
std::vector<int> grades;

int highestStory(int fromIndex);

int main()
{
 scanf("%d %d", &k, &n); 
 scanf("%d %d %d %d", &first, &mul, &add, &mod);
 grades.push_back(first);
 
 int sum = grades[0];
 
 for(int i = 1; i < k; i++)
 {
         grades.push_back((grades[i-1] * mul + add) % mod);
 }
  int currentStory = grades[0];
  int i = 0;
 while(i < k)
 {
        
         for(int j =1; j<= n; j++)
         {
           if(i+j < k && currentStory >= grades[i+j]){
                        sum=sum +currentStory;    
                        
                  if(j == n)
                  {
                       int lastI = i;
                    int highestIndex = highestStory(i+j);
                    i = highestIndex; 
                    currentStory = grades[i];
                    i= lastI+j-1;
                    }
                  
           }
           else if(i+j< k){
                if(grades[i+j] >= currentStory)
                {
                   
                   i = i+j;
                   currentStory=grades[i];       
                    if(i==grades.size()-2)
                       sum=(sum +currentStory);
                }
                else
                {
                    int highestIndex = highestStory(i+j);
                    i = highestIndex; 
                    currentStory = grades[i];
                }
               break;    
           }
           else
               i+=j;
         }
 }
 
 printf("\n %d", sum);
 return 0;   
}

int highestStory(int fromIndex)
{
  int max= grades[fromIndex];
    int maxIndex= fromIndex;
 for(int i =fromIndex-1; i> abs(fromIndex-n);i--)
 {
         if(max<=grades[i])
         {
                 max=grades[i];       
                 maxIndex=i; 
         }
 }     
 return maxIndex;
}
