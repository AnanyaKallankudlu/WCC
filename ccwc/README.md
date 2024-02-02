### Notes
- [The challenge](https://codingchallenges.fyi/challenges/challenge-wc)
- Build steps:
```
mkdir build
cd build
cmake ..
make
cd src
./ccwc
```
- [C++ STL Filesystem Library](https://en.cppreference.com/w/cpp/filesystem)
	- [File path](https://en.cppreference.com/w/cpp/filesystem/path/path)
	- [File size](https://en.cppreference.com/w/cpp/filesystem/file_size)
	- [Reading from a stringstream](https://www.geeksforgeeks.org/removing-spaces-string-using-stringstream/)
	- [Reading unicode characters](https://cplusplus.com/forum/beginner/58915/)
- [Getting multibyte character from strings with Unicode](https://en.cppreference.com/w/cpp/string/multibyte/wctomb#:~:text=Converts%20a%20wide%20character%20wc,the%20current%20locale's%20LC_CTYPE%20category.)

### Todos
- [x] Setup CMake
- [x] Setup boost
	- [Installing boost](https://stackoverflow.com/a/29657712/6656493)
	- [Finding boost installation](https://superuser.com/a/1431334)
	- [boost::program_options example](https://github.com/boostorg/program_options/tree/develop/example)
	- [Default values for program options](https://stackoverflow.com/a/31908741/6656493)
	- [Boost join algorithm](https://www.geeksforgeeks.org/boostalgorithmjoin-in-cpp-library/)
	- [Other Boost algorithms](https://www.boost.org/doc/libs/1_72_0/doc/html/string_algo.html)
- [x] Write an example program using `boost::program_options`
- [x] Write sample program that can read both from input as well as from a text file
- [x] Handle program options using [boost program_options](https://theboostcpplibraries.com/boost.program_options)
- [x] Build using CMake
- [x] Setup GoogleTest Framework on Ubuntu
- [ ] Do TDD using Google Test
