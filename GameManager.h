#pragma once
#include "Player.h"
#include "Chapters.h"


class GameManager
{
public:
	void StartGame();	// ������ Ʃ�丮��
	void ExploreMenu();	// ����/Ž�� ����
	void BattleMenu();	// ���� ����

	void Intro();
	void TutorialBattle(Player* player, TwilightPoet* twilight);	// Ʃ�丮�� ����


public:
	GameManager() = default;
	~GameManager();

private:
	Player player;
	Chapters Level;
};






/*
	=========== Poet War ===========
	�� ���ѷα� : �÷��̾� �̸�, �÷��̾� �� �Է� ����
		�����ֿ��� ����� ���� �� ���� ����� ��� Ʃ�丮��

	�� ���� : 6���� �������� 6���� ������ ������ �ο�

	���� é�� -> 3���� é��(�÷��̾ �����Ӱ� �� 3���� ���� ���� ������� ��) -> 2���� é��(,,) -> ���� é��

	�� é�� ���� ������ ���� �������� �����ֿ� ��ȭ�� �ؼ� �÷��̾ ��ȭ�� �� �ְ�, �����ϱ⸦ ���� ������ ������ �ο� �� �ִ�.

	�� ���� : ���� ���� �ϰ� �������� �÷��̾ �� �ð� �����鼭 ���� ũ����

*/