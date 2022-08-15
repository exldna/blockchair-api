/**
 *  @file chair.hxx
 *  @brief chair main header
 *
 *  @author exidna
 */

# ifndef CHAIR_HXX
# define CHAIR_HXX

# include <utils/utils.hxx>

/// @brief chair namespace
namespace chair {
    /// @return chair version
    utils::Version get_version();
}

# include <chair/coins.hxx>
# include <chair/api.hxx>

# endif // !CHAIR_HXX