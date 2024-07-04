#include <rfl.hpp>
#include <rfl/json.hpp>
#include <absl/status/statusor.h>
#include <string>
#include <vector>
#include "config.h"
#include <type_traits>


struct Config;
template <typename T>
absl::StatusOr<T> autoparse(int argc, char *argv[], std::vector<std::string> input_lines) {
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

    // TODO: Validation
    // Now I would like to check if T has a member of type flag

    auto val_res = validate(argc,argv);


    if(std::is_same<T, Config>::value){
        std::cout<<"T is of type Config"<<std::endl;

    }

    const auto view = rfl::to_view<T>(t);
    view.apply([](const auto&f ){
        std::cout<<f.name()<<": "<< rfl::json::write(f.value())<<std::endl;
    });
    return t;
}

bool isInteger(string str){
    if(str.starts_with('-')){
        str.erase(str.begin());
    }
    return std::all_of(str.begin(), str.end(),::isdigit);
}

absl::Status validate(int argc, char *argv[]){
    if(strcmp("--single",argv[0])){
        if(strcmp("true",argv[1]) || strcmp("false", argv[1]))
            return absl::OkStatus();
        else return absl::InvalidArgumentError(absl::StrFormat("single (boolean) - %s is not a valid input. Please see --help",argv[1]));
    }
    else if(strcmp("--integer", argv[0])){
        if(isInteger(static_cast<string>(argv[1])))
            return absl::OkStatus();
        else return absl::InvalidArgumentError(absl::StrFormat("integer - %s is not a valid input. Please see --help",argv[1]));
    }
    else if(strcmp("--string",argv[0])){
        return absl::OkStatus();
    }      
    else return absl::InvalidArgumentError(absl::StrFormat("%s - %s is not a valid input. Please see --help",argv[0],argv[1]));  
}