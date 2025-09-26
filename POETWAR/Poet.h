#pragma once
#include "ICanBattle.h"
#include <string>
#include <random>
#include <cstdio>

class Poet : public ICanBattle
{
public:

	inline const int GetPoetHealth() const { return Health; }		// 시인의 체력 확인
	inline const int GetAttackPower() const { return AttackPower; }	// 시인의 공격력 확인
	inline int GetDropGold() const { return DropInk; }	// 시인 이기면 얻은 골드 확인

public:
	Poet() = default;
	Poet(std::string InName, int InHealth, int InAttackPower) : Name(InName), Health(InHealth), AttackPower(InAttackPower) {}

	virtual ~Poet() {};

	virtual void TakeDamage(int InDamage)
	{
		SetHealth(Health - InDamage);
		if (Health < 0)
		{
			Health = 0;
		}

		printf("%s는 %d의 피해를 입었다! ([%s]의 현재 체력: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
	}

	virtual void Attack(class ICanBattle* InTarget) = 0;

protected:

	inline void SetHealth(int InHealth)
	{
		// 최종 보스를 제외하고 최대 체력이 500
		if (InHealth < 0)
		{
			Health = 0;
		}
		else if (InHealth > PoetMaxHealth)
		{
			Health = PoetMaxHealth;
		}
		else
		{
			Health = InHealth;
		}

	}
	inline void SetAttackPower(int InAttackPower)
	{
		// 최종 보스를 제외하고 최대 공격력은 100
		if (InAttackPower < 0)
		{
			AttackPower = 0;
		}
		else if (InAttackPower > PoemMaxAttackPower)
		{
			AttackPower = PoemMaxAttackPower;
		}
		else
		{
			AttackPower = InAttackPower;
		}
	}

	const int PoetMaxHealth = 500;	// 시인들의 최대 체력
	const int PoemMaxAttackPower = 100;	// 시인들의 최대 공격력

	int AttackPower = 0;	// 시인들의 기본 공격력
	std::string Name = "시인";
	int Health = 0;		// 시인들의 기본 체력
	int DropInk = 0;	// 시인들이 줄 잉크(골드)
};

