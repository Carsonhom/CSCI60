#ifndef NODE_H
#define NODE_H
#include <iostream>
class node
{
public:

    typedef int value_type;

    // pre: none
    // post: creates a new node with given data and link values
    //       defaults: 0 and nullptr
    node(const value_type & = value_type(),//value_type() requires C++11
         node * = nullptr);

    // pre: none
    // post: returns data value stored in this node
    value_type data() const;

    // pre: none
    // post: returns link value stored in this node
    node * link();

    // pre: none
    // post: returns CONSTANT link value stored in this node
    const node * link() const;

    // pre: none
    // post: sets the data field to given value
    void set_data(const value_type &);

    // pre: none
    // post: sets the link field to given value
    void set_link(node *);


private:
    value_type data_;
    node *   link_;
    // invariants:
    //  data_ holds the data value stored in this node
    //  link_ holds the address of the next node
};



std::size_t list_size(const node * head);
void list_head_insert(node * & head, node * & tail, const node::value_type & value);
void list_tail_insert(node * & head, node * & tail, const node::value_type & value);
std::ostream& operator <<(std::ostream& out, const node* head);
void list_head_remove(node * & headptr, node * & tailptr);
void list_tail_remove(node * & headptr, node * & tailptr);
void list_remove_value(node * & headptr, node * & tailptr, node::value_type value);


#endif // NODE_H
