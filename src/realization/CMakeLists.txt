cmake_minimum_required (VERSION 3.17)

add_library (BasedOnRulesAiImpl STATIC
                factories/CmdInteractorFactory.cpp
                initialization/AiKernelInitializer.cpp
                knowledge_base/ConclusionsFiller.cpp
                knowledge_base/KnowledgeBaseFiller.cpp
                user_interaction/CmdMessageInteractor.cpp
                user_interaction/CmdRequestInteractor.cpp
                user_interaction/CmdResponseInteractor.cpp
                user_interaction/CmdUserInitalData.cpp
                user_interaction/msg_storage/CmdMessageStorage.cpp
                user_interaction/msg_storage/CmdRequestsStorage.cpp)

#add_library (BasedOnRulesAiImpl STATIC)
#add_subdirectory (knowledge_base)
#add_subdirectory (user_interaction)
#add_subdirectory (factories)