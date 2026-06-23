#pragma once
class Game;

class Ability
{
public:
    virtual bool use(Game& game) = 0;
    virtual ~Ability() = default;
};

