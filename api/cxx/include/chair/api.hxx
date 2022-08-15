/**
 *  @file api.hxx
 *  @brief simple api
 *
 *  @author exidna
 */

# ifndef CHAIR_API_HXX
# define CHAIR_API_HXX

# include <cpr/cpr.h>
# include <chair/coins.hxx>

# include <optional>

/// @brief contains synchronized api functions
namespace chair::api {
    inline std::string request(std::string&& url) {
        std::string request_string = std::string("https://api.blockchair.com/") + url;
        std::cout << "request: " << request_string << '\n';
        return cpr::Get(cpr::Url{request_string}).text;
    }

    using response = std::optional<std::string>;

    inline response get_stats() {
        return request("stats");
    }

    template<coins::CoinClass coin_class>
    inline response get_stats(const coins::Coin<coin_class>& coin) {
        return request(coin.name + "/stats");
    }

    template<>
    inline response get_stats<>(const coins::Coin<coins::CoinClass::xchain>& coin) {
        return request("cross-chain/" + coin.name + "/stats");
    }

    template<coins::CoinClass coin_class>
    inline response get_block(const coins::Coin<coin_class>& coin, std::string hash_or_height) {
        if constexpr (
            coin_class == coins::CoinClass::btc ||
            coin_class == coins::CoinClass::eth
            ) {
            return request(coin.name + "/dashboards/block/" + hash_or_height);
        } else {
            return {};
        }
    }

    template<coins::CoinClass coin_class>
    inline response get_block(const coins::Coin<coin_class>& coin, uint height) {
        return get_block(coin, std::to_string(height));
    }
}

# endif // !CHAIR_API_HXX