#pragma once
#include "Poet.h"
#include "ICanBattle.h"
class Charles : public Poet, public ICanBattle
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

	/// <summary>
	/// 이 시인의 생존 여부를 알려주는 함수
	/// </summary>
	/// <returns>true면 살아있다. false면 죽었다.</returns>
	inline bool IsAliveCharles();

	
	void CharlesDefeat(); // 샤를이 패배하면 출력할 함수

public:
	Charles() = default;
	Charles(std::string InName) : Poet(InName) {}
	virtual ~Charles() {};


};

