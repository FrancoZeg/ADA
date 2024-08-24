#include <iostream>
#include <cstdlib> // for realloc

struct Vector {
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;
};

void Resize(Vector* pThis) {
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector* pThis, int elem) {
    if (pThis->m_nCount == pThis->m_nMax)
        Resize(pThis);
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main() {
    Vector myVector = {nullptr, 0, 0, 10};
    Insert(&myVector, 10);
    return 0;
}
