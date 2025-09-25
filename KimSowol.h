#pragma once
#include "Poet.h"
#include "ICanBattle.h"
class KimSowol : public Poet, public ICanBattle
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

	void KimSowolPoemSkill();	// ���� ���鷹���� ���� ��ų

	inline bool IsAliveKimSowol() const { return Health > 0; }

	void KimSowolDefeat(); // ��ҿ��� �й��ϸ� ����� �Լ�

public:
	KimSowol() = default;
	KimSowol(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~KimSowol() {};
};

