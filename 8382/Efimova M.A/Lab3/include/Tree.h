#pragma once
#include "NeutralBoardUnit.h"
class Tree : public NeutralBoardUnit
{
public:
	std::vector<ActionMeta> turnAction() override;
	std::string getName() override;
};

