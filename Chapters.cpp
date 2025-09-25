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
    Charles CharlesPoet("샤를 보들레르", 100, 8);
    poet.CharlesBattle(player, &CharlesPoet);
    
}

void Chapters::DanteChapter(Player* player)
{
    map.InferniaMap();

    DefeatedPoets.push_back(PoetID::DanteID);
}

void Chapters::ConanChapter(Player* player)
{
    map.ShercroftMap();

    DefeatedPoets.push_back(PoetID::ConanID);
}

void Chapters::GoetheChapter(Player* player)
{
    map.FaustburgMap();

    DefeatedPoets.push_back(PoetID::GoetheID);
}

void Chapters::KenjiChapter(Player* player)
{
    map.KazehamuraMap();

    DefeatedPoets.push_back(PoetID::KenjiID);
}

void Chapters::KimSowolChapter(Player* player)
{
    map.AzaleanMap();

    DefeatedPoets.push_back(PoetID::KimSowolID);
}

void Chapters::BoseChapter(Player* player)
{
    map.AvonSanctumMap();

    DefeatedPoets.push_back(PoetID::ShakespeareID);
}

void Chapters::LevelChapters(Player* player)
{
    int ChoiceNumber = -1;

    if (std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::CharlesID) != DefeatedPoets.end())
    {
        // 1단계 후보 목록
        std::vector<std::pair<int, PoetID>> menu;
        int Index = 1;

        bool DanteAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::DanteID) == DefeatedPoets.end();
        bool ConanAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::ConanID) == DefeatedPoets.end();
        bool GoetheAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::GoetheID) == DefeatedPoets.end();

        if (DanteAlive || ConanAlive || GoetheAlive)
        {
            printf("\n=== 이동 가능한 맵 ===\n");
            if (DanteAlive)
            {
                printf("%d. 지옥의 문 앞 마을\n", Index);
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

            auto iter = std::find_if(menu.begin(), menu.end(),
                [ChoiceNumber](auto& m) { return m.first == ChoiceNumber; });   // 람다에 변수명을 넣어서 캡쳐함

            if (iter != menu.end())
            {
                switch (iter->second)
                {
                case PoetID::DanteID:
                {
                    DanteChapter(player);
                    CurrentLocation = LocationID::Infernia;
                }
                break;
                case PoetID::ConanID:
                {
                    ConanChapter(player);
                    CurrentLocation = LocationID::Shercroft;
                }
                    break;
                case PoetID::GoetheID:
                {
                    GoetheChapter(player);
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
                    KenjiChapter(player);
                    CurrentLocation = LocationID::Kazehamura;
                }
                    break;
                case PoetID::KimSowolID:
                {
                    KimSowolChapter(player);
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
            BoseChapter(player);
            CurrentLocation = LocationID::AvonSanctum;
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

bool Chapters::IsPoetAlive(PoetID id) const
{
    return std::find(DefeatedPoets.begin(), DefeatedPoets.end(), id) == DefeatedPoets.end();
}