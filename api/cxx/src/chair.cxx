# include <chair/chair.hxx>
# include <config/version.hxx>

# include <curl/curl.h>
# include <utils/types.hxx>

using utils::types::deffer_t;

utils::Version chair::get_version() {
    return { CHAIR_VERSION };
}
