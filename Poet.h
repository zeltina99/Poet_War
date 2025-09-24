#pragma once
#include <string>
#include <random>
class Poet
{
public:

	inline const float GetPoetHealth() const { return PoetHealth; }		// ������ ü�� Ȯ��
	inline const int GetPoemAttackPower() const { return PoemAttackPower; }	// ������ ���ݷ� Ȯ��
	inline int GetDropGold() const { return DropGold; }	// ���� �̱�� ���� ��� Ȯ��

public:
	Poet() = default;
	Poet(std::string InName) : Name(InName) {}

	virtual ~Poet() {};

protected:

	inline void SetPoetHealth(float InPoetHealth)
	{
		// ���� ������ �����ϰ� �ִ� ü���� 500
		if (InPoetHealth < 0)
		{
			PoetHealth = 0.0f;
		}
		else if (InPoetHealth > PoetMaxHealth)
		{
			PoetHealth = PoetMaxHealth;
		}
		else
		{
			PoetHealth = InPoetHealth;
		}

	}
	inline void SetPoemAttackPower(int InPoemAttackPower)
	{
		// ���� ������ �����ϰ� �ִ� ���ݷ��� 100
		if (InPoemAttackPower < 0)
		{
			PoemAttackPower = 0;
		}
		else if (InPoemAttackPower > PoemMaxAttackPower)
		{
			PoemAttackPower = PoemMaxAttackPower;
		}
		else
		{
			PoemAttackPower = InPoemAttackPower;
		}
	}

	const float PoetMaxHealth = 500.0f;	// ���ε��� �ִ� ü��
	const int PoemMaxAttackPower = 100;	// ���ε��� �ִ� ���ݷ�

	int PoemAttackPower = 10;	// ���ε��� �⺻ ���ݷ�
	std::string Name = "����";
	float PoetHealth = 100.0f;		// ���ε��� �⺻ ü��
	int DropGold = 10;
};

// ������ ���ε��� �̱�� ���� ����(������)
enum class Poem
{
	 CharlesPoem = 1,	// ���� ��
	 DantePoem = 2,		// �Ű�
	 GoethePoem = 3,	// ����
	 KimSowolPoem = 4,	// ���޷���
	 ConanPoem = 5,		// Ȱ�� �뷡
	 KenjiPoem = 6		// �񿡵� ���� �ʰ�

};