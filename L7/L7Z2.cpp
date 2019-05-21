#include <iostream>

unsigned int countSetBits(unsigned int n){
  unsigned int count = 0;
  while (n){
    count += n & 1;
    n >>= 1;
  }
  return count;
}
 
int main()
{
    int i = 15;
    std::cout << countSetBits(i)) << std:endl;
    return 0;
}
