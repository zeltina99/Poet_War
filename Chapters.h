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
	Scentveil,			// 샤를 맵
	Infernia,			// 단테 맵
	Shercroft,			// 코난 맵
	Faustburg,			// 괴테 맵
	Kazehamura,			// 켄지 맵
	Azalean,			// 김소월 맵
	AvonSanctum,		// 보스 맵
};

class Chapters
{
public:
	void CharlesChapter(Player* player);	// 샤를 전
	void DanteChapter(Player* player);	// 단테 전
	void ConanChapter(Player* player);	// 코난 전
	void GoetheChapter(Player* player);	// 괴테 전
	void KenjiChapter(Player* player);	// 켄지 전
	void KimSowolChapter(Player* player);	// 김소월 전
	void LevelChapters(Player* player);	// 레벨 별로 분리 해서 이동할 수 있는 맵을 좁히는 함수

	bool IsPoetAlive(PoetID id) const;	// 시인이 죽었는지 여부 확인

	inline LocationID GetCurrentLocation() { return CurrentLocation; }
	bool YoonMasage = true;

private:
	std::vector<PoetID> DefeatedPoets;	//이긴 시인의 기록
	LocationID CurrentLocation = LocationID::Scentveil;
};

