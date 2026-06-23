#include "Hero.h"

Hero::Hero(const Position& currentPosition, std::unique_ptr<Ability> ability)
	: IEntity(currentPosition), ability(std::move( ability))
{
}
