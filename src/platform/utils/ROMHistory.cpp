#include <utils/ROMHistory.h>

#include <list>
#include <unordered_map>

namespace platform::utils
{
    ROMHistory::ROMHistory(size_t capacity) : capacity(capacity) {}

    void ROMHistory::set(std::string key)
    {
        use(key);
    }

    bool ROMHistory::empty()
    {
        return recent.empty();
    }

    std::list<std::string> ROMHistory::getRecent()
    {
        return recent;
    }

    void ROMHistory::use(std::string key)
    {
        if (pos.find(key) != pos.end())
        {
            recent.erase(pos[key]);
        }
        else if (recent.size() >= capacity)
        {
            std::string old = recent.back();
            recent.pop_back();
            pos.erase(old);
        }
        recent.push_front(key);
        pos[key] = recent.begin();
    }

}