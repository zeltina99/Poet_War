#pragma once
#include "Poet.h"
class Dante : public Poet
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


	inline bool IsAliveDante() const { return Health > 0; }



public:
	Dante() = default;
	Dante(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~Dante() {};

private:
	bool IgnoreNextDamage = false;	// 단테의 스킬을 한번만 썼다고 출력할 bool
	bool SkiilUsed = false;			// 스킬을 실제로 썼는지 판단하는 bool
	void DantePoemSkill();	// 단테의 전용 스킬

};

