#pragma once
#include "Poet.h"
#include "ICanBattle.h"
class Dante : public Poet, public ICanBattle
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

	void DantePoemSkill();	// ������ ���� ��ų

	inline bool IsAliveDante() const { return Health > 0; }



public:
	Dante() = default;
	Dante(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~Dante() {};

private:
	bool IgnoreNextDamage = false;	// ������ ��ų ���� ������ �������� ����


};

