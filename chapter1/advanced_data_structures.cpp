#include <cstdint>
#include <iostream>
#include <string>

/*
  part1
*/
// struct Address {
//   std::string city;
//   std::string street;
//   int houseNumber;
// };

// struct Student {
//   int age;
//   int grade;
//   std::string name;
//   double score {0};
//   Address address;
// };


/*
  part2
*/
union Holder {
  std::int64_t big_num;
  std::uint16_t mid_num;
  std::uint8_t low_num;
};

enum Levels {
  Level1,Level2,Level3
};

int main() {
  /*
    part1
  */
  // Student s1;
  // Student s2;
  // Address a2;

  // s1.address.city="Guangzhou";
  // s1.address.street="Canton Tower";
  // s1.address.houseNumber=250;

  // std::cout << s1.address.city + " " + s1.address.street + " " << s1.score << " " + s1.name + "test" << "\n";

  // a2.city="Peking";
  // a2.street="Dog road";
  // a2.houseNumber=2333;

  // s2.address.city=a2.city;
  // s2.address.street=a2.street;
  // s2.address.houseNumber=a2.houseNumber;
  // s2.name="Zhang";
  // s2.score=100;

  // std::cout << s2.address.city + " " + s2.address.street + " " << s2.score << " " + s2.name << "\n";


  /*
    part2
  */
  Holder test;
  test.big_num=10;
  test.low_num=20;
  test.mid_num=0;
  std::cout << sizeof(test) << "\n";

  enum Levels mylevel = Level1;
  std::cout << mylevel << "\n";

  return 0;
}