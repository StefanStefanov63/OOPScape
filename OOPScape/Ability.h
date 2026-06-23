#pragma once
class Ability
{
public:
    virtual void use() = 0;
    virtual ~Ability() = default;
};

