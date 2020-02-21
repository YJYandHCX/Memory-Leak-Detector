#include <iostream>
#include "LeakDetector.h"
using namespace std;

int main()
{
    auto n = new int(9);
    auto t = new int(10);
    auto s = new int(12);
    //auto c = new int(9);
    //delete(n);


    //Leak_detector::l_d.~detector();


    getchar();
    return 0;
}
