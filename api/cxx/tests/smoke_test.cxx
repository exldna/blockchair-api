# include <iostream>
# include <chair/chair.hxx>

int smoke_test(int argc, char*[]) {
    std::cout << chair::get_version() << '\n';
    return 0;
}