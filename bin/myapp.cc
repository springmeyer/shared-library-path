#include <mylib/interface.h>

#include <string>
#include <iostream>

int main(int argc, char **argv) {
    MyLib::Message msg("hello");
    std::cout << msg.get() << "\n";
    std::clog << MyLib::get_lib_dir("mapnik",(void*)(intptr_t) MyLib::anchor) << "\n";
    return 0;
}
