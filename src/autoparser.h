#include <rfl.hpp>
#include <rfl/json.hpp>
#include <absl/status/statusor.h>
#include <string>
#include <vector>
#include "config.h"
#include <type_traits>


struct Config;

absl::Status validate(std::vector<std::pair<string,string>>);


template <typename T>
absl::StatusOr<T> autoparse(int argc, char *argv[], std::vector<std::string> input_lines) {
    T t = {};
    std::vector<std::pair<string,string>> types_of_members;
    for (const auto& f : rfl::fields<T>()) {
        types_of_members.emplace_back(std::make_pair(f.name(),f.type()));
    }

    std::vector<std::pair<string,string>> flags_with_argument;
    for(int i=1;i<argc;i++){
        auto flag = static_cast<string>(argv[i]);
        flag.erase(0,2);
        auto argument   = static_cast<string>(argv[++i]);
        std::cout<<flag <<" "<<argument<<" \n";
        flags_with_argument.emplace_back(flag,argument);
    }

    // TODO: Validation
    // Now I would like to check if T has a member of type flag

    auto val_res = validate(flags_with_argument);
    if(val_res.ok()){
        std::cout<<"VALID"<<std::endl;
        
        const auto view = rfl::to_view<T>(t);
       
        for(auto &flag: flags_with_argument){
            
            if(strcmp(flag.first.data(), "single")){
                bool op;
                std::istringstream(flag.second)>>std::boolalpha>>op;
                *rfl::get<"single">(view)=op;
            }
            else if(strcmp(flag.first.data(),"thread")){
                int val = atoi(flag.second.data());
                std::cout<<flag.first<<"val "<<flag.second<<std::endl;
                *rfl::get<"thread">(view)=val;
            }
        }

        view.apply([](const auto&f ){
            std::cout<<f.name()<<": "<< rfl::json::write(f.value())<<std::endl;
        });
    }
    else{
        std::cout<<val_res.message()<<std::endl;
    }

    return t;
}

bool isInteger(string str){
    if(str.starts_with('-')){
        str.erase(str.begin());
    }
    return std::all_of(str.begin(), str.end(),::isdigit);
}

absl::Status validate(std::vector<std::pair<string,string>> flags_with_argument){

    for(auto &flag : flags_with_argument){
        
        // Ensures argument is not missing 
        if(!flag.second.empty()){

            // Check types match
            if (strcmp("--single", flag.first.data())){
                if (! (strcmp("true", flag.second.data()) || strcmp("false", flag.second.data())))
                    return absl::InvalidArgumentError(absl::StrFormat("single (boolean) - %s is not a valid input. Please see --help", flag.second.data()));
            }
            else if (strcmp("--integer", flag.first.data())){
                if (! isInteger(static_cast<string>(flag.second.data())))
                    return absl::InvalidArgumentError(absl::StrFormat("integer - %s is not a valid input. Please see --help", flag.second.data()));
            }
        }
        else 
            return absl::InvalidArgumentError(absl::StrFormat("Missing argument for %s . Please see --help.",flag.first));
    }     
    return absl::OkStatus();
}