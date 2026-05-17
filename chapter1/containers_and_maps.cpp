#include <iostream>
// #include <array>
#include <string>
#include <vector>
#include <unordered_map>

void PrintArrays(int nums[5]) {
  for (int i=0;i<5;i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << "\n";
}

void PrintVectors(std::vector<int> vector) {
  for (int x : vector) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

void PrintUnorderedMap(std::unordered_map<std::string, int> unordered_map) {
  for (auto x : unordered_map) {
    std::cout << "key: " << x.first << " , value: " << x.second << "\n";
  }
}

int main() {

  int arr[5]={1,2,3,4,5};
  PrintArrays(arr);

  std::vector<int> v1;
  v1={10,20,30,40,50};
  v1.push_back(60);
  PrintVectors(v1);

  std::unordered_map<std::string, int> um1 = {
    {"pigs",20},
    {"dogs",30},
    {"cats",40},
    {"monkey",50}
  };
  PrintUnorderedMap(um1);

  return 0;
}