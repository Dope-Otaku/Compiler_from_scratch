#include <iostream>
#include <fstream>
#include <sstream>

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




    return EXIT_SUCCESS;
}