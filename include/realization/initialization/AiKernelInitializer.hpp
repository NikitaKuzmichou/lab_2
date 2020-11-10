#ifndef AI_KERNEL_INITIALIZER
#define AI_KERNEL_INITIALIZER

#include "../../ai/logic_kernel/AiKernel.hpp"
#include "../../ai/factories/FactoriesFactory.hpp"
#include "../../realization/factories/CmdInteractorFactory.hpp"
#include "../../realization/knowledge_base/KnowledgeBaseFiller.hpp"
#include "../../realization/knowledge_base/ConclusionsFiller.hpp"
#include "../../realization/user_interaction/CmdUserInitialData.hpp"

class AiKernelInitializer {
private:
    std::shared_ptr<AiKernel> aiKernel;
public:
    AiKernelInitializer();
    void initializeKnowledgeBase();
    void initializeFactoriesFactory();
    void initializeConclusions();
    AiKernel getInitializedAiKernel();
private:
    void getInitialUserInput(std::shared_ptr<Conclusions> conclusions, 
                             CmdUserInitialData initializer);
};

#endif // !AI_KERNEL_INITIALIZER