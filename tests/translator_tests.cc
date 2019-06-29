#include "../src/translator.h"

#include <cstdlib>
#include <fstream>

#include <gtest/gtest.h>

const string TEST_STRING = "yeet";
const string TEST_FILES_DIR = "../../tests/files/";
const string TEST_FILE = TEST_FILES_DIR + "yeet.iching";
const string TEST_FILE_SHIFTED = TEST_FILES_DIR + "yeet-shifted.iching";
const string TEST_KEY = "TX/FB8Pu40ZztIVmpNeh9xocflkLnE+2Ysd7vyOACGWHwbqjgDSKr5a3J1RUQ6iM";

string load_test_file(const string& test_file)
{
    std::srand(unsigned(std::time(0)));
    std::ifstream ifs(TEST_FILE);
    string file_contents((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    return file_contents;
}

TEST(Encode, String)
{
    Translator translator = Translator();
    string EXPECTED = Util::String::trim(load_test_file(TEST_FILE));
    string ACTUAL = Util::String::trim(translator.encode(TEST_STRING));
    ASSERT_EQ(ACTUAL, EXPECTED);
}

TEST(Encode, StringWithShiftCipher)
{
    Translator translator = Translator();
    string EXPECTED = Util::String::trim(load_test_file(TEST_FILE));
    string ACTUAL = Util::String::trim(translator.encode(TEST_STRING, true));
    ASSERT_NE(ACTUAL, EXPECTED);
}

TEST(Decode, String)
{
    Translator translator = Translator();
    string EXPECTED = TEST_STRING;
    string encoded = Util::String::trim(translator.encode(TEST_STRING));
    string ACTUAL = Util::String::trim(translator.decode(encoded));
    ASSERT_EQ(ACTUAL, EXPECTED);
}

TEST(Decode, StringWithShiftCipher)
{
    Translator translator = Translator();
    string EXPECTED = TEST_STRING;
    string shifted = load_test_file(TEST_FILE_SHIFTED);
    string ACTUAL = Util::String::trim(translator.decode(shifted));
    ASSERT_EQ(ACTUAL, EXPECTED);
}
