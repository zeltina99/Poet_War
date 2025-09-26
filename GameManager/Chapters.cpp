#include "Chapters.h"
#include "Map.h"
#include "Battles.h"
#include "Player.h"
#include <cstdio>
#include <iostream>




Map map;
Battles poet;




void Chapters::CharlesChapter(Player* player)
{
    Charles CharlesPoet("샤를 보들레르", 100, 8);     // 샤를의 체력과 공격력 설정
    poet.CharlesBattle(player, &CharlesPoet);
    if (!CharlesPoet.IsAliveCharles())
    {
        DefeatedPoets.push_back(PoetID::CharlesID);  // 샤를 죽음 기록
    }
    
}

void Chapters::DanteChapter(Player* player)
{
    Dante DantePoet("단테", 130, 10);                 // 단테의 체력과 공격력 설정

    poet.DanteBattle(player, &DantePoet);
    if (!DantePoet.IsAliveDante())
    {
        DefeatedPoets.push_back(PoetID::DanteID);
    }
}

void Chapters::ConanChapter(Player* player)
{
    Conan ConanPoet("아서 코난도일", 150, 8);           // 아서 코난도일의 체력과 공격력 설정

    poet.ConanBattle(player, &ConanPoet);
    if (!ConanPoet.IsAliveConan())
    {
        DefeatedPoets.push_back(PoetID::ConanID);
    }
}

void Chapters::GoetheChapter(Player* player)
{
    Goethe GoethePoet("괴테", 100, 20);               // 괴테의 체력과 공격력 설정
    
    poet.GoetheBattle(player, &GoethePoet);
    if(!GoethePoet.IsAliveGoethe())
    {
        DefeatedPoets.push_back(PoetID::GoetheID);
    }
}

void Chapters::KenjiChapter(Player* player)
{
    Kenji KenjiPoet("미야자와 켄지", 200, 25);            // 미야자와 켄지의 체력과 공격력 설정
    
    poet.KenjiBattle(player, &KenjiPoet);
    if (!KenjiPoet.IsAliveKenji())
    {
        DefeatedPoets.push_back(PoetID::KenjiID);
    }
}

void Chapters::KimSowolChapter(Player* player)
{
    KimSowol KimSowolPoet("김소월", 250, 20);          // 김소월의 체력과 공격력 설정
    
    poet.KimSowolBattle(player, &KimSowolPoet);
    if(!KimSowolPoet.IsAliveKimSowol())
    {
        DefeatedPoets.push_back(PoetID::KimSowolID);
    }
}

