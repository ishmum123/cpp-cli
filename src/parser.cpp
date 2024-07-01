#include "parser.h"
#include <string>
#include <vector>

bool validate(char *argv[]);

absl::StatusOr<Config> parse(int argc, char *argv[], std::vector<std::string> input_lines) {

    if(validate(argv))
        return Config(false, input_lines);
    else
        return absl::InvalidArgumentError("invalid flag");

}

bool isInteger(string str){
    return std::all_of(str.begin(), str.end(),::isdigit);
}

bool isString(string str){
    
}

bool validate(char *argv[]){
    if(strcmp("--bool",argv[0])){
        if(strcmp("true",argv[1]))
            return true;
        else return false;
    }
    else if(strcmp("--integer",argv[0])){
        if(isInteger(static_cast<string>(argv[1])))
            return true;
        else return false;
    }
    else if(strcmp("--string",argv[0])){
        if(isString(static_cast<string>(argv[1])))
            return true;
        else return false;
    }

        
}