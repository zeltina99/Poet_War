#pragma once
#include "Poet.h"
#include "ICanBattle.h"
class Goethe : public Poet, public ICanBattle
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

	void GoethePoemSkill();	// ���� ���鷹���� ���� ��ų

	inline bool IsAliveGoethe() const { return Health > 0; }


	void GoetheDefeat(); // ���װ� �й��ϸ� ����� �Լ�

public:
	Goethe() = default;
	Goethe(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~Goethe() {};
};

