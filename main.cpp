#include <iostream>

int *gpVect = NULL,
gnCount = 0,
gnMax = 0;

void Resize()
{
  const int delta = 10;
  int *pTemp, i;
  pTemp = new int[gnMax + delta]; 
  for(i = 0 ; i < gnMax ; i++) 
    pTemp[i] = gpVect[i]; 
  delete [ ] gpVect; 
  gpVect = pTemp; 
  gnMax += delta; 
}

void Insert(int elem)
{
  if( gnCount == gnMax )
    Resize();
  gpVect[gnCount++] = elem;
}

int main() { 
  Insert(10);
  return 0;
}