void Chapters::LevelChapters(Player* player)
{
    int ChoiceNumber = -1;

    if (std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::CharlesID) != DefeatedPoets.end())
    {
        // 1단계 후보 목록
        std::vector<std::pair<int, PoetID>> menu;
        int Index = 1;

        // DefeatedPoets 벡터에 DanteID가 없으면 (아직 단테를 안 이겼으면) true
        bool DanteAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::DanteID) == DefeatedPoets.end();
        // 즉, 단테가 아직 살아있다는 의미

        // 밑에도 똑같음
        bool ConanAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::ConanID) == DefeatedPoets.end();
        bool GoetheAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::GoetheID) == DefeatedPoets.end();

        if (DanteAlive || ConanAlive || GoetheAlive)
        {
            printf("\n=== 이동 가능한 맵 ===\n");
            if (DanteAlive)
            {
                printf("%d. 지옥의 문 앞 마을\n", Index);

                // 메뉴 벡터에 (메뉴 번호, 단테의 ID) 쌍을 추가
                // Index++ 로 인해 다음 메뉴 항목을 위한 번호가 자동으로 증가함
                menu.push_back({ Index++, PoetID::DanteID });
            }
            if (ConanAlive)
            {
                printf("%d. 추리의 뜰\n", Index);
                menu.push_back({ Index++, PoetID::ConanID });
            }
            if (GoetheAlive)
            {
                printf("%d. 파우스트의 성채\n", Index);
                menu.push_back({ Index++, PoetID::GoetheID });
            }
            
            printf("0. 뒤로가기\n");

            printf("> 선택: ");
            std::cin >> ChoiceNumber;

            if (ChoiceNumber == 0)
            {
                return;
            }


            // menu 컨테이너 안에서 플레이어가 입력한 ChoiceNumber와 일치하는 항목을 찾는다.
            // menu는 아마 (번호, PoetID) 형태의 pair들을 담고 있는 벡터일 것.
            // std::find_if는 조건을 만족하는 첫 번째 원소를 반환한다.
            auto iter = std::find_if
            (menu.begin(),  // 탐색 시작 위치
             menu.end(),    // 탐색 끝 위치
             [ChoiceNumber](auto& m)    // 람다식: menu의 각 원소 m에 대해 검사
             { return m.first == ChoiceNumber; }    // m.first(메뉴 번호)가 ChoiceNumber와 같은지 확인
            );

            
            if (iter != menu.end())     // iter가 menu.end()가 아니라면 → 즉, 플레이어가 고른 번호에 해당하는 메뉴 항목이 실제로 존재한다면
            {
                switch (iter->second)    // iter->second = 해당 메뉴 항목에 연결된 PoetID
                {
                case PoetID::DanteID:   // 플레이어가 단테가 있는 마을을 선택했을 경우
                {
                    map.InferniaMap();   // "지옥의 문 앞 마을" 맵을 불러옴
                    CurrentLocation = LocationID::Infernia; // 현재 위치를 Infernia로 설정
                }
                break;
                case PoetID::ConanID:
                {
                    map.ShercroftMap();
                    CurrentLocation = LocationID::Shercroft;
                }
                    break;
                case PoetID::GoetheID:
                {
                    map.FaustburgMap();
                    CurrentLocation = LocationID::Faustburg;
                }
                    break;
                }
            }
            else
            {
                printf("잘못된 입력입니다.\n");
            }
            return;
        }

        // 2단계: 켄지 & 소월
        std::vector<std::pair<int, PoetID>> menu2;
        Index = 1;
        bool KenjiAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::KenjiID) == DefeatedPoets.end();
        bool SowolAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::KimSowolID) == DefeatedPoets.end();

        if(YoonMasage)
        {
            printf("윤동주: 드디어 꽃잎으로 막혔던 동방의 나라가 열렸어.\n\n");
            YoonMasage = false;
        }
        if (KenjiAlive || SowolAlive)
        {
            printf("\n=== 이동 가능한 맵 ===\n");
            if (KenjiAlive)
            {
                printf("%d. 백풍마을\n", Index);
                menu2.push_back({ Index++, PoetID::KenjiID });
            }
            if (SowolAlive)
            {
                printf("%d. 진달래의 언덕\n", Index);
                menu2.push_back({ Index++, PoetID::KimSowolID });
            }

            printf("0. 뒤로가기\n");

            printf("> 선택: ");
            std::cin >> ChoiceNumber;

            if (ChoiceNumber == 0)
            {
                return;
            }

            auto it = std::find_if(menu2.begin(), menu2.end(),
                [ChoiceNumber](auto& m) { return m.first == ChoiceNumber; });

            if (it != menu2.end())
            {
                switch (it->second)
                {
                case PoetID::KenjiID:
                {
                    map.KazehamuraMap();
                    CurrentLocation = LocationID::Kazehamura;
                }
                    break;
                case PoetID::KimSowolID:
                {
                    map.AzaleanMap();
                    CurrentLocation = LocationID::Azalean;
                }
                    break;
                }
            }
            else
            {
                printf("잘못된 입력입니다.\n");
            }
            return;
        }

        // 최종 보스
        if (!KenjiAlive && !SowolAlive)
        {
            while (true)
            {
                printf("\n=== 이동 가능한 맵 ===\n");
                printf("1. ???????????\n");
                printf("0. 뒤로가기\n");

                printf("> 선택: ");
                std::cin >> ChoiceNumber;

                if (ChoiceNumber == 0)
                {
                    return;
                }
                else if (ChoiceNumber == 1)
                {
                    map.AvonSanctumMap();
                    CurrentLocation = LocationID::AvonSanctum;
                    break;
                }
                else
                {
                    printf("잘못된 입력입니다.\n");
                }
            }
        }
    }
    else
    {
        while(true)
        {
            printf("0. 뒤로가기\n");
            printf("> 선택: ");
            std::cin >> ChoiceNumber;

            if (ChoiceNumber == 0)
            {
                return;
            }
            else
            {
                printf("잘못된 입력입니다.\n");
            }
        }
    }
}

// 특정 시인(PoetID id)이 아직 살아있는지 여부를 확인하는 함수
bool Chapters::IsPoetAlive(PoetID id) const
{
    // DefeatedPoets 벡터에서 id를 찾아본다.
    // - begin() ~ end() 범위에서 id와 같은 원소를 찾으면 해당 시인은 이미 쓰러진 것.
    // - 못 찾았다면(end() 반환) 아직 쓰러뜨리지 못한 것이므로 살아있다.
    return std::find(DefeatedPoets.begin(), DefeatedPoets.end(), id) == DefeatedPoets.end();
}