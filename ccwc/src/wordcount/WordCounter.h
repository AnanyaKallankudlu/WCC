#ifndef __HEADER_WORD_COUNTER
#define __HEADER_WORD_COUNTER

#include <string>

struct Options {
    bool countBytes;
    bool countWords;
    bool countLines;
    bool countChars;
    std::string filename;

    Options();
    Options(bool, bool, bool, bool, std::string);
};

class WordCountStats {
    int bytes;
    int words;
    int lines;
    int chars;
public:
    WordCountStats();
    WordCountStats(int, int, int, int);
    bool operator == (const WordCountStats&) const;
    void PopulateWordCountStats(std::wistream&);
    std::string FormatWordCountStats(const Options&);
};

#endif
