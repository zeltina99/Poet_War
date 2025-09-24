#pragma once
#include <string>
#include <random>
class Poet
{
public:

	inline const float GetPoetHealth() const { return PoetHealth; }		// 시인의 체력 확인
	inline const int GetPoemAttackPower() const { return PoemAttackPower; }	// 시인의 공격력 확인
	inline int GetDropGold() const { return DropGold; }	// 시인 이기면 얻은 골드 확인

public:
	Poet() = default;
	Poet(std::string InName) : Name(InName) {}

	virtual ~Poet() {};

protected:

	inline void SetPoetHealth(float InPoetHealth)
	{
		// 최종 보스를 제외하고 최대 체력이 500
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
		// 최종 보스를 제외하고 최대 공격력은 100
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

	const float PoetMaxHealth = 500.0f;	// 시인들의 최대 체력
	const int PoemMaxAttackPower = 100;	// 시인들의 최대 공격력

	int PoemAttackPower = 10;	// 시인들의 기본 공격력
	std::string Name = "시인";
	float PoetHealth = 100.0f;		// 시인들의 기본 체력
	int DropGold = 10;
};

// 각각의 시인들을 이기면 얻을 시집(아이템)
enum class Poem
{
	 CharlesPoem = 1,	// 악의 꽃
	 DantePoem = 2,		// 신곡
	 GoethePoem = 3,	// 마왕
	 KimSowolPoem = 4,	// 진달래꽃
	 ConanPoem = 5,		// 활의 노래
	 KenjiPoem = 6		// 비에도 지지 않고

};