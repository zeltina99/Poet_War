#pragma once
#include <algorithm>
#include <vector>
#include "TwilightPoet.h"
#include "Player.h"


enum class PoetID
{
	CharlesID = 10,
	DanteID,
	ConanID,
	GoetheID,
	KenjiID,
	KimSowolID,
	ShakespeareID
};

enum class LocationID
{
	None = 0,
	Scentveil,			// ���� ��
	Infernia,			// ���� ��
	Shercroft,			// �ڳ� ��
	Faustburg,			// ���� ��
	Kazehamura,			// ���� ��
	Azalean,			// ��ҿ� ��
	AvonSanctum,		// ���� ��
};

class Chapters
{
public:
	void CharlesChapter(Player* player);	// ���� ��
	void DanteChapter(Player* player);	// ���� ��
	void ConanChapter(Player* player);	// �ڳ� ��
	void GoetheChapter(Player* player);	// ���� ��
	void KenjiChapter(Player* player);	// ���� ��
	void KimSowolChapter(Player* player);	// ��ҿ� ��
	void LevelChapters(Player* player);	// ���� ���� �и� �ؼ� �̵��� �� �ִ� ���� ������ �Լ�

	bool IsPoetAlive(PoetID id) const;	// ������ �׾����� ���� Ȯ��

	inline LocationID GetCurrentLocation() { return CurrentLocation; }
	bool YoonMasage = true;

private:
	std::vector<PoetID> DefeatedPoets;	//�̱� ������ ���
	LocationID CurrentLocation = LocationID::Scentveil;
};

