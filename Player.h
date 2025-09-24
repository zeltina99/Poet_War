#pragma once
#include "ICanBattle.h"
class Player : public ICanBattle
{
public:

	inline const float GetPlayerHealth() const { return PlayerHealth; }


private:

	inline void SetPoetHealth(float InPoetHealth)
	{
		//최대 체력이 500
		if (InPoetHealth < 0)
		{
			PlayerHealth = 0.0f;
		}
		else if (InPoetHealth > MaxHealth)
		{
			PlayerHealth = MaxHealth;
		}
		else
		{
			PlayerHealth = InPoetHealth;
		}

	}

	inline void SetPlayerAttackPower(int InPlayerAttackPower)
	{
		//최대 공격력이 100
		if (InPlayerAttackPower < 0)
		{
			PlayerAttackPower = 0;
		}
		else if (InPlayerAttackPower > MaxPlayerAttackPower)
		{
			PlayerAttackPower = MaxPlayerAttackPower;
		}
		else
		{
			PlayerAttackPower = InPlayerAttackPower;
		}

	}


	float PlayerHealth = 100.0f;	// 기본 체력
	const float MaxHealth = 500.0f;	// 최대 체력을 상수화 함
	const int MaxPlayerAttackPower = 100;	// 최대 공격력을 상수화 함
	int PlayerAttackPower = 15;		// 기본 공격력


};

