# include <chair/chair.hxx>
# include <config/version.hxx>

# include <curl/curl.h>

utils::Version chair::get_version() {
    return { CHAIR_VERSION };
}
