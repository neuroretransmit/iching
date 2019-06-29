#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include "translator.h"

using std::cerr;
using std::cout;
using std::endl;

namespace po = boost::program_options;

enum {
  SUCCESS,
  ERROR_IN_COMMAND_LINE,
  ERROR_UNHANDLED_EXCEPTION
};

int main(int argc, char** argv)
{
    string encode = "";
    string decode = "";
    string key = "";
    bool shift_cipher = false;
    
    try { 
        po::options_description desc("Options"); 
        desc.add_options() 
            ("help,h", "Print help messages") 
            ("encode,e", po::value(&encode), "Encode message") 
            ("decode,d", po::value(&decode), "Decode message")
            ("shift-cipher,s", po::bool_switch(&shift_cipher), "Use shift cipher")
            ("key,k", po::value(&key), "Key for decoding shift cipher"); 
        po::variables_map vm; 
        
        try { 
            po::store(po::parse_command_line(argc, argv, desc), vm); // can throw 
    
            if (vm.count("help") || vm.count("h")) { 
                std::cout << "I Ching Hexagram Encoder/Decoder" << std::endl 
                          << desc << std::endl; 
                return SUCCESS; 
            } else if (vm.count("encode") || vm.count("e")) {
                Translator translator = Translator();
                
                if (vm["shift-cipher"].as<bool>()) {
                    cout << translator.encode(vm["encode"].as<string>(), true) << endl;
                } else {
                    cout << translator.encode(vm["encode"].as<string>(), false) << endl;
                }
            } else if (vm.count("decode") || vm.count("d")) {
                Translator translator = Translator();
                
                if (vm.count("key") || vm.count("k")) {
                    cout << translator.decode(vm["decode"].as<string>(), vm["key"].as<string>()) << endl;
                } else {
                    cout << translator.decode(vm["decode"].as<string>()) << endl;
                }
            }
        
            po::notify(vm);
        } catch(po::error& e) { 
            cerr << "ERROR: " << e.what() << std::endl << std::endl; 
            cerr << desc << std::endl; 
            return ERROR_IN_COMMAND_LINE; 
        } 
    } catch(std::exception& e) { 
        cerr << "Unhandled Exception reached the top of main: " 
                  << e.what() << ", application will now exit" << std::endl;
        return ERROR_UNHANDLED_EXCEPTION; 
    
    } 
    
    return SUCCESS;   
    
}
