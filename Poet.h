#pragma once
#include "ICanBattle.h"
#include <string>
#include <random>
#include <cstdio>

class Poet : public ICanBattle
{
public:

	inline const int GetPoetHealth() const { return Health; }		// ������ ü�� Ȯ��
	inline const int GetAttackPower() const { return AttackPower; }	// ������ ���ݷ� Ȯ��
	inline int GetDropGold() const { return DropInk; }	// ���� �̱�� ���� ��� Ȯ��

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

		printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
	}

	virtual void Attack(class ICanBattle* InTarget) = 0;

protected:

	inline void SetHealth(int InHealth)
	{
		// ���� ������ �����ϰ� �ִ� ü���� 500
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
		// ���� ������ �����ϰ� �ִ� ���ݷ��� 100
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

	const int PoetMaxHealth = 500;	// ���ε��� �ִ� ü��
	const int PoemMaxAttackPower = 100;	// ���ε��� �ִ� ���ݷ�

	int AttackPower = 0;	// ���ε��� �⺻ ���ݷ�
	std::string Name = "����";
	int Health = 0;		// ���ε��� �⺻ ü��
	int DropInk = 0;	// ���ε��� �� ��ũ(���)
};

