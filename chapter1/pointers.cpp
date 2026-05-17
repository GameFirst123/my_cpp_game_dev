#include <iostream>

int main() {
  int num=20;
  int* num_p=&num;

  std::cout << num << " " << num_p << "\n";

  int num2=*num_p;
  std::cout << num2 << "\n";
  num2=30;
  std::cout << num << " " << num2 << "\n";

  const int a=100;
  // a=40;
  const int* const a_p=&a;

  std::cout << *a_p;

  return 0;
}