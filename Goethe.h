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

	/// <summary>
	/// �� ������ ���� ���θ� �˷��ִ� �Լ�
	/// </summary>
	/// <returns>true�� ����ִ�. false�� �׾���.</returns>
	inline bool IsAliveGoethe();


	void GoetheDefeat(); // ���װ� �й��ϸ� ����� �Լ�

public:
	Goethe() = default;
	Goethe(std::string InName) : Poet(InName) {}
	virtual ~Goethe() {};
};

