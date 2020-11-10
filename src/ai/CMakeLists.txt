cmake_minimum_required (VERSION 3.17)

add_library (BasedOnRulesAi STATIC
                factories/FactoriesFactory.cpp
                factories/interaction/AbstractInteractorFactory.cpp
                interraction/AbstractMessageInteractor.cpp
                interraction/AbstractRequestInteractor.cpp
                interraction/AbstractResponseInteractor.cpp
                knowledge_base/KnowledgeBase.cpp
                knowledge_base/Rule.cpp
                logic_kernel/AiKernel.cpp
                logic_kernel/Conclusions.cpp
                logic_kernel/service/KernelService.cpp
                logic_kernel/service/StateFinder.cpp
                states/AbstractState.cpp)

#add_library (BasedOnRulesAi STATIC)
#add_subdirectory (states)
#add_subdirectory (logic_kernel)
#add_subdirectory (interraction)
#add_subdirectory (knowledge_base)
#add_subdirectory (factories)