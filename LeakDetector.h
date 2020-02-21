#ifndef LEAKDETECTOR_H_INCLUDED
#define LEAKDETECTOR_H_INCLUDED

#include <iostream>
#include <vector>

namespace Leak_detector{
    
	//结构体，leak_node 使用一个链表来存分配的内存
	struct leak_node{
        void* p;
        size_t size;
        leak_node* pre;
        leak_node* next;
    };
	
	
    class detector{
        private:
            size_t total_size;
            leak_node* head;

        public:
            detector();

            ~detector();
            
			//返回头节点
			leak_node* Get_head();
			
			//修改总内存大小的接口
            void add_size(int a);
            void min_size(int a);
    };
}
//全局变量leak—detector，这个先于main存在
static Leak_detector::detector l_d;

//重载operator new
void *operator new (size_t t);


void operator delete (void* ptr);
#endif // LEAKDETECTOR_H_INCLUDED
