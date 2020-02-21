#include "LeakDetector.h"

namespace Leak_detector{
    detector::detector(){
        total_size = 0;

        head = static_cast<Leak_detector::leak_node*>(malloc(sizeof(Leak_detector::leak_node)));
        head->next = nullptr;
        head->pre = nullptr;
    }
    detector::~detector(){

        
        if (head->next == nullptr){
            //std::cout<<"NO LEAK"<<std::endl;
            return;
        }
	std::cout<<"THE SIZE OF LEAK MEMORY IS " << this->total_size<<" Bytes"<<std::endl;
        head = head->next;
        while(head!=nullptr){
            //if (head->pre!=nullptr)
            free(head->pre);
            std::cout<<"Address is  "<<head->p<<" size is "<<head->size<<std::endl;
            head = head->next;
        }
        return;
    }

    leak_node*  detector::Get_head() { return head;};

    void detector::add_size(int a) {this->total_size+=a;};
    void detector::min_size(int a) {this->total_size-=a;};
}
void *operator new (size_t t){
    auto p = malloc(t);
    if (!p) std::cout<<"Memory is not enough"<<std::endl;

    l_d.add_size(t);


    auto n_node = static_cast<Leak_detector::leak_node*>(malloc(sizeof(Leak_detector::leak_node)));
    n_node->p = p;
    n_node->size = t;

    auto s = l_d.Get_head();
    while(s->next!=nullptr) s = s->next;

    s->next = n_node;
    n_node->pre = s;

    return p;
}
void operator delete (void* ptr){

    auto s = l_d.Get_head();

    s = s->next;
    while(s!=nullptr){
        if (s->p == ptr){
            s->pre->next = s->next;
            l_d.min_size(s->size);
            free(s);
            break;
        }
        s = s->next;
    }
    free(ptr);
    return;
}
