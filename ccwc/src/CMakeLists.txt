find_package(Boost 1.40 COMPONENTS program_options REQUIRED)

add_subdirectory(wordcount)

add_executable(ccwc main.cpp)

target_link_libraries(ccwc 
                      PRIVATE 
                      Boost::program_options
                      wordcount)
