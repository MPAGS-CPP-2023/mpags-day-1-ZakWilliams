#include <iostream>
#include <string>
#include <vector>
#include <cctype>

//add together aspects

int main(int argc, char* argv[]) {
    const std::vector<std::string> cmdLineArgs { argv, argv+argc };

    char in_char{'x'};
    std::string in_str{""};
    std::string out_str{""};

    if (cmdLineArgs.size() > 1) {
        for (std::size_t i{1}; i < cmdLineArgs.size(); i++) {
            std::cout << cmdLineArgs[i] << std::endl;
            in_str += cmdLineArgs[i];
        }
    }
    while(std::cin >> in_char) {
        in_str += in_char;
    }

    while(std::cin >> in_char) { //Excecutes a loop over each given character: printing each of them out (over CHARACTERS in STRING)
        switch (in_char) {
            case '0':
                out_str += "ZERO";
                break;
            case '1':
                out_str += "ONE";
                break;
            case '2':
                out_str += "TWO";
                break;
            case '3':
                out_str += "THREE";
                break;
            case '4':
                out_str += "FOUR";
                break;
            case '5':
                out_str += "FIVE";
                break;
            case '6':
                out_str += "SIX";
                break;
            case '7':
                out_str += "SEVEN";
                break;
            case '8':
                out_str += "EIGHT";
                break;
            case '9':
                out_str += "NINE";
                break;
            }
        if (std::isalpha(in_char)) {
            out_str += std::toupper(in_char);            //std::cout << static_cast<char>(std::toupper(in_char)) << std::endl;
        }
    }
    std::cout << "\n"<< out_str <<"\n";
}