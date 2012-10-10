#include <mylib/interface.h>

#include <string>
#include <iostream>

int main(int argc, char **argv) {
    MyLib::Message msg("hello");
    std::cout << msg.get() << "\n";
    std::clog << get_lib_dir("mapnik",(void*)(intptr_t) here) << "\n";

    return 0;
}
