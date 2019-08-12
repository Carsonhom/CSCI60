#include "sd.h"

SD::SD()
{
  name_ = "";
  capacity_ = 0;
  usedMem_ = 0;
}

SD::SD(std::string name, int capacity, int usedMem)
{
  name_ = name;
  capacity_ = capacity;
  usedMem_ = usedMem;
}

std::string SD::name()
{
  return name_;
}

int SD::capacity()
{
  return capacity_;
}

int SD::usedMem()
{
  return usedMem_;
}

bool SD::takePicture()
{
  if(capacity_ - usedMem_ > 50)
  {
    usedMem_ += 50;
    return true;
  }
  else return false;
}

void SD::empty()
{
  usedMem_ = 0;
}

bool SD::dump(SD& sd)
{
  if(usedMem_ + sd.usedMem_ <= capacity_)
  {
    usedMem_ += sd.usedMem_;
    sd.usedMem_ = 0;
    return true;
  }
  else return false;
}





