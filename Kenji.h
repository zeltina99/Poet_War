#pragma once
#include "Poet.h"
#include "ICanBattle.h"
class Kenji : public Poet, public ICanBattle
{
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

	void KenjiPoemSkill();	// ���� ���鷹���� ���� ��ų

	inline bool IsAliveKenji() const { return Health > 0; }


	void KenjiDefeat(); // ��ҿ��� �й��ϸ� ����� �Լ�

public:
	Kenji() = default;
	Kenji(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~Kenji() {};
};

