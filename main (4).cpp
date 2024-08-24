#include <iostream>
#include <string>

using namespace std;

struct CArithmetic{

  float sum (float a, float b){
    return a+b;
  }
  
  float rest (float a, float b){
    return a-b;
  }
  
  float mul (float a, float b){
    return a*b;
  }
  
  float div (float a, float b){
    if (b == 0.0)
      throw (int)   0;
    return a/b;
  }

};

typedef float (CArithmetic::*Actual)(float, float);

int main() {
  float x, y, res;
  int opcion = 0;
  CArithmetic calc;
  Actual op[4] = {&CArithmetic::sum, &CArithmetic::rest, &CArithmetic::mul, &CArithmetic::div};
  cout << "¿Que operación desea realizar?\n0. Suma\n1. Resta\n2. Multiplicación\n3. División" << endl;
  cin >> opcion;
  cout << "¿Cuál es el primer número?" << endl;
  cin >> x;
  cout << "¿Cuál es el segundo número?" << endl;
  cin >> y;
  try {
    res = (calc.*op[opcion])(x, y);
    cout << "La respuesta es: " << res << endl;
  } catch (int e) {
    cout << "Error: División por cero." << endl;
  }
  return 0;
}