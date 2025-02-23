#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>


enum class TokenType{
    _return,
    int_lit,
    semi
};


struct Token{
    TokenType type;
    std::optional<std::string> value {};
};


std::vector<Token> tokenize(const std::string& str){
    std::vector<Token> tokens; 
    std::string buf;
    for (int i =0; i<str.length(); i++){
        // std::cout << c << std::endl;
        char c = str.at(i);
        if(std::isalpha(c)) {
            buf.push_back(c);
            i++;
            while (std::isalnum(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;


            if(buf == "return"){
                tokens.push_back({.type = TokenType::_return});
                buf.clear();
                continue;
            } else {
                std::cerr << "You F** up!" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else if (std::isdigit(c)) {
            buf.push_back(c);
            i++;
            while (std::isdigit(str.at(c))) {
                buf.push_back(str.at(c));
                i++;
            }
            i--;
            tokens.push_back({.type = TokenType::int_lit, .value = buf});
            buf.clear();
        }
        else if (c == ';'){
            tokens.push_back({.type = TokenType::semi});
        }
        else if(std::isspace(c)) {
            continue;
        } else {
            std::cerr << "You F** up!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return tokens;
}



int main(int argc, char* argv[]){

    if (argc!=2){
        std::cerr << "Incorrect Usage, Correct usage is..." << std::endl;
        std::cerr << "com <input.co>" << std::endl;
        return EXIT_FAILURE;
    }


    // reading a file
    std::string contents;
    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        if(!input){
            std::cerr << "Error: Unable to open the file" << argv[1] << std::endl;
            return EXIT_FAILURE;
        }
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }



    std::cout << contents << std::endl;



    std::vector<Token> tokens = tokenize(contents);
    return EXIT_SUCCESS;
}