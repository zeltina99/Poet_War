#pragma once
#include "Poet.h"
#include "ICanBattle.h"
class Conan : public Poet, public ICanBattle
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

	void ConanPoemSkill();	// ���� ���鷹���� ���� ��ų

	inline bool IsAliveConan() const { return Health > 0; }


	void ConanDefeat(); // ��ҿ��� �й��ϸ� ����� �Լ�

public:
	Conan() = default;
	Conan(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~Conan() {};
};

