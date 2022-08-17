/**
 *  @file coins.hxx
 *  @brief contains API supported coins defenitions
 *
 *  @author exidna
 */

# ifndef CHAIR_COINS_HXX
# define CHAIR_COINS_HXX

# include <chair/system.hxx>

# include <utils/patterns.hxx>

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

    class CoinBase {
    protected:
        static inline chair::System& system = utils::ptt::Singleton<chair::System>::get();
    public:
        const std::string name;

        inline explicit CoinBase(const std::string& _name) : name(_name) {}
        inline CoinBase(const char* _name) : name(_name) {}

        // no copy
        CoinBase(const CoinBase&) = delete;
        CoinBase& operator=(const CoinBase&) = delete;

        // no move
        CoinBase(CoinBase&&) = delete;
        CoinBase& operator=(CoinBase&&) = delete;
    };

    template<CoinClass _coin_class>
    class Coin {};

    template<>
    class Coin<CoinClass::btc> : public CoinBase {
    public:
        inline explicit Coin(const std::string& _name) : CoinBase(_name) {}
        inline Coin(const char* _name) : CoinBase(_name) {}

        inline chair::Response get_stats() const {
            // https://api.blockchair.com/{:btc_chain}/stats
            return system.request(name + "/stats");
        }

        inline chair::Response get_block_info(uint height) const {
            // https://api.blockchair.com/{:btc_chain}/dashboards/block/{:height}₀
            return system.request(name + "/dashboards/block/" + std::to_string(height));
        }

        inline chair::Response get_block_info(const std::string& hash) const {
            // https://api.blockchair.com/{:btc_chain}/dashboards/block/{:hash}₀
            return system.request(name + "/dashboards/block/" + hash);
        }

        inline chair::Response get_block_info(const char* hash) const {
            // https://api.blockchair.com/{:btc_chain}/dashboards/block/{:hash}₀
            return system.request(name + "/dashboards/block/" + hash);
        }

        inline chair::Response get_transaction_info(const std::string& hash) const {
            // https://api.blockchair.com/{:btc_chain}/dashboards/transaction/{:hash}₀
            return system.request(name + "/dashboards/transaction/" + hash);
        }

        inline chair::Response get_transaction_info(const char* hash) const {
            // https://api.blockchair.com/{:btc_chain}/dashboards/transaction/{:hash}₀
            return system.request(name + "/dashboards/transaction/" + hash);
        }

        inline chair::Response get_address_info(const std::string& address) const {
            // https://api.blockchair.com/{:btc_chain}/dashboards/address/{:address}₀
            return system.request(name + "/dashboards/address/" + address);
        }

        inline chair::Response get_address_info(const char* address) const {
            // https://api.blockchair.com/{:btc_chain}/dashboards/address/{:address}₀
            return system.request(name + "/dashboards/address/" + address);
        }

        inline chair::Response get_xpub_info(const std::string& key) const {
            // https://api.blockchair.com/{:btc_chain}/dashboards/xpub/{:extended_key}
            return system.request(name + "/dashboards/xpub/" + key);
        }

        inline chair::Response get_xpub_info(const char* key) const {
            // https://api.blockchair.com/{:btc_chain}/dashboards/xpub/{:extended_key}
            return system.request(name + "/dashboards/xpub/" + key);
        }
    };

    template<>
    class Coin<CoinClass::eth> : public CoinBase {
    public:
        inline explicit Coin(const std::string& _name) : CoinBase(_name) {}
        inline Coin(const char* _name) : CoinBase(_name) {}

        inline chair::Response get_stats() const {
            // https://api.blockchair.com/{:eth_chain}/stats
            return system.request(name + "/stats");
        }

        inline chair::Response get_block_info(uint height) const {
            // https://api.blockchair.com/{:eth_chain}/dashboards/block/{:height}₀
            return system.request(name + "/dashboards/block/" + std::to_string(height));
        }

        inline chair::Response get_block_info(const std::string& hash) const {
            // https://api.blockchair.com/{:eth_chain}/dashboards/block/{:hash}₀
            return system.request(name + "/dashboards/block/" + hash);
        }

        inline chair::Response get_block_info(const char* hash) const {
            // https://api.blockchair.com/{:eth_chain}/dashboards/block/{:hash}₀
            return system.request(name + "/dashboards/block/" + hash);
        }

        inline chair::Response get_uncle_info(const std::string& hash) const {
            // https://api.blockchair.com/{:eth_chain}/dashboards/uncle/{:hash}₀
            return system.request(name + "/dashboards/uncle/" + hash);
        }

        inline chair::Response get_uncle_info(const char* hash) const {
            // https://api.blockchair.com/{:eth_chain}/dashboards/uncle/{:hash}₀
            return system.request(name + "/dashboards/uncle/" + hash);
        }

        inline chair::Response get_transaction_info(const std::string& hash) const {
            // https://api.blockchair.com/{:eth_chain}/dashboards/transaction/{:hash}₀
            return system.request(name + "/dashboards/transaction/" + hash);
        }

        inline chair::Response get_transaction_info(const char* hash) const {
            // https://api.blockchair.com/{:eth_chain}/dashboards/transaction/{:hash}₀
            return system.request(name + "/dashboards/transaction/" + hash);
        }

        inline chair::Response get_address_info(const std::string& address) const {
            // https://api.blockchair.com/{:eth_chain}/dashboards/address/{:address}₀
            return system.request(name + "/dashboards/address/" + address);
        }

        inline chair::Response get_address_info(const char* address) const {
            // https://api.blockchair.com/{:eth_chain}/dashboards/address/{:address}₀
            return system.request(name + "/dashboards/address/" + address);
        }
    };

    template<>
    class Coin<CoinClass::xpr> : public CoinBase {
    public:
        inline explicit Coin(const std::string& _name) : CoinBase(_name) {}
        inline Coin(const char* _name) : CoinBase(_name) {}

        inline chair::Response get_stats() const {
            // https://api.blockchair.com/{:xpr_chain}/stats
            return system.request(name + "/stats");
        }
    };

    template<>
    class Coin<CoinClass::xlm> : public CoinBase {
    public:
        inline explicit Coin(const std::string& _name) : CoinBase(_name) {}
        inline Coin(const char* _name) : CoinBase(_name) {}

        inline chair::Response get_stats() const {
            // https://api.blockchair.com/{:xlm_chain}/stats
            return system.request(name + "/stats");
        }
    };

    template<>
    class Coin<CoinClass::xmr> : public CoinBase {
    public:
        inline explicit Coin(const std::string& _name) : CoinBase(_name) {}
        inline Coin(const char* _name) : CoinBase(_name) {}

        inline chair::Response get_stats() const {
            // https://api.blockchair.com/{:xmr_chain}/stats
            return system.request(name + "/stats");
        }
    };

    template<>
    class Coin<CoinClass::ada> : public CoinBase {
    public:
        inline explicit Coin(const std::string& _name) : CoinBase(_name) {}
        inline Coin(const char* _name) : CoinBase(_name) {}

        inline chair::Response get_stats() const {
            // https://api.blockchair.com/{:ada_chain}/stats
            return system.request(name + "/stats");
        }
    };

    template<>
    class Coin<CoinClass::xin> : public CoinBase {
    public:
        inline explicit Coin(const std::string& _name) : CoinBase(_name) {}
        inline Coin(const char* _name) : CoinBase(_name) {}

        inline chair::Response get_stats() const {
            // https://api.blockchair.com/{:xin_chain}/stats
            return system.request(name + "/stats");
        }
    };

    template<>
    class Coin<CoinClass::xtz> : public CoinBase {
    public:
        inline explicit Coin(const std::string& _name) : CoinBase(_name) {}
        inline Coin(const char* _name) : CoinBase(_name) {}

        inline chair::Response get_stats() const {
            // https://api.blockchair.com/{:xtz_chain}/stats
            return system.request(name + "/stats");
        }
    };

    template<>
    class Coin<CoinClass::eos> : public CoinBase {
    public:
        inline explicit Coin(const std::string& _name) : CoinBase(_name) {}
        inline Coin(const char* _name) : CoinBase(_name) {}

        inline chair::Response get_stats() const {
            // https://api.blockchair.com/{:eos_chain}/stats
            return system.request(name + "/stats");
        }
    };

    template<>
    class Coin<CoinClass::xchain> : public CoinBase {
    public:
        inline explicit Coin(const std::string& _name) : CoinBase(_name) {}
        inline Coin(const char* _name) : CoinBase(_name) {}

        inline chair::Response get_stats() const {
            // https://api.blockchair.com/cross-chain/{:xchain_token}/stats
            return system.request("cross-chain/" + name + "/stats");
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