#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

int main(int argc, char* argv[]) {


    //Command Line Interface Optionality ##############################################################################################################################################################
    std::vector<std::string> CLI_control;
    std::vector<int> CLI_control_index;
    std::vector<std::string> CLI_optionality;
    int num_control{0};

    for (int i{1}; i < argc; i++) {
        if (argv[i][0] == '-') {
            CLI_control.push_back(argv[i]);
            CLI_control_index.push_back(i);
            num_control++;
            if ((i < argc - 1) && (argv[i+1][0] != '-')) {
                CLI_optionality.push_back(argv[i+1]);
            } else {
                CLI_optionality.push_back("UNREPLICATABLEPLACEHOLDERKEYTHINGY258832579823583shg127fha917sj9hh7dh2iksh2fibd");
            }
        }
    }

    bool help_called{false}; 
    bool version_called{false};
    bool input_called(false);
    bool output_called{false};
    std::string input_name{""};
    std::string output_name{""};
    for (int i{0}; i < CLI_control.size(); i++) {
        if (CLI_control[i] == "-h" || CLI_control[i] == "--help") {
            if (help_called == false) {std::cout<<"mpags-cipher is an executable which applies a simple ciper to the content of a specified input .txt file, returning a ciphered output .txt file.\n Command line inputs to call alongside this executable are:\n"<<std::endl;}
            if (help_called) {std::cout<<"--help/-h functionality already called: ignoring excess calls of this function"<<std::endl;}
            help_called = true;
        } else if (CLI_control[i] == "-v" || CLI_control[i] == "--version") {
            if (version_called == false) {std::cout<<"The version of mpags-cipher being called is version XXXX"<<std::endl;}
            if (version_called) {std::cout<<"--version/-v functionality already called: ignoring excess calls of this function"<<std::endl;}
            version_called = true;
        } else if (CLI_control[i] == "-i" || CLI_control[i] == "--input") {
            //ADD FUNCITONALITY FOR NULL FILLING AFTER -i
            if (input_called == false) {input_name = CLI_optionality[i];}
            if (input_called) {std::cout<<"--input/-i functionality already called: ignoring excess calls of this function"<<std::endl;}
            if (CLI_optionality[i] == "UNREPLICATABLEPLACEHOLDERKEYTHINGY258832579823583shg127fha917sj9hh7dh2iksh2fibd") {std::cout<<"No valid file name found for -i/--input optionality, defaulting to input.txt.\nPlease ensure the filename argument does not begin with '-'"<<std::endl; input_name = "input.txt";}
            input_called = true;
        } else if (CLI_control[i] == "-o"|| CLI_control[i] == "--output") {
            //ADD FUNCITONALITY FOR NULL FILLING AFTER -O
            if (output_called == false) {output_name = CLI_optionality[i];}
            if (output_called) {std::cout<<"--output/-o functionality already called: ignoring excess calls of this function"<<std::endl;}
            if (CLI_optionality[i] == "UNREPLICATABLEPLACEHOLDERKEYTHINGY258832579823583shg127fha917sj9hh7dh2iksh2fibd") {std::cout<<"No valid file name found for -o/--ouput optionality, defaulting to output.txt.\nPlease ensure the filename argument does not begin with '-'"<<std::endl; output_name = "output.txt";}
            output_called = true;
        } else { //unrecognised optionality, break code
            std::cout<<CLI_control[i]<<"is an unrecognised command line optionality\nExiting now...\nExiting now...\nExiting now..."<<std::endl;
            return 0;
        }
    }
    //If neither -i nor -o present: break the code
    if (input_called == false || output_called == false) {
        if (input_called == false) {std::cout<<"ERROR: --input/-i functionality required for a correct calling of mpags-cipher"<<std::endl;}
        if (output_called == false) {std::cout<<"ERROR: --output/-o functionality required for a correct calling of mpags-cipher"<<std::endl;}
        std::cout<<"Ending executable prematurely...\nEnding executable prematurely...\nEnding executable prematurely...\nEnding executable prematurely...\n"<<std::endl;
        return 0;
    }
    //Command Line Interface Optionality ##############################################################################################################################################################
    //Read input file #################################################################################################################################################################################
    //Check if input and output names of .txt file type
    size_t dot_pos_input = input_name.find_last_of('.');
    size_t dot_pos_output = output_name.find_last_of('.');
    if (dot_pos_input != std::string::npos) { //test input is of .txt type
        std::string input_type = input_name.substr(dot_pos_input);
        if (input_type == ".txt") {
            std::cout<<"\nSearching for input: "<<input_name<<"."<<std::endl;
        } else {
            std::cout<<"ERROR: input file not of type .txt"<<std::endl;
            return 0;
        }
    } else {
        std::cout<<"ERROR: input file not of type .txt"<<std::endl;
        return 0;
    }
    if (dot_pos_output != std::string::npos) { //test output is of .txt type
        std::string output_type = output_name.substr(dot_pos_output);
        if (output_type == ".txt") {
            std::cout<<"Searching for output: "<<output_name<<"."<<std::endl;
        } else {
            std::cout<<"ERROR: output file not of type .txt"<<std::endl;
            return 0;
        }
    } else {
        std::cout<<"ERROR: output file not of type .txt"<<std::endl;
        return 0;
    }

    //Read input and assemble cipher
    std::ifstream inputFile(input_name);
    std::string cipher_input{""};
    std::string file_line{""};
    if (!inputFile) {
        std::cout<<"ERROR: input file name unrecognised, please ensure it is in the format: input.txt"<<std::endl;
        return 0;
    } else {
        while (std::getline(inputFile,file_line)) {
            cipher_input += file_line;
        }
        inputFile.close();
    }
    //Return error if input is empty
    if (cipher_input == "") {"ERROR: input file provided no cipher input to act on"; return 0;}
    //Return warning and ask for verification if output file has content
    std::ifstream outputFile(output_name);
    char choice;
    bool overwrite_trigger{true};
    if (outputFile) {
        std::cout<<"WARNING: existant output file of the same name. Do you wish to overwrite this file [y/n]?"<<std::endl;
        std::cin >> choice;
        while (overwrite_trigger) {
            if (choice == 'y' || choice == 'Y') {
                std::cout<<"\nContinuing with overwrite of "<<output_name<<std::endl;
                overwrite_trigger = false;
            } else if (choice == 'n' || choice == 'N') {
                std::cout<<"ABORTING: Due to user choice not to overwrite current "<<output_name<<std::endl;
                overwrite_trigger = false;
                return 0;
            } else {
                std::cout<<"\nPlease enter either 'y' or 'n' for continuation or abortion respecitively"<<std::endl;
            }
        }
    }
    outputFile.close();
    //Read input file #################################################################################################################################################################################
    //Apply cipher alterations#########################################################################################################################################################################
    std::cout<<"\nUnaltered cipher input is:\n"<<cipher_input<<std::endl;
    //Apply cipher alterations#########################################################################################################################################################################
    //ignore non-alpha numeric
    std::string cipher_output{""};
    for (std::size_t i{0}; i < cipher_input.size(); i++) { //if num, switch to letter, then capitalize
        if (std::isalnum(cipher_input[i])) {
            switch (cipher_input[i]) {
                case '0':
                    cipher_output += "ZERO";
                    break;
                case '1':
                    cipher_output += "ONE";
                    break;
                case '2':
                    cipher_output += "TWO";
                    break;
                case '3':
                    cipher_output += "THREE";
                    break;
                case '4':
                    cipher_output += "FOUR";
                    break;
                case '5':
                    cipher_output += "FIVE";
                    break;
                case '6':
                    cipher_output += "SIX";
                    break;
                case '7':
                    cipher_output += "SEVEN";
                    break;
                case '8':
                    cipher_output += "EIGHT";
                    break;
                case '9':
                    cipher_output += "NINE";
                    break;
                default:
                    cipher_output += std::toupper(cipher_input[i]);
            }
        }
    }
    //capitalize
    //convert numbers to 
    //Send to output file##############################################################################################################################################################################
    std::cout<<"\nAltered cipher output is:\n"<<cipher_output<<std::endl;
    //Send to output file##############################################################################################################################################################################
}