#include "util.h"

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

int Util::Random::random_generator(int i)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, UINT32_MAX);
    return std::rand() % i;
}

string Util::String::rtrim(const string& s, const char* t)
{
    
    return string(s).erase(s.find_last_not_of(t) + 1);
}

string Util::String::ltrim(const string& s, const char* t)
{
    return string(s).erase(0, s.find_first_not_of(t));
}

string Util::String::trim(const string& s, const char* t)
{
    return Util::String::ltrim(Util::String::rtrim(s, t), t);
}

string Util::Base64::b64_decode(const string& msg)
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

string Util::Base64::b64_encode(const string& msg)
{
    std::stringstream os;
    typedef base64_from_binary<transform_width<const char*, 6, 8>> base64_text;

    std::copy(
        base64_text(msg.c_str()),
        base64_text(msg.c_str() + msg.size()),
        std::ostream_iterator<char>(os));
    return os.str();
}
