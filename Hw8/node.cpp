#include "node.h"

node::node(const value_type & init_data, node * init_link)
{

    _data = init_data;
    _link = init_link;
}

node::value_type node::data() const
{
    return _data;
}

node * node::link()
{
    return _link;
}

void node::set_data(const value_type & new_data)
{
    _data = new_data;
}

void node::set_link(node * new_link)
{
    _link = new_link;
}

std::size_t list_index(node * head_ptr, int target)
{
  std::size_t x = 0;
  for (node*p = head_ptr; p != nullptr; p = p->link()) 
  {
    if (p->data() == target)
    {
      return x;
    }
    x++;
  }
  std::cout << "Not found" << std::endl;
  return x;
}

node* list_at(node * head_ptr, std::size_t n)
{
  node* x = nullptr;
  std::size_t count = 0;
  for (node*p = head_ptr; p != nullptr; p = p->link()) 
  {
    if (count == n) 
    {
      return p;
    }
    count++;
  }
  return nullptr;
}

void list_clear(node * & head_ptr, node * & tail_ptr)
{
  node * nhead;
  for (node * p = head_ptr; p != nullptr; p = p -> link())
  {
    if(p == nullptr)
    {
      return;
    }
    else if(p == tail_ptr)
    {
      nhead = head_ptr;
      tail_ptr = nullptr;
      head_ptr = nullptr;
      delete nhead;
      return;
    }
    else 
    {
      nhead = head_ptr;
      head_ptr = head_ptr -> link();
      delete nhead;
    }
  }
  
}

void reverse(int a[], int first, int last)
{
  if(last - first == 2 || last - first == 1)
  {
    int f = a[first];
    a[first] = a[last];
    a[last] = f;
    return;
  }
  else
  {
    int f = a[first];
    a[first] = a[last];
    a[last] = f;
    return reverse(a, first + 1, last - 1);
  }
}

// void list_reverse(node * & head_ptr, node * & tail_ptr)
// {
//   int count = 0;
//   for(node * p = head_ptr; p != nullptr; p = p -> link())
//   {
//     ++count;
//   }
//   int arr[count];
//   int pos = 0;
//   for(node * q = head_ptr; q != nullptr; q = q -> link())
//   {
//     arr[pos] = q -> data();
//     ++pos;p[]
//   }
//   reverse(arr, 0, count - 1);
//   int pos2 = 0;
//   for(node * r = head_ptr; r != nullptr; r = r -> link())
//   {
//     r -> set_data(arr[pos2]);
//     ++pos2;
//   }
// }

void list_reverse(node * & head_ptr, node * & tail_ptr)
{
  node * prev = nullptr;
  node * next;
  for(node * p = head_ptr; p != nullptr; p = next)
  {
    next = p -> link();
    p -> set_link(prev);
    prev = p;
  }
  node * temp = head_ptr;
  head_ptr = tail_ptr;
  tail_ptr = temp;
}







/*
 *
const node * node::link() const
{
    return _link;
}
*/