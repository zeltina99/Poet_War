#pragma once
#include "Poet.h"
#include "Player.h"
class Goethe : public Poet
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


	inline bool IsAliveGoethe() const { return Health > 0; }


public:
	Goethe() = default;
	Goethe(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~Goethe() {};
	bool GoethePoemSkill(Player* InPlayer);	// ���� ���鷹���� ���� ��ų
};

