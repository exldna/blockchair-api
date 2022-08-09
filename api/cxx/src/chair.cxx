# include <chair/chair.hxx>
# include <config/version.hxx>

utils::Version chair::get_version() {
    return { CHAIR_VERSION };
}
