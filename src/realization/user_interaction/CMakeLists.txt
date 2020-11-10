cmake_minimum_required (VERSION 3.17)

target_sources (BasedOnRulesAiImpl
                PUBLIC
                    CmdRequestInteractor.cpp
                    CmdResponseInteractor.cpp
                    CmdMessageInteractor.cpp
                    CmdUserInitalData.cpp)

add_subdirectory (msg_storage)