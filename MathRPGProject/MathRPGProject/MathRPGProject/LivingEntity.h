#pragma once
#include <string>

using namespace std;

class LivingEntity
{
public:
	string name;
	float maxHp;
	float hp = 0;
	float damage = 0;
	LivingEntity(string _name, float _hp, float _damage) : name(_name), maxHp(_hp), damage(_damage){ hp = maxHp; }
	virtual void die() = 0;
	virtual void onDamage(float damage) = 0;
};

