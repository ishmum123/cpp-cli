#include "autoparser.h"
#include <rfl.hpp>
#include <rfl/json.hpp>
#include <string>
#include <vector>

template <typename T>
T autoparse(int argc, char *argv[], std::vector<std::string> input_lines) {
    T t = {};
    const auto view = rfl::to_view(t);
    view.apply([](const auto&f ){
        std::cout<<f.name()<<": "<< rfl::json::write(f.value())<<std::endl;
    });
    return t;
}

void dummy(){
    // Requires explicit instantiation. Otherwise fails to find
    // the definition for specific instance
    std::vector<std::string> input_lines;
    char *argv[] = {0};
    auto c = autoparse<Config>(1, argv, input_lines);
}