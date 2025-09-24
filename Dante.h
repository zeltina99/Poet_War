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

	void DantePoemSkill();	// ���� ���鷹���� ���� ��ų

	/// <summary>
	/// �� ������ ���� ���θ� �˷��ִ� �Լ�
	/// </summary>
	/// <returns>true�� ����ִ�. false�� �׾���.</returns>
	inline bool IsAliveDante();


	void DanteDefeat(); // ���װ� �й��ϸ� ����� �Լ�

public:
	Dante() = default;
	Dante(std::string InName) : Poet(InName) {}
	virtual ~Dante() {};
};

