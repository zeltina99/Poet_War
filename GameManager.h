#pragma once
#include "Player.h"
#include "Chapters.h"


class GameManager
{
public:
	void StartGame();	// 윤동주 튜토리얼
	void ExploreMenu();	// 마을/탐험 상태
	void BattleMenu();	// 전투 상태

	void Intro();
	void TutorialBattle(Player* player, TwilightPoet* twilight);	// 튜토리얼 전투


public:
	GameManager() = default;
	~GameManager();

private:
	Player player;
	Chapters Level;
};






/*
	=========== Poet War ===========
	① 프롤로그 : 플레이어 이름, 플레이어 시 입력 받음
		윤동주에게 세계관 설명 및 전투 방식을 듣고 튜토리얼

	② 메인 : 6개의 마을에서 6명의 시인을 만나서 싸움

	샤를 챕터 -> 3개의 챕터(플레이어가 자유롭게 그 3개의 마을 순서 상관없이 감) -> 2개의 챕터(,,) -> 보스 챕터

	각 챕터 마다 마을에 가고 마을에서 윤동주와 대화를 해서 플레이어를 강화할 수 있고, 조사하기를 통해 시인을 만나서 싸울 수 있다.

	③ 엔딩 : 보스 전을 하고 마지막에 플레이어가 쓴 시가 나오면서 엔딩 크레딧

*/