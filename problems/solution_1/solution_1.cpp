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

auto multiples(int max) {
    auto sum = 0;

    for (auto i = 0; i < max; i++) {
        bool mutliple_of_threes = (i % 3) == 0;
        bool multiple_of_fives = (i % 5) == 0;

        if (mutliple_of_threes && multiple_of_fives) {
            sum = sum + i;
            continue;
        } else if (multiple_of_fives) {
            sum = sum + i;
        } else if (mutliple_of_threes) {
            sum = sum + i;
        }
    }
    
    return sum;
}

auto multiplesv2(int max) {
    auto sum = 0;
    auto i = 1;
    bool multiples_remaining = true;

    while (multiples_remaining) {
        auto multiple_three = i * 3;
        auto multiple_five = i * 5;

        if (multiple_three == multiple_five) {
            sum += multiple_three;
            i += 1;
        } else if (multiple_five ) {
            /* code */
        }
        
    }
}

int main() {
    auto multiples_10 = multiples(10);
    ASSERT(multiples_10 == 23, "multiples returned " << multiples_10 << ", but were expecting 23");

    auto multiples_20 = multiples(20);
    ASSERT(multiples_20 == 78, "multiples returned " << multiples_20 << ", but were expecting 78");

    auto multiples_100 = multiples(100);
    ASSERT(multiples_100 == 78, "multiples returned " << multiples_100 << ", but were expecting 78");

    return 0;
}