#include <list>
#include <unordered_map>

namespace platform::utils
{
    class ROMHistory
    {
    public:
        ROMHistory(size_t capacity);

        void set(std::string key);

        bool empty();

        std::list<std::string> getRecent();

    private:
        void use(std::string key);

        size_t capacity;
        std::list<std::string> recent;
        std::unordered_map<std::string, std::list<std::string>::iterator> pos;
    };
}