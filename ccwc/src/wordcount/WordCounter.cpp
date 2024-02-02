#include <cwctype>
#include <sstream>
#include "WordCounter.h"

Options::Options()
    : countBytes(false)
    , countWords(false)
    , countLines(false)
    , countChars(false)
    , filename("")
{}

Options::Options(bool countBytesParam, bool countWordsParam, 
                 bool countLinesParam, bool countCharsParam, 
                 std::string filenameParam)
    : countBytes(countBytesParam)
    , countWords(countWordsParam)
    , countLines(countLinesParam)
    , countChars(countCharsParam)
    , filename(filenameParam)
{}

WordCountStats::WordCountStats()
    : bytes(0)
    , words(0)
    , lines(0)
    , chars(0)
{}

WordCountStats::WordCountStats(int bytesParam, int wordsParam,
                               int linesParam, int charsParam)
    : bytes(bytesParam)
    , words(wordsParam)
    , lines(linesParam)
    , chars(charsParam)
{}

bool WordCountStats::operator == (const WordCountStats& rhs) const {
    return this->bytes == rhs.bytes &&
           this->words == rhs.words &&
           this->lines == rhs.lines &&
           this->chars == rhs.chars;
}

void WordCountStats::PopulateWordCountStats(std::wistream& inputStream) {
    wchar_t currChar, prevChar;
    prevChar = '\0';
    std::string mb(MB_CUR_MAX, '\0');

    while (inputStream.get(currChar)) {
        bytes += std::wctomb(&mb[0], currChar);
        chars++;

        if (currChar == '\n') {
            lines++;
        }
        if (!std::iswspace(prevChar) && std::iswspace(currChar)) {
            words++;
        }

        prevChar = currChar;
    }
    if (!std::iswspace(prevChar))
        words++;
}

std::string WordCountStats::FormatWordCountStats(const Options& options) {
    std::stringstream stats;
    if (options.countBytes) {
        stats << bytes << " ";
    }
    if (options.countLines) {
        stats << lines << " ";
    }
    if (options.countWords) {
        stats << words << " ";
    }
    if (options.countChars) {
        stats << chars << " ";
    }
    if (!options.filename.empty()) {
        stats << options.filename << " ";
    }
    stats << std::endl;
    return stats.str();
}
