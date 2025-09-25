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
	void CharlesBattle(Player* InPlayer, Charles* InPoet);		// ������ ���� ����
	void ConanBattle(Player* InPlayer, Conan* InPoet);			// �ڳ��� ���� ����
	void DanteBattle(Player* InPlayer, Dante* InPoet);			// ���׿� ���� ����
	void GoetheBattle(Player* InPlayer, Goethe* InPoet);		// ���׿� ���� ����
	void KenjiBattle(Player* InPlayer, Kenji* InPoet);			// ������ ���� ����
	void KimSowolBattle(Player* InPlayer, KimSowol* InPoet);	// ��ҿ��� ���� ����



};

