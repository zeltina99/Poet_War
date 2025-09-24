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

	/// <summary>
	/// �� ������ ���� ���θ� �˷��ִ� �Լ�
	/// </summary>
	/// <returns>true�� ����ִ�. false�� �׾���.</returns>
	inline bool IsAliveKenji();


	void KenjiDefeat(); // ��ҿ��� �й��ϸ� ����� �Լ�

public:
	Kenji() = default;
	Kenji(std::string InName) : Poet(InName) {}
	virtual ~Kenji() {};
};

