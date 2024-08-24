#include <iostream>

using namespace std;

class CVector
{
private:
  int *m_pVect,
  m_nCount,
  m_nMax,
  m_nDelta;
  void Init(int delta);
  void Resize();
public:
  CVector(int delta = 10){Init(10);};
  void Insert(int elem);
};

void CVector::Insert(int elem)
{
  if( m_nCount == m_nMax )
    Resize();
  m_pVect[m_nCount++] = elem;
}

void CVector::Resize(){
  int *pVect = new int[m_nMax + m_nDelta];
  for(int i = 0; i < m_nMax; i++)
    pVect[i] = m_pVect[i];
  delete [] m_pVect;
  m_pVect = pVect;
  m_nMax += m_nDelta;
}

void CVector::Init(int delta){
  m_nDelta = delta;
  m_pVect = new int[delta];
  m_nCount = 0;
  m_nMax = delta;
}

int main(){
  CVector v;
  v.Insert(1);
  return 0;
}