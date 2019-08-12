
#include <iostream>
#include "node.h"
using namespace std;

int main() {
    node * head, *tail;
    head = tail = nullptr; //empty list
    node n(5, nullptr);
    head = tail = &n;
    node n2(6, nullptr);
    n.set_link(&n2);
    tail = &n2;//Works, but not how we do it - those names are bulky and serve no purpose

    head = tail = new node(5, nullptr);
    node* node1 = new node(6, nullptr);
    tail->set_link(node1);
    tail = node1;//Insert at the tail - easier to insert at the head

    head = tail = new node(4, nullptr);//Tail is nice to have but not necessary
    head = new node(2, head);
    head = new node(9, head);
    head = new node(6, head);
    head = new node(5, head);

    for(node* p = head; p!=nullptr; p=p->link()){
      cout<<p->data() <<" ";
    }









    return 0;
}
























/*
void list_copy(const node *orig_head, const node *orig_tail, node * & new_head, node * & new_tail) {
    while (new_head->link()!=nullptr) {
        node *temp = new_head;
        new_head= new_head->link();
        delete temp;


    }
    new_head = new_tail = node (*orig_head);
    for (const node *p = orig_head->link(); p != nullptr; p = p->link()) {
        node * temp = node (p->data(), nullptr);
        new_tail->setlink_(temp);
        new_tail = temp;

    }
}

void list_index_remover (node * & head_ptr, node * & tail_ptr, std::size_t n) {
    if(head_ptr==nullptr)
        return;
    else if (n==0){
        head_ptr=head_ptr->link();
    }
    else if (n==1){
        node *temp = head_ptr->link();
        head_ptr->setlink_(head_ptr->link()->link());
        delete temp;


    }
    else{
        node * nhead = head_ptr->link();
        list_index_remover(nhead, tail_ptr, n-1);
    }
}

void list_index_remove(node * & head_ptr, node * & tail_ptr, std::size_t n){
    if(head_ptr==nullptr)
        return;
    std::size_t count = 0;
    node *temp;
    for (node *p = head_ptr; p->link()!= nullptr; p = p->link()) {
        cout<<count<<endl;
        if (count==n-1){
            cout<<"here"<<count<<endl;
            temp=p->link();
            if (p->link()->link()==nullptr)
                p->setlink_(nullptr);
            else
                p->setlink_(p->link()->link());
            cout<<"here2"<<endl;
            delete temp;
            return;

        }
        count++;
    }
}
*/
//void list_reverse(node* & head_ptr){
//    node* tail = node (head_ptr->data(), nullptr);
//    head_ptr=head_ptr->link();
//    for (head_ptr; head_ptr!=nullptr; head_ptr=head_ptr->link()){
//        tail=new node (head_ptr->data(), tail);
//    }
//    while (head_ptr->link()!=nullptr) {
//        node *temp = head_ptr;
//        head_ptr=head_ptr->link();
//        delete temp;
//    head_ptr=tail;
//    }
//
//}
//
//

/*
#
#include <iostream>
#include "node.h"

using namespace std;

int main(int argc, char *argv[])
{

    node * head = node(5, nullptr);
    node * tail = head;
    head = node(7, head);
    head = node(2, head);
    head = node(9, head);
    head = node(40, head);

    for(node* p =head; p!=nullptr; p = p->link() ){
        cout<<p->data()<<" ";
    }
    cout<<endl;
    list_remove_value(head, tail, 2);
    for(node* p =head; p!=nullptr; p = p->link() ){
        cout<<p->data()<<" ";
    }
    cout<<endl;
    cout<<list_size_rec(head)<<endl;







/*


    cout<<endl<<list_size(head)<<endl;
    cout<<head<<endl;
    list_head_remove(head, tail);

    cout<<head<<endl;

    return 0;
}


*/



/*
 *
size_t size(node* head){
    if(head==nullptr)
        return 0;
    else
        return 1+size(head->link());
}

node* remove(node* head, node::value_type find){
    if(head==nullptr)
        return nullptr;
    else if(head->data()==find){
        temp = head->link();
        delete head;
        return temp;
    }
    else{
        head->setlink_(remove(head->link(), find));
        return head;
    }
}

void remove2(node* & head, node::value_type find){
    if(head==nullptr)
        return;
    else if(head->link()==nullptr){
        if(head->data()==find)
            head = nullptr;
    }
    else if(head->link->data()==find){
        temp = head->link()->link();
        delete head->link();
        head->setlink_(temp);
    }
    else{
        remove(head->link(), find);
    }
}
node* insert_at(node* head, node::value_type value, std::size_t index){
    if(head==nullptr)
        return nullptr;
    else if(index==1){
        head->setlink_(new node(value, head->link()));
        return head;
    }

    else{
        head->setlink_(insert_at(head->link(), value, index-1));
        return head;
    }

}

void insert_at2(node* & head, node::value_type value, std::size_t index){
    if(head==nullptr)
        return;
    else if(index==1){
        head->setlink_(new node(value, head->link()));
    }

    else{
        insert_at(head->link(), value, index-1);
    }

}

*/
