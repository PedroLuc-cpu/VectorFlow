#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &v)
{
    s.put('{');
    for (char comma[]{'\0', ' ', '\0'}; const auto &e : v)
        s << comma << e, comma[0] = ',';
    return s << "}\n";
}

int main(int argc, char *argv[])
{
    std::vector<std::string> words1{"o", "sapo", "é", "também", "amaldiçoado"};
    std::cout << "1: " << words1;

    std::vector<std::string> words2(words1.begin(), words1.end());
    std::cout << "2: " << words2;

    std::vector<std::string> words3(words1);
    std::cout << "3: " << words3;

    std::vector<std::string> words4(5, "Creduuu");
    std::cout << "4: " << words4;

    auto const rg = {"cat",
                     "cow",
                     "crow"};

#ifdef __cpp_lib_containers_ranges
    std::vector<std::string> words5(std::from_range, rg);
#else
    std::vector<std::string> words5(rg.begin(), rg.end()); // overload (5)
#endif // DEBUG
    std::cout << "5: " << words5;
}
