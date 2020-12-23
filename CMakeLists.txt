cmake_minimum_required (VERSION 3.17)

project ("Lab_2" VERSION 0.0.1 LANGUAGES CXX)

set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREADED ON)
find_package (Boost 1.73.0 REQUIRED COMPONENTS system)
include_directories (${Boost_INCLUDE_DIRS})

add_subdirectory (src)
add_executable (Lab_2 app/lab_2.cpp "include/ai/states/InitType.hpp")
target_include_directories (Lab_2 PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries (Lab_2 PUBLIC BasedOnRulesAi BasedOnRulesAiImpl ${Boost_LIBRARIES})
install (TARGETS Lab_2 DESTINATION bin)