/**
 *  @file chair.hxx
 *  @brief chair welcome header
 *
 *  @author exidna
 */

# ifndef CHAIR_HXX
# define CHAIR_HXX

# include <string>
# include <utils/utils.hxx>

/// @brief chair namespace
namespace chair {
    /// @return chair version
    utils::Version get_version();
}

# endif // !CHAIR_HXX