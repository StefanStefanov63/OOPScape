#include "HeroFactory.h"

std::unique_ptr<Hero> HeroFactory::create(const Position& currentPosition, char type)
{
	std::unique_ptr<Ability> abl = std::make_unique<Regression>();;

	switch (type)
	{
	case 'B':
	{
		abl = std::make_unique<BardicSong>();
		break;
	}
	case 'C':
	{
		abl = std::make_unique<Regression>();
		break;
	}
	case 'R':
	{
		abl = std::make_unique<WallShift>();
		break;
	}
	default:
		abl = std::make_unique<Regression>();
		break;
	}

	return std::make_unique<Hero>(currentPosition, std::move(abl));
}
