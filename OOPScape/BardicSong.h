#pragma once
#include "Ability.h"
class BardicSong : public Ability
{
	static unsigned int STUNTURNS;
	static unsigned int MINDISTANCE;
	bool use(Game& game) override;
};

