#include "HeroFactory.h"

std::unique_ptr<Hero> HeroFactory::create(const Position& currentPosition, char type)
{
	std::unique_ptr<Ability> abl = std::make_unique<Regression>();;

	switch (type)
	{
	case 'A':
	{
		abl = std::make_unique<Regression>();
		break;
	}
	case 'C':
	{
		abl = std::make_unique<Regression>();
		break;
	}
	default:
		abl = nullptr;
		break;
	}

	return std::make_unique<Hero>(currentPosition, std::move(abl));
}
