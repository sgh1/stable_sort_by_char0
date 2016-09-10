
#include <algorithm>
#include <iostream>
#include <vector>

namespace stable_sort_by_char0
{
    //one might need to specialize this
    template<typename T>
    struct has_char0{
        static bool has(const T& t){
            return t.size() > 0;
        }
    };

    template< class RandomIt >
    void ssort_char0( RandomIt first, RandomIt last, char c )
    {
        typedef typename std::iterator_traits<RandomIt>::value_type value_t;

        std::stable_sort(first,last,
            [c](const value_t& a, const value_t& b)
            {
                if( !has_char0<value_t>::has(a) ||
                    !has_char0<value_t>::has(b))
                {
                    return a < b;
                }

                return int(a[0] == c) < int(b[0] == c);
            }
        );
    }
}

int main()
{
    std::vector<std::string> wordlist;

    wordlist.reserve(6);

    wordlist.push_back("");
    wordlist.push_back(".dir");
    wordlist.push_back("granola");
    wordlist.push_back("lamp");
    wordlist.push_back(".dev");
    wordlist.push_back("glass");

    stable_sort_by_char0::ssort_char0(
        wordlist.begin(),wordlist.end(),'.');

    for(const std::string& s : wordlist){
        std::cout << s << "\n";
    }

    return 0;
}
