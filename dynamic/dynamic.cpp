#include <iostream>

double readPositiveDouble() {
  double x;
  do {
    std::cout << "Въведете число: ";
    std::cin >> x;
  } while (x <= 0);
  // x > 0
  return x;
}

double* readArray(int n) {
  double* a = new double[n];
  for(int i = 0; i < n; i++)
    a[i] = readPositiveDouble();
  return a;
}

double findAverage(double a[], int n) {
  double sum = 0;
  for(int i = 0; i < n; i++)
    sum += a[i];
  return sum / n;
}

void testAverage() {
  int n;
  do {
    std::cout << "n = ";std::cin >> n;
  } while(n <= 0);
  // !!! double a[MAX];
  // !!! double a[n]; // variable-sized array
  // !!! std::cout << findAverage(readArray(n), n) << std::endl;
  double* a = readArray(n);
  std::cout << findAverage(a, n) << std::endl;
  delete[] a;
}

double** createMatrix(int m, int n) {
  double** a = new double*[m]; // по 1 указател за всеки ред
  for(int i = 0; i < m; i++)
    // заделяме памет за ред i
    a[i] = new double[n];
  return a;
}

double** readMatrix(int m, int n) {
  double **a = createMatrix(m, n);
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      std::cout << "a[" << i << "][" << j << "] = ";
      std::cin >> a[i][j];
    }
  }
  return a;
}

void printMatrix(double** a, int m, int n) {
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++)
      std::cout << a[i][j] << '\t';
    std::cout << std::endl;
  }   
}

void deleteMatrix(double **a, int m, int) {
  // изтриваме всеки ред
  for(int i = 0; i < m; i++) {
    std::cout << "Изтриваме " << a[i] << std::endl;
    delete[] a[i];
  }
  // изтриваме указателния масив
  delete[] a;
}

// double**
void transposeMatrix(double **&a, int m, int n) {
  double** newa = createMatrix(n, m);
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      newa[j][i] = a[i][j];
  deleteMatrix(a, m, n);
  a = newa;
  // return newa;
}

void testTranspose() {
  int m, n;
  std::cout << "m = ";std::cin >> m;
  std::cout << "n = ";std::cin >> n;
  double** a = readMatrix(m, n);
  printMatrix(a, m, n);
  // a = transposeMatrix(a, m, n);
  transposeMatrix(a, m, n);
  printMatrix(a, n, m);
  // !!! double b[10][20] = { 0 };
  // !!! printMatrix(b, 10, 20);
  deleteMatrix(a, n, m);
  std::cout << "Готово!\n";
}

int main() {
  // testAverage();
  testTranspose();
  return 0;
}
