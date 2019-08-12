#include "sd.h"
#include <iostream>
#include <string>

int main() {
  std::string name;
  int capacity;
  int usedMem;

  std::cout << "What is the name of your sd card? : ";
  std::cin >> name;
  std::cout << "What is the capacity of your sd card? : ";
  std::cin >> capacity;
  std::cout << "How many pictures do you already have on your sd card? : ";
  std::cin >> usedMem;
  
  SD a = SD(name, capacity, usedMem*50);

  a.takePicture();
  std::cout << a.usedMem() << std::endl;

  a.empty();
  std::cout << a.usedMem() << std::endl;

  SD b = SD("joe", 100000, 100);
  a.dump(b);
  std::cout << a.usedMem() << std::endl;

  return 0;
}


