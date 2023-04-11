#include <iostream>
#include <vector>
#include <algorithm>
 
// predicado binario
struct comp
{
    template<typename T>
    bool operator()(const T &l, const T &r) const {
        return l > r;
    }
};
 
int main(void)
{
    std::vector<int> v = { 3, 5, 2, 4, 7 };
 
    std::sort(v.begin(), v.end(), comp());
 
    for (const auto &i: v) {
        std::cout << i << ' ';
    }
    std::cout << "\n";
 
    return 0;
}