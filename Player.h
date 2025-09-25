#pragma once
#include "ICanBattle.h"
#include <string>
#include <vector>
#include "Poet.h"

// ������ ���ε��� �̱�� ���� ����(������)
enum class Poem
{
	CharlesPoem = 100,	// ���� ��
	DantePoem,			// �Ű�
	GoethePoem,			// ����
	KimSowolPoem,		// ���޷���
	ConanPoem,			// Ȱ�� �뷡
	KenjiPoem			// �񿡵� ���� �ʰ�

};

class Player : public ICanBattle
{
public:

	virtual void TakeDamage(int InDamage) override;

	inline bool IsAlivePlayer() const { return PlayerHealth > 0; }
	void PlayerHeal(int InPoetHealth);	// ü�� ȸ��
	void PayInk(int InPutInk);	// ��ũ �Һ�
	void TakeInk(int InPutInk);	// ��ũ ����
	void AttackPowerUP();		// �� ���ݷ� ��ȭ
	void HealthPowerUP();		// �ִ� ü�� ��ȭ
	virtual void Attack(ICanBattle* InTarget) override;	
	void SetPoem(std::wstring InPoem);
	void DecideAttackPower();  // �� ���̷� ���ݷ� ����
	
	// ����/Ž�� ���
	void TalkToYoon();          //	�� �����ֿ� ��ȭ
	void MoveToLocation();      //	�� �ٸ� ��ҷ� �̵�
	void InvestigateArea();     //	�� �ֺ� ����
	void OpenInventory();       //	�� ���� ����

	

	// ���� ���
	void RecitePoemAttack();	//	�� �⺻ ����
	void UnleashPoemSkill();    //	�� ����(��ų) ����


	inline const int GetPlayerHealth() const { return PlayerHealth; }
	inline const int GetInk() const { return Ink; }
	inline std::wstring GetName() const { return Name; }
	inline int GetPlayerAttackPower() const { return PlayerAttackPower; }

	void AddPoem(Poem poem);	// ���� �̱�� ���� ������

	void ShowInventory() const;// ������ �κ��丮

	

public:

	Player() = default;
	Player(std::wstring InName) : Name(InName) {}

	void Init(std::wstring InName)
	{
		Name = InName;
		Poems.clear();
		PlayerAttackPower = 0;
		PlayerHealth = 100;
	}

	virtual ~Player() {}


private:

	inline void SetPlayerInk(int InPutInk)
	{
		//�ִ� ������ ������ ��ũ(���)�� 1000
		if (InPutInk < 0)
		{
			Ink = 0;
		}
		else if (InPutInk > MaxInk)
		{
			Ink = MaxInk;
		}
		else
		{
			Ink = InPutInk;
		}
	}


	inline void SetPlayerHealth(int InPoetHealth)
	{
		//�ִ� ü���� ��ȭ�� �þ
		if (InPoetHealth < 0)
		{
			PlayerHealth = 0;
		}
		else if (MaxHealth > LimitHealth)	// �ִ� ü���� �Ѱ� ü�º��� ������
		{
			MaxHealth = LimitHealth;
		}
		else if(InPoetHealth > MaxHealth)	// ���� ü���� �ִ� ü�º��� ������
		{
			PlayerHealth = MaxHealth;
		}
		else
		{
			PlayerHealth = InPoetHealth;
		}

	}

	inline void SetPlayerMaxHealth(int InPoetHealth)
	{
		//�ִ� ü���� ��ȭ�� �þ
		MaxHealth = MaxHealth + InPoetHealth;
	}

	inline void SetPlayerAttackPower(int InPlayerAttackPower)
	{
		//�ִ� ���ݷ��� 100
		if (InPlayerAttackPower < 0)
		{
			PlayerAttackPower = 0;
		}
		else if (InPlayerAttackPower > MaxPlayerAttackPower)
		{
			PlayerAttackPower = MaxPlayerAttackPower;
		}
		else
		{
			PlayerAttackPower = InPlayerAttackPower;
		}

	}

	std::string GetPoemName(Poem poem) const
	{
		switch (poem)
		{
		case Poem::CharlesPoem:
			return "[���� ��] (���鷹��)";
		case Poem::DantePoem:
			return "[�Ű�] (����)";
		case Poem::GoethePoem:
			return "[����] (����)";
		case Poem::KimSowolPoem:
			return "[���޷���] (��ҿ�)";
		case Poem::ConanPoem:
			return "[Ȱ�� �뷡] (�ڳ� ����)";
		case Poem::KenjiPoem:
			return "[�񿡵� ���� �ʰ�] (�̾��ڿ� ����)";
		default:
			return "�� �� ���� ����";
		}
	}

	std::vector<Poem> Inventory;	// �÷��̾��� �������� �� ����

	int PlayerAttackPower = 0;		// �⺻ ���ݷ�
	std::wstring Name;
	std::vector<std::wstring> Poems;;  // �÷��̾ �Է��� �� ����
	int PlayerHealth = 100;	// �⺻ ü��
	int MaxHealth = 100;	// �ִ� ü�� (��ȭ�� �þ)
	static const int LimitHealth = 500;	// �Ѱ� ü�� (��ȭ�ص� 500 �ʰ��� �ȵ�)
	static const int MaxPlayerAttackPower = 100;	// �ִ� ���ݷ��� ���ȭ ��
	int Ink = 0;
	const int MaxInk = 1000;		// �ִ� ���� ��ũ(���)�� 1000


};

