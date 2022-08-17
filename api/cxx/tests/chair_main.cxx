# include <iostream>
# include <chair/chair.hxx>

# include <vector>

int chair_main(int argc, char*[]) {
    std::vector<int> a;
    auto parser_op = chair::coins::litecoin.get_block_info(10);
    if (parser_op.has_value()) {
        auto& parser = parser_op.value();
        auto& data = parser.get_data();

        std::cout << data << '\n';
    }
    return 0;
}