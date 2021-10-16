#include <string>

namespace platform::utils
{
    std::string base_name(std::string const &path, std::string const &delims = "/\\")
    {
        return path.substr(path.find_last_of(delims) + 1);
    }

    std::string remove_extension(std::string const &filename)
    {
        typename std::string::size_type const p(filename.find_last_of('.'));
        return p > 0 && p != std::string::npos ? filename.substr(0, p) : filename;
    }
}