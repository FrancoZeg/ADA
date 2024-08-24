#include <iostream>

using namespace std;

template <typename Type> class CVector
{
private:
  Type*m_pVect;
  int m_nCount,
  m_nMax,
  m_nDelta;
  void Init(int delta);
  void Resize();
public:
  CVector(int delta = 10);
  void Insert(Type elem);
};

template <typename Type> CVector<Type>::CVector(int delta)
{
  Init(delta);
}

template <typename Type> void CVector<Type>::Insert(Type elem)
{
  if( m_nCount == m_nMax )
    Resize();
  m_pVect[m_nCount++] = elem;
}

template <typename Type> void CVector<Type>::Init(int delta){
  m_pVect = new Type[delta];
  m_nCount = 0;
  m_nMax = delta;
  m_nDelta = delta;
}

template <typename Type> void CVector<Type>::Resize(){
  Type*pVect = new Type[m_nMax + m_nDelta];
  for(int i = 0; i < m_nMax; i++)
    pVect[i] = m_pVect[i];
  delete [] m_pVect;
  m_pVect = pVect;
  m_nMax += m_nDelta;
}

int main(){
  CVector<int> v;
  v.Insert(1);
  return 0;
}