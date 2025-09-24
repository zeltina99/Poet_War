#pragma once
#include "ICanBattle.h"
class Player : public ICanBattle
{
public:

	inline const float GetPlayerHealth() const { return PlayerHealth; }


private:

	inline void SetPoetHealth(float InPoetHealth)
	{
		//�ִ� ü���� 500
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
		//�ִ� ���ݷ��� 100
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


	float PlayerHealth = 100.0f;	// �⺻ ü��
	const float MaxHealth = 500.0f;	// �ִ� ü���� ���ȭ ��
	const int MaxPlayerAttackPower = 100;	// �ִ� ���ݷ��� ���ȭ ��
	int PlayerAttackPower = 15;		// �⺻ ���ݷ�


};

