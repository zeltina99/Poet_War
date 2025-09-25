#pragma once
#include "Poet.h"
#include "ICanBattle.h"
class Dante : public Poet, public ICanBattle
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

	void DantePoemSkill();	// 단테의 전용 스킬

	inline bool IsAliveDante() const { return Health > 0; }



public:
	Dante() = default;
	Dante(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~Dante() {};

private:
	bool IgnoreNextDamage = false;	// 단테의 스킬 다음 공격을 무시할지 여부


};

