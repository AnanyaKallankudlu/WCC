#include <iostream>
#include <fstream>
#include <clocale>
#include <filesystem>
#include <boost/program_options.hpp>
#include "wordcount/WordCounter.h"

namespace po = boost::program_options;
namespace fs = std::filesystem;
void ParseArgs(int argc, char** argv, Options& options) {
    try {
        po::options_description countingOptions("Options for counting stuff inside file");
        countingOptions.add_options()
            ("bytes,c", "Count bytes in file")
            ("lines,l", "Count lines in file")
            ("words,w", "Count words in file")
            ("chars,m", "Count characters in file");
        po::options_description hiddenOptions("Hidden options");
        hiddenOptions.add_options()
            ("input-file", po::value<std::string>(), "input file")
            ;

        po::options_description cmdlineOptions;
        cmdlineOptions.add(countingOptions).add(hiddenOptions);

        po::positional_options_description positionalOptions;
        positionalOptions.add("input-file", 1);

        po::variables_map vm;
        store(po::command_line_parser(argc, argv)
                  .options(cmdlineOptions)
                  .positional(positionalOptions)
                  .run(), vm);
        notify(vm);
        
        if (vm.count("bytes"))
            options.countBytes = true;

        if (vm.count("lines"))
            options.countLines = true;

        if (vm.count("words"))
            options.countWords = true;

        if (vm.count("chars"))
            options.countChars = true;

        if (vm.count("input-file"))
            options.filename = vm["input-file"].as<std::string>();
    }
    catch(std::exception& e) {
        throw(e);
    }
}

int main (int argc, char* argv[]) {
    std::locale::global(std::locale(""));
    try {
        Options options;
        WordCountStats stats;
        ParseArgs(argc, argv, options);
        if (options.filename.empty()) {
           stats.PopulateWordCountStats(std::wcin);
        }
        else {
           fs::path inputFilePath = options.filename;
           std::wifstream inputFile(inputFilePath.c_str());
           stats.PopulateWordCountStats(inputFile);
        }
        std::cout << stats.FormatWordCountStats(options); 
        return 0;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}
