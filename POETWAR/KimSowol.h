#pragma once
#include "Poet.h"
class KimSowol : public Poet
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


	inline bool IsAliveKimSowol() const { return Health > 0; }


public:
	KimSowol() = default;
	KimSowol(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~KimSowol() {};
	void KimSowolPoemSkill();	// ��ҿ��� ���� ��ų
};

