# include <iostream>
# include <chair/chair.hxx>

int chair_main(int argc, char*[]) {
    auto parser_op = chair::coins::bitcoin.get_addresses_info("0", "1");
    if (parser_op.has_value()) {
        auto& data = parser_op.value().get_data();
        std::cout << data << '\n';
    }
    return 0;
}