 #include "dbiguint.h"


dbiguint::dbiguint() //biguint default constructor
{
  data_ = new unsigned short[1];
  data_[0] = 0;
  capacity_ = 1;
}

dbiguint::dbiguint(const std::string & str) //biguint constructor which converts string into biguint
{
  std::string str2 = str;
  for(std::size_t i = 0; i < str.length(); i++)
  {
  str2.at(i) = str.at(str.length() - 1 - i);
  }
  data_ = new unsigned short[str.length()]; 
  capacity_= str.length();
  for(std::size_t j = 0; j < str2.length(); j++)
  {
    data_[j] = str2.at(j) - '0';
  }
}


dbiguint::dbiguint(const dbiguint & b)
{
  delete [] data_;
  capacity_ = b.capacity_;
  data_ = new unsigned short[capacity_];
  for(std::size_t i = 0; i < capacity_; i++)
  {
    data_[i] = b.data_[i];
  }
}


std::size_t dbiguint::size() const
{
  return capacity_;
}

unsigned short dbiguint::operator [](std::size_t pos) const //accesses the digit in position pos
{
  if(pos < capacity_)
  {
    return data_[pos];
  }
  else return 0;
}

void dbiguint::reserve(std::size_t newcapacity_)
{
  if(newcapacity_ > capacity_)
  {
    unsigned short *newdata;
    newdata = new unsigned short[newcapacity_];
    for(std::size_t i = 0; i < capacity_; i++)
    {
      newdata[i] = data_[i];
    }


    for(std::size_t k = capacity_; k < newcapacity_; k++)
    {
      newdata[k] = 0;
    }

    delete[] data_;
    capacity_ = newcapacity_;
    data_ = newdata;
  }
  else if(newcapacity_ < capacity_)
  {
    // std::size_t indx = 0;
    // while(data_[capacity_ - 1 - indx] == 0 && (capacity_ - indx) > 0)
    // {
    //   indx++;
    // }
    // if(capacity_ - indx < newcapacity_)
    // {
    //   newcapacity_ = capacity_ - indx;
    // }
    unsigned short *newdata;
    newdata = new unsigned short[newcapacity_];
    for(std::size_t i = 0; i < newcapacity_; i++)
    {
      newdata[i] = data_[i];
    }
    delete [] data_;
    capacity_ = newcapacity_;
    data_ = newdata;
  }
}

void dbiguint::operator +=(const dbiguint & b)
{
  if(capacity_ < b.capacity_)
  {
    this -> reserve(b.size());
  }
  for(std::size_t i = 0; i < capacity_; i++)
  {
    if(data_[i] + b.data_[i] >= 10 && i + 1 == capacity_)
    {
      this -> reserve(capacity_ + 1);
      data_[i] = data_[i] + b.data_[i] - 10;
      data_[i + 1] += 1;
    }
    if(data_[i] + b.data_[i] >= 10)
    {
      data_[i] = data_[i] + b.data_[i] - 10;
      data_[i + 1] += 1;
    }
    else
    {
      data_[i] += b.data_[i];
    }
  }
}

dbiguint::~dbiguint()
{
  delete [] data_;
  data_ = nullptr;
  capacity_ = 0;
  // std::cout << "destructor ";
}



void dbiguint::operator -=(const dbiguint & b)
{
  if(capacity_ < b.capacity_)
  {
    this -> reserve(b.size());
    std::cout << "-=" << std::endl;
  }
  for(std::size_t i = 0; i < capacity_; i++)
  {
    if(data_[i] - b.data_[i] < 0)
    {
      data_[i + 1] -= 1;
      data_[i] = (10 + data_[i]) - b.data_[i];
    }
    else 
    {
      data_[i] -= b.data_[i];
    }
  }

  std::size_t indx = 0;
  std::size_t newcapacity_;
  while(data_[capacity_ - 1 - indx] == 0 && (capacity_ - indx) > 0)
  {
    indx++;
  }
  if(capacity_ - indx < capacity_)
  {
    newcapacity_ = capacity_ - indx;
    this -> reserve(newcapacity_);
  }

  // return (*this);
  // dbiguint ndbiguint = dbiguint(*this);
  // return ndbiguint;
}

