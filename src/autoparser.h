#include <rfl.hpp>
#include <rfl/json.hpp>
#include <string>
#include <vector>
#include "config.h"
#include <type_traits>


struct Config;
template <typename T>
T autoparse(int argc, char *argv[], std::vector<std::string> input_lines) {
    T t = {};
    std::vector<std::pair<string,string>> types_of_members;
    for (const auto& f : rfl::fields<T>()) {
        types_of_members.emplace_back(std::make_pair(f.name(),f.type()));
    }

    std::vector<std::pair<string,string>> flags_with_argument;
    for(int i=0;i<argc-1;i++){
        auto flag = static_cast<string>(argv[i]);
        auto argument   = static_cast<string>(argv[i++]);
        flags_with_argument.emplace_back(flag,argument);
    }

    // Validation
    // Now I would like to check if T has a member of type flag






    const auto view = rfl::to_view<T>(t);
    view.apply([](const auto&f ){
        std::cout<<f.name()<<": "<< rfl::json::write(f.value())<<std::endl;
    });
    return t;
}
