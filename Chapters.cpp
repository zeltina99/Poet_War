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
    Charles CharlesPoet("���� ���鷹��", 100, 8);
    poet.CharlesBattle(player, &CharlesPoet);
    if (!CharlesPoet.IsAliveCharles())
    {
        DefeatedPoets.push_back(PoetID::CharlesID);  // ���� ���� ���
    }
    
}

void Chapters::DanteChapter(Player* player)
{
    map.InferniaMap();
    Dante DantePoet("����", 130, 10);
    printf("������: �� ���� �Ѻ����� �ڵ��� �ϳ����� ������ٴ� ��Ⱑ �־�...\n\n");


    if (!DantePoet.IsAliveDante())
    {
        DefeatedPoets.push_back(PoetID::DanteID);
    }
}

void Chapters::ConanChapter(Player* player)
{
    map.ShercroftMap();
    Conan ConanPoet("�Ƽ� �ڳ�����", 150, 8);
    printf("������: �׸��� �ϳ������� �ܼ��� �Ǵ� �����̾�.\n\n");

    if (!ConanPoet.IsAliveConan())
    {
        DefeatedPoets.push_back(PoetID::ConanID);
    }
}

void Chapters::GoetheChapter(Player* player)
{
    map.FaustburgMap();
    Goethe GoethePoet("����", 80, 20);
    printf("������: �Ŀ콺Ʈ�� ��ä... ����� �ȾƳѱ��� ���� ��ȥ�̶�� �����ϴ� �� ����.\n\n");

    if(!GoethePoet.IsAliveGoethe())
    {
        DefeatedPoets.push_back(PoetID::GoetheID);
    }
}

void Chapters::KenjiChapter(Player* player)
{
    map.KazehamuraMap();
    Kenji KenjiPoet("�̾��ڿ� ����", 200, 25);
    printf("������: �鰳�� �ٶ��� �дٴ� �����̾�.\n\n");

    if (!KenjiPoet.IsAliveKenji());
    {
        DefeatedPoets.push_back(PoetID::KenjiID);
    }
}

void Chapters::KimSowolChapter(Player* player)
{
    map.AzaleanMap();
    KimSowol KimSowolPoet("��ҿ�", 250, 20);
    printf("������: �ٶ��� ��鸮�� ������ ����... �������� �ʾ�?\n\n");

    if(!KimSowolPoet.IsAliveKimSowol())
    {
        DefeatedPoets.push_back(PoetID::KimSowolID);
    }
}

void Chapters::BoseChapter(Player* player)
{
    map.AvonSanctumMap();
    TwilightPoet Shakespeare("������ ���ͽ��Ǿ�", 500, 50);
    printf("������: .....���ݱ��� ���� ������ ��\n\n");

    if(!Shakespeare.IsAlive())
    {
        DefeatedPoets.push_back(PoetID::ShakespeareID);
    }
}

void Chapters::LevelChapters(Player* player)
{
    int ChoiceNumber = -1;

    if (std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::CharlesID) != DefeatedPoets.end())
    {
        // 1�ܰ� �ĺ� ���
        std::vector<std::pair<int, PoetID>> menu;
        int Index = 1;

        bool DanteAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::DanteID) == DefeatedPoets.end();
        bool ConanAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::ConanID) == DefeatedPoets.end();
        bool GoetheAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::GoetheID) == DefeatedPoets.end();

        if (DanteAlive || ConanAlive || GoetheAlive)
        {
            printf("\n=== �̵� ������ �� ===\n");
            if (DanteAlive)
            {
                printf("%d. ������ �� �� ����\n", Index);
                menu.push_back({ Index++, PoetID::DanteID });
            }
            if (ConanAlive)
            {
                printf("%d. �߸��� ��\n", Index);
                menu.push_back({ Index++, PoetID::ConanID });
            }
            if (GoetheAlive)
            {
                printf("%d. �Ŀ콺Ʈ�� ��ä\n", Index);
                menu.push_back({ Index++, PoetID::GoetheID });
            }
            
            printf("0. �ڷΰ���\n");

            printf("> ����: ");
            std::cin >> ChoiceNumber;

            if (ChoiceNumber == 0)
            {
                return;
            }

            auto iter = std::find_if(menu.begin(), menu.end(),
                [ChoiceNumber](auto& m) { return m.first == ChoiceNumber; });   // ���ٿ� �������� �־ ĸ����

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
                printf("�߸��� �Է��Դϴ�.\n");
            }
            return;
        }

        // 2�ܰ�: ���� & �ҿ�
        std::vector<std::pair<int, PoetID>> menu2;
        Index = 1;
        bool KenjiAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::KenjiID) == DefeatedPoets.end();
        bool SowolAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::KimSowolID) == DefeatedPoets.end();

        if (KenjiAlive || SowolAlive)
        {
            printf("\n=== �̵� ������ �� ===\n");
            if (KenjiAlive)
            {
                printf("%d. ��ǳ����\n", Index);
                menu2.push_back({ Index++, PoetID::KenjiID });
            }
            if (SowolAlive)
            {
                printf("%d. ���޷��� ���\n", Index);
                menu2.push_back({ Index++, PoetID::KimSowolID });
            }

            printf("0. �ڷΰ���\n");

            printf("> ����: ");
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
                printf("�߸��� �Է��Դϴ�.\n");
            }
            return;
        }

        // ���� ����
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
            printf("0. �ڷΰ���\n");
            printf("> ����: ");
            std::cin >> ChoiceNumber;

            if (ChoiceNumber == 0)
            {
                return;
            }
            else
            {
                printf("�߸��� �Է��Դϴ�.\n");
            }
        }
    }
}

bool Chapters::IsPoetAlive(PoetID id) const
{
    return std::find(DefeatedPoets.begin(), DefeatedPoets.end(), id) == DefeatedPoets.end();
}