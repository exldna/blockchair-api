/**
 *  @file api.hxx
 *  @brief
 *
 *  @author exidna
 */

# ifndef CHAIR_API_HXX
# define CHAIR_API_HXX

# include <chair/coins.hxx>
# include <chair/system.hxx>

/// @brief contains synchronized no-const api functions
namespace chair::api {

    inline Response get_stats() {
        return chair::System::get().request("stats");
    }

    template<coins::CoinClass coin_class>
    inline Response get_stats(const coins::Coin<coin_class>& coin) {
        return chair::System::get().request(coin.name + "/stats");
    }

    template<>
    inline Response get_stats<>(const coins::Coin<coins::CoinClass::xchain>& coin) {
        return chair::System::get().request("cross-chain/" + coin.name + "/stats");
    }

    template<coins::CoinClass coin_class>
    inline Response get_block(const coins::Coin<coin_class>& coin, std::string hash_or_height) {
        if constexpr (
            coin_class == coins::CoinClass::btc ||
            coin_class == coins::CoinClass::eth
            ) {
            return chair::System::get().request(coin.name + "/dashboards/block/" + hash_or_height);
        } else {
            return {};
        }
    }

    template<coins::CoinClass coin_class>
    inline Response get_block(const coins::Coin<coin_class>& coin, uint height) {
        return get_block(coin, std::to_string(height));
    }
}

# endif // !CHAIR_API_HXX