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

static void help(const po::options_description& desc) {
    cout << "I Ching Hexagram Encoder/Decoder" << std::endl << desc << std::endl;
}

static void encode_msg(po::variables_map vm) {
    Translator translator = Translator();
    bool with_substition_cipher = vm["substitution-cipher"].as<bool>();
    cout << translator.encode(vm["encode"].as<string>(), with_substition_cipher) << endl;
}

static void decode_msg(po::variables_map vm) {
    Translator translator = Translator();
    bool keyed = vm.count("key") || vm.count("k");
    
    if (keyed) {
        cout << translator.decode(vm["decode"].as<string>(), vm["key"].as<string>()) << endl;
    } else {
        cout << translator.decode(vm["decode"].as<string>()) << endl;
    }
}

int main(int argc, char** argv)
{
    string encode = "";
    string decode = "";
    string key = "";
    bool substitution_cipher = false;
    
    try { 
        po::options_description desc("Options"); 
        desc.add_options() 
            ("help,h", "Print help messages") 
            ("encode,e", po::value(&encode), "Encode message") 
            ("decode,d", po::value(&decode), "Decode message")
            ("substitution-cipher,s", po::bool_switch(&substitution_cipher), "Use substitution cipher")
            ("key,k", po::value(&key), "Key for decoding substitution cipher"); 
        po::variables_map vm; 
        
        try { 
            po::store(po::parse_command_line(argc, argv, desc), vm);
    
            if (vm.count("help") || vm.count("h")) { 
                help(desc);
            } else if (vm.count("encode") || vm.count("e")) {
                encode_msg(vm);
            } else if (vm.count("decode") || vm.count("d")) {
                decode_msg(vm);
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
