#include "parser.h"
#include <string>
#include <vector>
#include <sstream>

absl::Status validate(int argc, char *argv[]);

absl::StatusOr<Config> parse(int argc, char *argv[], std::vector<std::string> input_lines) {

    auto status = validate(argc,argv);
    if(status.ok()){
        bool single;
        istringstream(argv[1])>>std::boolalpha>>single;
        return Config(single, input_lines);
    }
    else {
        return status;
    }

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