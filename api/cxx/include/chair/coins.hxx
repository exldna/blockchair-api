/**
 *  @file coins.hxx
 *  @brief contains API supported coins defenitions
 *
 *  @author exidna
 */

# ifndef CHAIR_COINS_HXX
# define CHAIR_COINS_HXX

namespace chair::coins {
    /// @brief coins classes
    enum class CoinClass : unsigned {
        btc, // bitcoin bitcoin-cash litecoin bitcoin-sv dogecoin dash groestlcoin zcash ecash bitcoin/testnet
        eth, // ethereum ethereum/testnet
        xpr, // ripple
        xlm, // stellar
        xmr, // monero
        ada, // cardano
        xin, // mixin
        xtz, // tezos
        eos, // eos
        xchain // tether usd-coin binance-usd
    };

    template<CoinClass _coin_class>
    class Coin {
    protected:
        const CoinClass coin_class = _coin_class;
    public:
        const std::string name;

        Coin(const std::string& _name) : name(_name) {}

        // no copy
        Coin(const Coin&) = delete;
        Coin& operator=(const Coin&) = delete;

        // no move
        Coin(Coin&&) = delete;
        Coin& operator=(Coin&&) = delete;

        bool operator==(const Coin& other) {
            return coin_class == other.coin_class && name == other.name;
        }
    };

    inline const Coin<CoinClass::btc> bitcoin{"bitcoin"};
    inline const Coin<CoinClass::btc> bitcoin_cash{"bitcoin-cash"};
    inline const Coin<CoinClass::btc> litecoin{"litecoin"};
    inline const Coin<CoinClass::btc> bitcoin_sv{"bitcoin-sv"};
    inline const Coin<CoinClass::btc> dogecoin{"dogecoin"};
    inline const Coin<CoinClass::btc> dash{"dash"};
    inline const Coin<CoinClass::btc> groestlcoin{"groestlcoin"};
    inline const Coin<CoinClass::btc> zcash{"zcash"};
    inline const Coin<CoinClass::btc> ecash{"ecash"};
    inline const Coin<CoinClass::btc> bitcoin_testnet{"bitcoin/testnet"};

    inline const Coin<CoinClass::eth> ethereum{"ethereum"};
    inline const Coin<CoinClass::eth> ethereum_testnet{"ethereum/testnet"};

    inline const Coin<CoinClass::xpr> ripple{"ripple"};
    inline const Coin<CoinClass::xlm> stellar{"stellar"};
    inline const Coin<CoinClass::xmr> monero{"monero"};
    inline const Coin<CoinClass::ada> cardano{"cardano"};
    inline const Coin<CoinClass::xin> mixin{"mixin"};
    inline const Coin<CoinClass::xtz> tezos{"tezos"};
    inline const Coin<CoinClass::eos> eos{"eos"};

    inline const Coin<CoinClass::xchain> tether{"tether"};
    inline const Coin<CoinClass::xchain> usd_coin{"usd-coin"};
    inline const Coin<CoinClass::xchain> binance_usd{"binance-usd"};
}

# endif // !CHAIR_COINS_HXX