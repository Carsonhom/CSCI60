#ifndef SD_H
#define SD_H

#include <iostream>
#include <string>
class SD{
private:
  std::string name_;
int capacity_;
int usedMem_;

public:
SD();

SD(std::string name, int capacity, int usedMem);

std::string name();

int capacity();

int usedMem();

bool takePicture();

void empty();

bool dump(SD& sd);
};
#endif
