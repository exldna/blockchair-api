# include <iostream>
# include <chair/chair.hxx>

int main(int argc, char*[]) {
    auto resp = chair::coins::bitcoin.get_stats();
    if (resp.has_value()) {
        std::cout << resp.value().data << '\n';
    }
    return 0;
}