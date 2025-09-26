#pragma once
#include "Poet.h"
#include "Player.h"
class TwilightPoet : public Poet
{
public:
	virtual void Attack(ICanBattle* InTarget) override;
	virtual void TakeDamage(int InDamage) override;

	inline bool IsAlive() const { return Health > 0; }
	inline int GetHealth() const { return Health; }
	inline std::string GetName() const { return Name; }


public:
	TwilightPoet(std::string InName, int InHealth, int InAttackPower) : Poet(InName, InHealth, InAttackPower) {}

	virtual ~TwilightPoet() {}
private:
	/*std::string Name;
	int Health = 0;
	int AttackPower = 0;*/
	bool IsTransformed = false;	// true�� ���� ���� ���ͽ��Ǿ ��
	void AttackSkill1(Player* InPlayer);		// ���ͽ��Ǿ� ��ų 1
	void AttackSkill2(Player* InPlayer);		// ���ͽ��Ǿ� ��ų 2
};