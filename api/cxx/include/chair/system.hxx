/**
*  @file request.hxx
*  @brief
*
*  @author exidna
*/

# ifndef CHAIR_SYSTEM_HXX
# define CHAIR_SYSTEM_HXX

# include <optional>
# include <string>

# include <cpr/cpr.h>

namespace chair {
    class DataParser {
        bool is_parsed;
        std::string source;

        using DataType = std::string;
        DataType data;
    public:
        inline explicit DataParser(const std::string& src) {
            source = src;
            is_parsed = false;
        }

        inline void parse() {
            data = source; // TODO: parse json response
            source.clear();
            is_parsed = true;
        }

        inline const DataType& get_data() {
            if (!is_parsed) {
                parse();
            }
            return data;
        }

        inline const DataType& get_data_unchecked() {
            return data;
        }
    };

    using Response = std::optional<DataParser>;

    class System {
    private:
        const std::string host_name = "https://api.blockchair.com/";

    public:
        // for Singleton
        System() = default;

        // no copy
        System(const System&) = delete;
        System& operator=(const System&) = delete;

        // no move
        System(System&&) = delete;
        System& operator=(System&&) = delete;

        template<typename... Args>
        inline Response request(const std::string& url, Args&&... args) const {
            auto response = cpr::Get(cpr::Url{host_name + url}, std::forward(args));
            if (response.status_code == 0) return {/*empty*/};
            return DataParser{response.text};
        }
    };
}

# endif // !CHAIR_SYSTEM_HXX