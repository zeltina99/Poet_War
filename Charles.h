#pragma once
#include "Poet.h"
class Charles : public Poet
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

	void CharlesPoemSkill();	// 샤를 보들레르의 전용 스킬

	
	inline bool IsAliveCharles() const { return Health > 0; }	//true면 살아있다, false면 죽어있다.
	

public:
	Charles() = default;
	Charles(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}

	//TwilightPoet(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	
	virtual ~Charles() {};


};

