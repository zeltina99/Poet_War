#pragma once
#include "ICanBattle.h"
#include <string>
#include <vector>
#include "Poet.h"

// 각각의 시인들을 이기면 얻을 시집(아이템)
enum class Poem
{
	CharlesPoem = 100,	// 악의 꽃
	DantePoem,			// 신곡
	GoethePoem,			// 마왕
	KimSowolPoem,		// 진달래꽃
	ConanPoem,			// 활의 노래
	KenjiPoem			// 비에도 지지 않고

};

class Player : public ICanBattle
{
public:

	virtual void TakeDamage(int InDamage) override;

	inline bool IsAlivePlayer() const { return PlayerHealth > 0; }
	void PlayerHeal(int InPoetHealth);	// 체력 회복
	void PayInk(int InPutInk);	// 잉크 소비
	void TakeInk(int InPutInk);	// 잉크 얻음
	void AttackPowerUP();		// 시 공격력 강화
	void HealthPowerUP();		// 최대 체력 강화
	virtual void Attack(ICanBattle* InTarget) override;	
	void SetPoem(std::wstring InPoem);
	void DecideAttackPower();  // 시 길이로 공격력 결정
	
	// 마을/탐험 모드
	void TalkToYoon();          //	① 윤동주와 대화
	void MoveToLocation();      //	② 다른 장소로 이동
	void InvestigateArea();     //	③ 주변 조사
	void OpenInventory();       //	④ 가방 열기

	

	// 전투 모드
	void RecitePoemAttack();	//	① 기본 공격
	void UnleashPoemSkill();    //	② 시집(스킬) 공격


	inline const int GetPlayerHealth() const { return PlayerHealth; }
	inline const int GetInk() const { return Ink; }
	inline std::wstring GetName() const { return Name; }
	inline int GetPlayerAttackPower() const { return PlayerAttackPower; }

	void AddPoem(Poem poem);	// 적을 이기면 얻을 아이템

	void ShowInventory() const;// 보여줄 인벤토리

	

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
		//최대 보유가 가능한 잉크(골드)는 1000
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
		//최대 체력이 강화시 늘어남
		if (InPoetHealth < 0)
		{
			PlayerHealth = 0;
		}
		else if (MaxHealth > LimitHealth)	// 최대 체력이 한계 체력보다 높으면
		{
			MaxHealth = LimitHealth;
		}
		else if(InPoetHealth > MaxHealth)	// 현재 체력이 최대 체력보다 높으면
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
		//최대 체력이 강화시 늘어남
		MaxHealth = MaxHealth + InPoetHealth;
	}

	inline void SetPlayerAttackPower(int InPlayerAttackPower)
	{
		//최대 공격력이 100
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
			return "[악의 꽃] (보들레르)";
		case Poem::DantePoem:
			return "[신곡] (단테)";
		case Poem::GoethePoem:
			return "[마왕] (괴테)";
		case Poem::KimSowolPoem:
			return "[진달래꽃] (김소월)";
		case Poem::ConanPoem:
			return "[활의 노래] (코난 도일)";
		case Poem::KenjiPoem:
			return "[비에도 지지 않고] (미야자와 겐지)";
		default:
			return "알 수 없는 시집";
		}
	}

	std::vector<Poem> Inventory;	// 플레이어의 아이템이 들어갈 벡터

	int PlayerAttackPower = 0;		// 기본 공격력
	std::wstring Name;
	std::vector<std::wstring> Poems;;  // 플레이어가 입력한 시 구절
	int PlayerHealth = 100;	// 기본 체력
	int MaxHealth = 100;	// 최대 체력 (강화시 늘어남)
	static const int LimitHealth = 500;	// 한계 체력 (강화해도 500 초과가 안됨)
	static const int MaxPlayerAttackPower = 100;	// 최대 공격력을 상수화 함
	int Ink = 0;
	const int MaxInk = 1000;		// 최대 보유 잉크(골드)는 1000


};

