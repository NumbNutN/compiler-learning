#include <iostream>
#include <regex>
#include <string>

using namespace std;
int main(){

    std::string inputData = "3av";

    std::regex regexStr("^[a-zA-Z_]\\w{0,1000}$");
    std::smatch matchResult;

    if(std::regex_match(inputData,matchResult,regexStr)){
        std::cout << "Match" <<std::endl;
    }
    else{
        std::cout <<"Not match" << std::endl;
    }
    return 0;

}