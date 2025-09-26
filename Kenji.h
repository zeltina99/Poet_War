#pragma once
#include "Poet.h"
class Kenji : public Poet
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


	inline bool IsAliveKenji() const { return Health > 0; }


public:
	Kenji() = default;
	Kenji(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}
	virtual ~Kenji() {};

private:
	void KenjiPoemSkill();	// ������ ���� ��ų
	bool Passive = true;	// ������ �нú� ����ġ


};

