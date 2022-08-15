# include <chair/chair.hxx>
# include <config/version.hxx>

# include <curl/curl.h>
# include <cpr/cpr.h>

# include <iostream>

using utils::types::deffer_t;

utils::Version chair::get_version() {
    std::cout << cpr::Get(cpr::Url{ "https://api.blockchair.com/stats" }).text << '\n';
    return { CHAIR_VERSION };
}
