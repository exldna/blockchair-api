# include <iostream>
# include <chair/chair.hxx>

int check_coins(int argc, char*[]) {
    auto answer = chair::api::get_block(chair::coins::ethereum, "2345678");
    if (answer.has_value()) {
        std::cout << answer.value() << '\n';
    } else {
        std::cout << "answer has not value\n";
    }
    return 0;
}