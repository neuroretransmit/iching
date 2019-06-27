#pragma once

#include <iostream>
#include <random>
#include <sstream>

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/remove_whitespace.hpp>
#include <boost/archive/iterators/transform_width.hpp>

using namespace boost::archive::iterators;
using std::cerr;
using std::cout;
using std::endl;
using std::string;

namespace Util
{
    namespace Random
    {
        int random_generator(int i)
        {
            return std::rand() % i;
        }
    }
    
    namespace Base64
    {
        string b64_encode(const string& msg)
        {
            std::stringstream os;
            typedef base64_from_binary<transform_width<const char*, 6, 8>> base64_text;

            std::copy(
                base64_text(msg.c_str()),
                base64_text(msg.c_str() + msg.size()),
                std::ostream_iterator<char>(os));
            return os.str();
        }

        string b64_decode(const string& msg)
        {
            typedef transform_width<binary_from_base64<remove_whitespace<std::string::const_iterator>>, 8, 6> ItBinaryT;
            string output = "";
            string padded = msg;
            
            try {
                size_t num_pad_chars((4 - msg.size() % 4) % 4);
                padded.append(num_pad_chars, '=');
                size_t pad_chars(std::count(padded.begin(), padded.end(), '='));
                std::replace(padded.begin(), padded.end(), '=', 'A');
                std::string output(ItBinaryT(padded.begin()), ItBinaryT(padded.end()));
                output.erase(output.end() - pad_chars, output.end());
                return output;
            } catch (std::exception const& e) {
                cerr << "Exception caught: " << e.what() << endl;
            }
            
            return output;
        }
    }
    
    namespace String
    {
        const char* ws = " \t\n\r\f\v";

        inline string& rtrim(const std::string& s, const char* t = ws)
        {
            return string(s).erase(s.find_last_not_of(t) + 1);
        }

        inline string& ltrim(const string& s, const char* t = ws)
        {
            return string(s).erase(0, s.find_first_not_of(t));
        }

        inline string& trim(const string& s, const char* t = ws)
        {
            return ltrim(rtrim(s, t), t);
        }
    }
}
