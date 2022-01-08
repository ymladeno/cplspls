/*
 * map.cpp
 *
 *  Created on: Jan 8, 2022
 *      Author: osboxes
 */

#include <functional>
#include <string>

template<typename Key, typename Value, typename Compare = std::less<Key>>
class map {
public:
    map() {}
    map(Compare c) : cmp{c} {}

private:
    Compare cmp{};
};

bool insensitive(const std::string& x, const std::string& y) {
    return false;
}

int main() {
    map<std::string, int> m1;
    map<std::string, int, std::greater<std::string>> m2;

    using Cmp = bool(*)(const std::string&, const std::string&);
    map<std::string, int, Cmp> m4{insensitive};
    map<std::string, int, Cmp> m5{[](const std::string& a, const std::string& b) { return a>b; } };
    auto cmp = [](const std::string& x, const std::string& y) { return x<y; };
}
