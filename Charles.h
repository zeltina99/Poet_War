#pragma once
#include "Poet.h"
#include "ICanBattle.h"
class Charles : public Poet, public ICanBattle
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

	void CharlesPoemSkill();	// ���� ���鷹���� ���� ��ų

	/// <summary>
	/// �� ������ ���� ���θ� �˷��ִ� �Լ�
	/// </summary>
	/// <returns>true�� ����ִ�. false�� �׾���.</returns>
	inline bool IsAliveCharles();

	
	void CharlesDefeat(); // ������ �й��ϸ� ����� �Լ�

public:
	Charles() = default;
	Charles(std::string InName) : Poet(InName) {}
	virtual ~Charles() {};


};

