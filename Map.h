#pragma once
class Map
{
public:
	void TutorialMap();		// 시작하면 나올 맵
	void ScentveilMap();	// 샤를이 있는 맵
	void InferniaMap();		// 단테가 있는 맵
	void FaustburgMap();	// 괴테가 있는 맵
	void AzaleanMap();		// 김소월이 있는 맵
	void ShercroftMap();	// 코난 도일이 있는 맵
	void KazehamuraMap();	// 겐지가 있는 맵
	void AvonSanctumMap();	// 보스가 있는 맵
};

/*
	맵 이동은 역전재판 같은 방식으로 이동할 예정
	ex)② 이동한다 (2를 입력하면) -> ①ㅇㅇ 마을 ②ㅁㅁ 마을 ③ㄱㄱ 마을 ④... (이렇게 선택창이 나오고) -> (그 중 하나 입력하면 마을 아스키 아트 하나 나오고,이동했습니다가 뜨는 연출)
	아스키 아트는 미로 게임때 썼던 txt 파일 읽는 함수 이용해서 호출 할 예정

	프롤로그 맵
	샤를 맵
	단테 맵
	괴테 맵
	김소월 맵
	코난 도일 맵
	겐지 맵
	보스 맵

*/