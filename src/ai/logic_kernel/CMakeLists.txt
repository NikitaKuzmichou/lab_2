cmake_minimum_required (VERSION 3.17)

target_sources (BasedOnRulesAi
                PUBLIC
                    AiKernel.cpp
                    Conclusions.cpp)

add_subdirectory (service)