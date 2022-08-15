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
        x_token // tether usd-coin binance-usd
    };

    template<CoinClass _coin_class>
    class Coin {
    protected:
        const CoinClass coin_class = _coin_class;
        const uint id;
    public:
        Coin(uint _id) : id(_id) {}

        // no copy
        Coin(const Coin&) = delete;
        Coin& operator=(const Coin&) = delete;

        // no move
        Coin(Coin&&) = delete;
        Coin& operator=(Coin&&) = delete;

        bool operator==(const Coin& other) {
            return coin_class == other.coin_class && id == other.id;
        }
    };

    inline const Coin<CoinClass::btc> bitcoin{0};
    inline const Coin<CoinClass::btc> bitcoin_cash{1};
    inline const Coin<CoinClass::btc> litecoin{2};
    inline const Coin<CoinClass::btc> bitcoin_sv{3};
    inline const Coin<CoinClass::btc> dogecoin{4};
    inline const Coin<CoinClass::btc> dash{5};
    inline const Coin<CoinClass::btc> groestlcoin{6};
    inline const Coin<CoinClass::btc> zcash{7};
    inline const Coin<CoinClass::btc> ecash{8};
    inline const Coin<CoinClass::btc> bitcoin_testnet{9};

    inline const Coin<CoinClass::eth> ethereum{0};
    inline const Coin<CoinClass::eth> ethereum_testnet{1};

    inline const Coin<CoinClass::xpr> ripple{0};
    inline const Coin<CoinClass::xlm> stellar{0};     
    inline const Coin<CoinClass::xmr> monero{0};
    inline const Coin<CoinClass::ada> cardano{0};
    inline const Coin<CoinClass::xin> mixin{0};
    inline const Coin<CoinClass::xtz> tezos{0};
    inline const Coin<CoinClass::eos> eos{0};

    inline const Coin<CoinClass::x_token> tether{0};
    inline const Coin<CoinClass::x_token> usd_coin{1};
    inline const Coin<CoinClass::x_token> binance_usd{2};
}

# endif // !CHAIR_COINS_HXX