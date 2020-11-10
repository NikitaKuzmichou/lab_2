#ifndef AI_KERNEL
#define AI_KERNEL

#include "../factories/FactoriesFactory.hpp"
#include "../knowledge_base/KnowledgeBase.hpp"
#include "service/KernelService.hpp"
#include "Conclusions.hpp"

class AiKernel {
private:
	std::shared_ptr<FactoriesFactory> factoriesFactory;
	std::shared_ptr<KnowledgeBase> knowledgeBase;
	std::shared_ptr<Conclusions> conclusions;
	std::shared_ptr<KernelService> kernelService;
	int maxUnknownStates;
public:
	AiKernel(int maxUnknownStates = 1);
	~AiKernel();
	void setMaxUnknownStates(int);
	int getMaxUnknownStates();
	void setFactoriesFactory(std::shared_ptr<FactoriesFactory>);
	KnowledgeBase getKnowledgeBase();
	void setKnowledgeBase(std::shared_ptr<KnowledgeBase>);
	std::shared_ptr<Conclusions> getConclusions();
	void setConclusions(std::shared_ptr<Conclusions>);
	bool startService();
};

#endif // !AI_KERNEL