int dbiguint::compare(const dbiguint & b) const
{
  if(capacity_ == b.capacity_)
  {
    for(std::size_t i = capacity_; i >= 1; i++)
    {
      if(data_[i - 1] > b.data_[i - 1])
      {
        return 1;
      }
      else if(data_[i - 1] < b.data_[i - 1])
      {
        return -1;
      }
      else if(data_[i - 1] == b.data_[i - 1] && (i - 1) == 0)
      {
        return 0;
      }
    }
  }
  else if(capacity_ > b.capacity_)
  {
    return 1;
  }
  else return 0;
}

void dbiguint::operator =(const dbiguint & b)
{
  // this -> ~dbiguint();
  delete [] data_;
  // std::cout <<"spot 1" << std::endl;
  capacity_ = b.capacity_;
  data_ = new unsigned short[capacity_];
  for(std::size_t i = 0; i < capacity_; i++)
  {
    data_[i] = b.data_[i];
    // std::cout << b.data_[i];
  }
  // std::cout <<"spot 2" << std::endl;


  // unsigned short *newdata;
  // newdata = new unsigned short[b.capacity_];
  // *newdata = *b.data_;
  // *data_ = *newdata;
  // capacity_ = b.capacity_;
  // delete [] newdata;

  // this -> reserve(b.size());
  // for(std::size_t i = 0; i < capacity_; i++)
  // {
  //   data_[i] = b.data_[i];
  // }
  // return (*this);  
  // return dbiguint(*this);
}



void dbiguint::operator *=(const dbiguint & b)
{
  std::size_t newdata = 0;
  // unsigned short *newdata;
  // newdata = new unsigned short[newcapacity_];
  for(std::size_t i = 0; i < capacity_; i++)
  {
    for(std::size_t j = 0; j < b.capacity_; j++)
    {
      // std::string str = std::to_string((data_[i] * (int)pow(10, i)) * (b.data_[j] * (int)pow(10, j)));
      // std::cout << str << std::endl;
      newdata += (data_[i] * (int)pow(10, i)) * (b.data_[j] * (int)pow(10, j));
    }
  }
  // dbiguint d = dbiguint(str);
  // c += d;
  std::string str = std::to_string(newdata);
  dbiguint c = dbiguint(str);
  delete [] data_;
  // std::cout <<"spot 1" << std::endl;
  capacity_ = c.capacity_;
  data_ = new unsigned short[capacity_];
  for(std::size_t i = 0; i < capacity_; i++)
  {
    data_[i] = c.data_[i];
    // std::cout << b.data_[i];
  }

  std::size_t indx = 0;
  std::size_t newcapacity_;
  while(data_[capacity_ - 1 - indx] == 0 && (capacity_ - indx) > 0)
  {
    indx++;
  }
  if(capacity_ - indx < capacity_)
  {
    newcapacity_ = capacity_ - indx;
    this -> reserve(newcapacity_);
  }
  // return dbiguint(*this);

}

void dbiguint::clean()
{
  std::size_t newcap = capacity_;
  for(int i = capacity_ - 1; data_[i] == 0; --i)
  {
    newcap--;
  }
  unsigned short *newdata;
  newdata = new unsigned short[newcap];
  for(int i = 0; i < newcap; ++i)
  {
    newdata[i] = data_[i];
  }
  delete [] data;
  data = newdata;
  capacity_ = newcap;
}



// std::string biguint::toString() //converts a biguint into a string
// {
//   std::string str = "";
//   std::string str1;
//   for(int i = 0; i < CAPACITY; i++)
//   {
//     if(data_[i] != 0)
//     {
//       str += '0' + data_[i];
//      // str += std::to_string(data_[i]);
//     }
//   }
//   str1 = str;
//   for(int i = 0; i < str.length(); i++)
//   {
//     str1.at(i) = str.at(str.length() - 1 - i);
//   }
//   return str1;
// }

