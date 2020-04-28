#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>

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

static inline bool file_exists(const string& fname)
{
  struct stat buffer;
  return (stat (fname.c_str(), &buffer) == 0); 
}

static void help(const po::options_description& desc)
{
    cout << "I Ching Hexagram Encoder/Decoder" << std::endl << desc << std::endl;
}

static void encode_msg(po::variables_map vm)
{
    Translator translator = Translator();
    bool with_substition_cipher = vm["substitution-cipher"].as<bool>();
    bool with_input_file = vm["input"].as<bool>();
    string plaintext = vm["encode"].as<string>();
    
    if (with_input_file) {
        string fname = vm["encode"].as<string>();
        std::ifstream ifs(fname);
        
        if (file_exists(fname)) {
            string file_contents((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
            plaintext = file_contents;
        } else {
            cerr << "ERROR: File '" << fname << "' does not exist.\n";
            exit(ERROR_IN_COMMAND_LINE);
        }
    }
    
    cout << translator.encode(plaintext, with_substition_cipher) << endl;
}

static void decode_msg(po::variables_map vm)
{
    Translator translator = Translator();
    bool keyed = vm.count("key") || vm.count("k");
    
    // Set encoded to fi
    string encoded = vm["decode"].as<string>();
    
    if (vm.count("input") || vm.count("i")) {
        std::ifstream ifs(vm["decode"].as<string>());
        string file_contents((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        encoded = file_contents;
    }
    
    if (keyed) {
        cout << translator.decode(encoded, vm["key"].as<string>()) << endl;
    } else {
        cout << translator.decode(encoded) << endl;
    }
}

int main(int argc, char** argv)
{
    string encode = "";
    string decode = "";
    string key = "";
    bool substitution_cipher = false;
    bool file = false;
    
    try { 
        po::options_description desc("Options"); 
        desc.add_options() 
            ("help,h", "Print help messages") 
            ("encode,e", po::value(&encode), "Encode message") 
            ("decode,d", po::value(&decode), "Decode message")
            ("substitution-cipher,s", po::bool_switch(&substitution_cipher), "Use substitution cipher")
            ("input,i", po::bool_switch(&file), "With input file")
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
