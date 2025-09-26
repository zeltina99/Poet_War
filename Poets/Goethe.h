#pragma once
#include "Poet.h"
#include "Player.h"
class Goethe : public Poet
{
public:
	/// <summary>
	/// Target에게 공격하는 함수
	/// </summary>
	/// <param name="InTarget">공격 받는 대상</param>
	virtual void Attack(ICanBattle* InTarget) override;

	/// <summary>
	/// 지정된 피해량만큼 본인에게 피해를 적용
	/// </summary>
	/// <param name="InDamage">적용할 피해량</param>
	virtual void TakeDamage(int InDamage) override;


	inline bool IsAliveGoethe() const { return Health > 0; }


public:
	Goethe() = default;
	Goethe(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~Goethe() {};
	bool GoethePoemSkill(Player* InPlayer);	// 샤를 보들레르의 전용 스킬
};

