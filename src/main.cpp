#include "foo.h"
#include <iostream>
#include <functional>
#include <type_traits>


#ifdef __cplusplus
extern "C" {
#endif

#include "test.h"

#ifdef __cplusplus
}
#endif

// =========== SCRIPT ============


int main(int argc, char * argv[]) {
    [out = std::ref(std::cout << "Result from C code: " << add(1, 2))]() {
        out.get() << ".\n";
    }();

    if (std::is_same<decltype(NULL), decltype(0)>::value)
        std::cout << "NULL == 0" << std::endl;
    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
        std::cout << "NULL == ((void*)0)" << std::endl;
    if (std::is_same<decltype(NULL), decltype(nullptr)>::value)
        std::cout << "NULL == nullptr" << std::endl;

    test();
    return 0;
}





void foo(void* c) {
    std::cout << "foo(char*) is called" << std::endl;
}

void foo(int a) {
    std::cout << "foo(int) is called" << std::endl;
}

void foo(long) {
    std::cout << "foo(long) is called" << std::endl;
}

