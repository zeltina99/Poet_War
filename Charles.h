#pragma once
#include "Poet.h"
class Charles : public Poet
{
public:
	/// <summary>
	/// Target���� �����ϴ� �Լ�
	/// </summary>
	/// <param name="InTarget">���� �޴� ���</param>
	virtual void Attack(ICanBattle* InTarget) override;

	/// <summary>
	/// ������ ���ط���ŭ ���ο��� ���ظ� ����
	/// </summary>
	/// <param name="InDamage">������ ���ط�</param>
	virtual void TakeDamage(int InDamage) override;	

	void CharlesPoemSkill();	// ���� ���鷹���� ���� ��ų

	
	inline bool IsAliveCharles() const { return Health > 0; }	//true�� ����ִ�, false�� �׾��ִ�.
	

public:
	Charles() = default;
	Charles(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}

	//TwilightPoet(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	
	virtual ~Charles() {};


};

