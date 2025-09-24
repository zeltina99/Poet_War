#pragma once
#include "Poet.h"
#include "ICanBattle.h"
class KimSowol : public Poet, public ICanBattle
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

	void KimSowolPoemSkill();	// ���� ���鷹���� ���� ��ų

	/// <summary>
	/// �� ������ ���� ���θ� �˷��ִ� �Լ�
	/// </summary>
	/// <returns>true�� ����ִ�. false�� �׾���.</returns>
	inline bool IsAliveKimSowol();


	void KimSowolDefeat(); // ��ҿ��� �й��ϸ� ����� �Լ�

public:
	KimSowol() = default;
	KimSowol(std::string InName) : Poet(InName) {}
	virtual ~KimSowol() {};
};

