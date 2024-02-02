#include <gtest/gtest.h>
#include <sstream>
#include "WordCounter.h"

TEST(WordCounterTests, TestHelloUniverse)
{
    std::wstringstream inputStream;
    inputStream << "Hello Universe\n";
    WordCountStats expected(15, 2, 1, 15);
    WordCountStats actual;
    actual.PopulateWordCountStats(inputStream);
    ASSERT_EQ(expected, actual);
}

// TODO Write some more tests
