#pragma once

#include <string>

using std::string;

namespace Util
{
    namespace Random
    {
        int random_generator(int i);
    }
    
    namespace Base64
    {
        string b64_encode(const string& msg);
        string b64_decode(const string& msg);
    }
    
    namespace String
    {
        string rtrim(const string& s, const char* t = " \t\n\r\f\v");
        string ltrim(const string& s, const char* t = " \t\n\r\f\v");
        string trim(const string& s, const char* t = " \t\n\r\f\v");
    }
}
