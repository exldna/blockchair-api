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

# include <utils/patterns.hxx>

namespace chair {
    struct ResponseData {
        std::string header;
        std::string data;
    };

    using Response = std::optional<ResponseData>;

    class System : public utils::ptt::Singleton<System> {
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

        inline Response request(const std::string& url) {
            auto response = cpr::Get(cpr::Url{host_name + url});
            if (response.status_code == 0) return {/*empty*/};
            return ResponseData{"", response.text};
        }
    };
}

# endif // !CHAIR_SYSTEM_HXX