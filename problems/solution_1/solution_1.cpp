#include <iostream>

// Super helpful assert + message funtionality from https://stackoverflow.com/a/3767883
#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            std::terminate(); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

auto multiples_of_3_and_5(int max) {
    auto sum = 0;

    for (auto i = 0; i < max; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum = sum + i;
        }
    }
    
    return sum;
}

int main() {
    // auto multiples_10 = multiples_of_3_and_5(10);
    // ASSERT(multiples_10 == 23, "multiples returned " << multiples_10 << ", but were expecting 23");

    // auto multiples_20 = multiples_of_3_and_5(20);
    // ASSERT(multiples_20 == 78, "multiples returned " << multiples_20 << ", but were expecting 78");

    // auto multiples_100 = multiples_of_3_and_5(1000);
    // ASSERT(multiples_100 == 233168, "multiples returned " << multiples_100 << ", but were expecting 233168");

    return multiples_of_3_and_5(1000);
}