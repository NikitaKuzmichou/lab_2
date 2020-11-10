cmake_minimum_required (VERSION 3.17)

target_sources (BasedOnRulesAi
                #PRIVATE
                #    AbstractState.cpp
                PUBLIC
                    KnowledgeBase.cpp
                    Rule.cpp)