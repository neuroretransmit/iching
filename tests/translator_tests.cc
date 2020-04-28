#include "../src/translator.h"

#include <cstdlib>
#include <fstream>

#include <gtest/gtest.h>

const string TEST_STRING = "yeet";
const string TEST_FILES_DIR = "../../tests/files/";
const string TEST_FILE = TEST_FILES_DIR + "yeet.iching";
const string TEST_FILE_SUBSTITUTED = TEST_FILES_DIR + "yeet-substituted.iching";
const string TEST_KEY = "Cgh4cob8Z+jlIfX/tRu7kWJwGHBzLQOxnqYKaPAET029V36pMmy5v1dSFrDseUNi";

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
    string EXPECTED = util::str::trim(load_test_file(TEST_FILE));
    string ACTUAL = util::str::trim(translator.encode(TEST_STRING));
    ASSERT_EQ(ACTUAL, EXPECTED);
}

TEST(Encode, StringWithSubstitutionCipher)
{
    Translator translator = Translator();
    string EXPECTED = util::str::trim(load_test_file(TEST_FILE));
    string ACTUAL = util::str::trim(translator.encode(TEST_STRING, true));
    ASSERT_NE(ACTUAL, EXPECTED);
}

TEST(Decode, String)
{
    Translator translator = Translator();
    string EXPECTED = TEST_STRING;
    string encoded = util::str::trim(translator.encode(TEST_STRING));
    string ACTUAL = util::str::trim(translator.decode(encoded));
    ASSERT_EQ(ACTUAL, EXPECTED);
}

TEST(Decode, StringWithSubstitutionCipher)
{
    Translator translator = Translator();
    string EXPECTED = TEST_STRING;
    string substituted = load_test_file(TEST_FILE_SUBSTITUTED);
    string ACTUAL = util::str::trim(translator.decode(substituted));
    ASSERT_EQ(ACTUAL, EXPECTED);
}
