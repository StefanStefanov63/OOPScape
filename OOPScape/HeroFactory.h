#pragma once
#include "Hero.h"
class HeroFactory
{
public:
	static  std::unique_ptr <Hero> create(const Position& currentPosition, char type);
};

