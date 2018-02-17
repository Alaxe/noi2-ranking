#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

std::string row;
int n, m;
std::vector<int> modded;
std::vector<int> usedIndices;

bool isDigitUsed(int number);
void permute (std::string input);
void checkNumber (std::string input);

int main()
{
 std::cin>>row;
 scanf("%d %d", &n, &m);
 
   std::string symbol;
   
   for(int i =0; i < row.size(); i++)
   {
       usedIndices.clear();
       usedIndices.push_back(i);
       symbol = row.at(i);
       permute(symbol);
   }
   
   std::cout<<modded.size() % m; 
 return 0;
}

bool isDigitUsed(int number)
{
  for(int i = 0; i < usedIndices.size(); i++)
  {
          if(number == usedIndices[i])
                    return true;
  }
  
  return false;
}

void permute(std::string input)
{
  if(input.size() >= row.size())
    return;
    
  checkNumber(input);
     
 for(int i = 0; i < row.size(); i++)
 {
   if(isDigitUsed(i))
     continue;
 
   input.push_back(row[i]);
  while(std::next_permutation(input.begin(), input.end()))
     checkNumber(input);
  permute(input);
 }
}

bool isNumberModded(int number)
{
 for(int i=0; i< modded.size(); i++)
 {
         if(number == modded[i])
            return true;
 }
 return false;
 }

void checkNumber(std::string input)
{
   if(input.size() >= row.size())
    return;
    
     int number = atoi(input.c_str());
     if(number % n == 0 && !isNumberModded(number))
                   modded.push_back(number);
}

