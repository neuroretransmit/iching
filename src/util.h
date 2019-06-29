#pragma once

#include <string>

using std::string;

namespace util
{
    namespace rand
    {
        int random_generator(int i);
    }
    
    namespace b64
    {
        string b64_encode(const string& msg);
        string b64_decode(const string& msg);
    }
    
    namespace str
    {
        string rtrim(const string& s, const char* t = " \t\n\r\f\v");
        string ltrim(const string& s, const char* t = " \t\n\r\f\v");
        string trim(const string& s, const char* t = " \t\n\r\f\v");
    }
}
