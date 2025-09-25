#pragma once
#include "ICanBattle.h"
#include "Charles.h"
#include "Conan.h"
#include "Dante.h"
#include "Goethe.h"
#include "Kenji.h"
#include "KimSowol.h"
#include "Player.h"



class Battles
{
public:
	void CharlesBattle(Player* InPlayer, Charles* InPoet);		// 샤를과 전투 시작
	void ConanBattle(Player* InPlayer, Conan* InPoet);			// 코난과 전투 시작
	void DanteBattle(Player* InPlayer, Dante* InPoet);			// 단테와 전투 시작
	void GoetheBattle(Player* InPlayer, Goethe* InPoet);		// 괴테와 전투 시작
	void KenjiBattle(Player* InPlayer, Kenji* InPoet);			// 켄지와 전투 시작
	void KimSowolBattle(Player* InPlayer, KimSowol* InPoet);	// 김소월과 전투 시작



};

