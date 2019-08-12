#include "dynamicBag.h"
#include <assert.h>

dynamicBag::dynamicBag(){
    (*this).used_ = 0;//This does the same thing as used_ = 0;
    this -> capacity_ = 0;//This does the same thing as capacity_ = 0;
    data_ = nullptr;
}

dynamicBag::dynamicBag(const dynamicBag& other){
    used_ = other.used_;
    capacity_ = other.capacity_;
    data_ = new int[capacity_];
    for(size_type i = 0; i<used_; i++){
        data_[i] = other.data_[i];
    }
}
dynamicBag::~dynamicBag(){
    delete [] data_;//This is the only piece we NEED
    data_ = nullptr;
    capacity_ = 0;
    used_ = 0;
  }


dynamicBag::size_type dynamicBag::size() const{
 return used_;
}

dynamicBag::size_type dynamicBag::count(int target) const{
    size_type count = 0;
    for(size_type i = 0; i<used_; i++){
     if(data_[i] == target)
         count++;
    }
    return count;

}
int dynamicBag::operator [](size_type pos) const{
  assert(pos<used_);
  return data_[pos];
}
void dynamicBag::insert(int target){
    if(size()<capacity_){
    data_[used_] = target;
    used_++;
  }else{
    int * p2 = new int[used_*2];//We copied this from our previous example and modified it.
    for(int i=0; i<used_; ++i){
      p2[i] = data_[i];
    }
    delete [] data_;
    data_ = p2;
    data_[used_] = target;
    ++used_;
    capacity_*=2;
    p2 = nullptr;
  }
}

dynamicBag dynamicBag::operator +=(const dynamicBag& b){
 //assert(size()+b.size()<=CAPACITY);
 for(size_type i = 0; i<b.size(); i++)
 {
     insert(b[i]);//insert handles memory management
 }
 return (*this);//this is a pointer to the object I'm inside
}

bool dynamicBag::erase_one(int target){
    size_type i = 0;
    while(data_[i]!=target && i<used_) i++;

    if(i==used_)
        return false;
    else{
        for(size_type j=i; j<used_-1; j++){
        data_[j] = data_[j+1];
        }
        used_--;
        if(used_<=((1.0/4)*capacity_)){
          int * temp = new int[capacity_/2];
          for(size_type j = 0; j<used_; ++j){
            temp[j] = data_[j];
          }
          delete [] data_;
          data_ = temp;
          temp = nullptr;
        }

        return true;
    }
}

dynamicBag::size_type dynamicBag::erase(int target){
    /*
    size_type k = count(target);
    for(size_type i=0; i<k; i++)
        erase_one(target)
    return k;
    */
    size_type count=0;
    while(erase_one(target)) count++;//erase_one does any necessary memory management
    return count;
}

dynamicBag dynamicBag::operator =(const dynamicBag &other){
    used_ = other.used_;
    capacity_ = other.capacity_;
    data_ = new int[capacity_];
    for(size_type i = 0; i<used_; i++){
        data_[i] = other.data_[i];
    }
    return (*this);
}

std::ostream& operator <<(std::ostream&  out, const dynamicBag& b){
 for(dynamicBag::size_type i=0; i<b.size(); i++)
     out<<b[i]<<" ";
 out<<std::endl;
 return out;
}

dynamicBag operator + (const dynamicBag & b1, const dynamicBag & b2){
  dynamicBag ans;
  ans+=b1;
  ans+=b2;
  return ans;
}

dynamicBag::dynamicBag(int a[], int sz){
    capacity_ = sz;
    used_ = sz;
    data_ = new int[capacity_];
    for(size_type i = 0; i<used_; i++)
        data_[i] = a[i];
    }


  // void dynamicBag::reserve(size_type new_capacity)
  // {
  //   if(new_capacity > capacity_)
  //   {
  //     int *newdata = new int[new_capacity];
  //     for(size_type i = 0; i < capacity_; i++)
  //     {
  //       newdata[i] = data_[i];
  //     }
  //     capacity_ = new_capacity;
  //     delete [] data_;
  //     data_ = newdata;
  //   }
  // } 
