/**
 *  @file coins.hxx
 *  @brief contains API supported coins defenitions
 *
 *  @author exidna
 */

# ifndef CHAIR_COINS_HXX
# define CHAIR_COINS_HXX

# include <chair/system.hxx>

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
    class CoinBase {
    protected:
        const CoinClass coin_class = _coin_class;
        using Base = CoinBase<_coin_class>;
    public:
        const std::string name;

        CoinBase(const std::string& _name) : name(_name) {}
        CoinBase(std::string&& _name) : name(std::move(_name)) {}

        // no copy
        CoinBase(const CoinBase&) = delete;
        CoinBase& operator=(const CoinBase&) = delete;

        // no move
        CoinBase(CoinBase&&) = delete;
        CoinBase& operator=(CoinBase&&) = delete;

        bool operator==(const CoinBase& other) {
            return coin_class == other.coin_class && name == other.name;
        }
    };

    template<CoinClass _coin_class>
    class Coin {};

    template<>
    class Coin<CoinClass::btc> : public CoinBase<CoinClass::btc> {
    public:
        Coin(const std::string& _name) : Base(_name) {}
        Coin(std::string&& _name) : Base(std::move(_name)) {}

        chair::Response get_stats() const {
            return chair::System::get().request(name + "/stats");
        }
    };

    template<>
    class Coin<CoinClass::eth> : public CoinBase<CoinClass::eth> {
    public:
        Coin(const std::string& _name) : Base(_name) {}
        Coin(std::string&& _name) : Base(std::move(_name)) {}
    };

    template<>
    class Coin<CoinClass::xpr> : public CoinBase<CoinClass::xpr> {
    public:
        Coin(const std::string& _name) : Base(_name) {}
        Coin(std::string&& _name) : Base(std::move(_name)) {}
    };

    template<>
    class Coin<CoinClass::xlm> : public CoinBase<CoinClass::xlm> {
    public:
        Coin(const std::string& _name) : Base(_name) {}
        Coin(std::string&& _name) : Base(std::move(_name)) {}
    };

    template<>
    class Coin<CoinClass::xmr> : public CoinBase<CoinClass::xmr> {
    public:
        Coin(const std::string& _name) : Base(_name) {}
        Coin(std::string&& _name) : Base(std::move(_name)) {}
    };

    template<>
    class Coin<CoinClass::ada> : public CoinBase<CoinClass::ada> {
    public:
        Coin(const std::string& _name) : Base(_name) {}
        Coin(std::string&& _name) : Base(std::move(_name)) {}
    };

    template<>
    class Coin<CoinClass::xin> : public CoinBase<CoinClass::xin> {
    public:
        Coin(const std::string& _name) : Base(_name) {}
        Coin(std::string&& _name) : Base(std::move(_name)) {}
    };

    template<>
    class Coin<CoinClass::xtz> : public CoinBase<CoinClass::xtz> {
    public:
        Coin(const std::string& _name) : Base(_name) {}
        Coin(std::string&& _name) : Base(std::move(_name)) {}
    };

    template<>
    class Coin<CoinClass::eos> : public CoinBase<CoinClass::eos> {
    public:
        Coin(const std::string& _name) : Base(_name) {}
        Coin(std::string&& _name) : Base(std::move(_name)) {}
    };

    template<>
    class Coin<CoinClass::xchain> : public CoinBase<CoinClass::xchain> {
    public:
        Coin(const std::string& _name) : Base(_name) {}
        Coin(std::string&& _name) : Base(std::move(_name)) {}
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