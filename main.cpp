#include <iostream>

int gVect[100];
int gnCount;

void Insert(int elem)
{
  if( gnCount < 100 )
    gVect[gnCount++] = elem;
}

int main() { 
  Insert(10);
  return 0;
}