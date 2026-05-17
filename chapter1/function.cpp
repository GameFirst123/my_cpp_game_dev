#include <iostream>

int Func1(int number){
  number=30;
  return number;
}

void Func2(int &number){
  number=40;
}

int main() {

  int num=20;

  Func1(num);
  std::cout << num << "\n";

  Func2(num);
  std::cout << num;

  return 0;
}