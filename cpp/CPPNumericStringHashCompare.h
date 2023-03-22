//
//  CPPNumericStringHashCompare.hpp
//  react-native-native-video
//
//  Created by Switt Kongdachalert on 4/1/2565 BE.
//

#ifndef CPPNumericStringHashCompare_hpp
#define CPPNumericStringHashCompare_hpp

#include <string_view>
#include <iostream>
#include <string>

// String hash switch case implementation as seen here
// https://learnmoderncpp.com/2020/06/01/strings-as-switch-case-labels/
inline constexpr auto hash_djb2a(const std::string_view sv) {
    unsigned long hash{ 5381 };
    for (unsigned char c : sv) {
        hash = ((hash << 5) + hash) ^ c;
    }
    return hash;
}
 
inline constexpr auto operator"" _sh(const char *str, size_t len) {
    return hash_djb2a(std::string_view{ str, len });
}

#endif /* CPPNumericStringHashCompare_hpp */
