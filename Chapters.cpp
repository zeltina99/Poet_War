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
    Charles CharlesPoet("���� ���鷹��", 100, 8);     // ������ ü�°� ���ݷ� ����
    poet.CharlesBattle(player, &CharlesPoet);
    if (!CharlesPoet.IsAliveCharles())
    {
        DefeatedPoets.push_back(PoetID::CharlesID);  // ���� ���� ���
    }
    
}

void Chapters::DanteChapter(Player* player)
{
    Dante DantePoet("����", 130, 10);                 // ������ ü�°� ���ݷ� ����

    poet.DanteBattle(player, &DantePoet);
    if (!DantePoet.IsAliveDante())
    {
        DefeatedPoets.push_back(PoetID::DanteID);
    }
}

void Chapters::ConanChapter(Player* player)
{
    Conan ConanPoet("�Ƽ� �ڳ�����", 150, 8);           // �Ƽ� �ڳ������� ü�°� ���ݷ� ����

    poet.ConanBattle(player, &ConanPoet);
    if (!ConanPoet.IsAliveConan())
    {
        DefeatedPoets.push_back(PoetID::ConanID);
    }
}

void Chapters::GoetheChapter(Player* player)
{
    Goethe GoethePoet("����", 100, 20);               // ������ ü�°� ���ݷ� ����
    
    poet.GoetheBattle(player, &GoethePoet);
    if(!GoethePoet.IsAliveGoethe())
    {
        DefeatedPoets.push_back(PoetID::GoetheID);
    }
}

void Chapters::KenjiChapter(Player* player)
{
    Kenji KenjiPoet("�̾��ڿ� ����", 200, 25);            // �̾��ڿ� ������ ü�°� ���ݷ� ����
    
    poet.KenjiBattle(player, &KenjiPoet);
    if (!KenjiPoet.IsAliveKenji())
    {
        DefeatedPoets.push_back(PoetID::KenjiID);
    }
}

void Chapters::KimSowolChapter(Player* player)
{
    KimSowol KimSowolPoet("��ҿ�", 250, 20);          // ��ҿ��� ü�°� ���ݷ� ����
    
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
        // 1�ܰ� �ĺ� ���
        std::vector<std::pair<int, PoetID>> menu;
        int Index = 1;

        // DefeatedPoets ���Ϳ� DanteID�� ������ (���� ���׸� �� �̰�����) true
        bool DanteAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::DanteID) == DefeatedPoets.end();
        // ��, ���װ� ���� ����ִٴ� �ǹ�

        // �ؿ��� �Ȱ���
        bool ConanAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::ConanID) == DefeatedPoets.end();
        bool GoetheAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::GoetheID) == DefeatedPoets.end();

        if (DanteAlive || ConanAlive || GoetheAlive)
        {
            printf("\n=== �̵� ������ �� ===\n");
            if (DanteAlive)
            {
                printf("%d. ������ �� �� ����\n", Index);

                // �޴� ���Ϳ� (�޴� ��ȣ, ������ ID) ���� �߰�
                // Index++ �� ���� ���� �޴� �׸��� ���� ��ȣ�� �ڵ����� ������
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


            // menu �����̳� �ȿ��� �÷��̾ �Է��� ChoiceNumber�� ��ġ�ϴ� �׸��� ã�´�.
            // menu�� �Ƹ� (��ȣ, PoetID) ������ pair���� ��� �ִ� ������ ��.
            // std::find_if�� ������ �����ϴ� ù ��° ���Ҹ� ��ȯ�Ѵ�.
            auto iter = std::find_if
            (menu.begin(),  // Ž�� ���� ��ġ
             menu.end(),    // Ž�� �� ��ġ
             [ChoiceNumber](auto& m)    // ���ٽ�: menu�� �� ���� m�� ���� �˻�
             { return m.first == ChoiceNumber; }    // m.first(�޴� ��ȣ)�� ChoiceNumber�� ������ Ȯ��
            );

            
            if (iter != menu.end())     // iter�� menu.end()�� �ƴ϶�� �� ��, �÷��̾ �� ��ȣ�� �ش��ϴ� �޴� �׸��� ������ �����Ѵٸ�
            {
                switch (iter->second)    // iter->second = �ش� �޴� �׸� ����� PoetID
                {
                case PoetID::DanteID:   // �÷��̾ ���װ� �ִ� ������ �������� ���
                {
                    map.InferniaMap();   // "������ �� �� ����" ���� �ҷ���
                    CurrentLocation = LocationID::Infernia; // ���� ��ġ�� Infernia�� ����
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
                printf("�߸��� �Է��Դϴ�.\n");
            }
            return;
        }

        // 2�ܰ�: ���� & �ҿ�
        std::vector<std::pair<int, PoetID>> menu2;
        Index = 1;
        bool KenjiAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::KenjiID) == DefeatedPoets.end();
        bool SowolAlive = std::find(DefeatedPoets.begin(), DefeatedPoets.end(), PoetID::KimSowolID) == DefeatedPoets.end();

        if(YoonMasage)
        {
            printf("������: ���� �������� ������ ������ ���� ���Ⱦ�.\n\n");
            YoonMasage = false;
        }
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
                printf("�߸��� �Է��Դϴ�.\n");
            }
            return;
        }

        // ���� ����
        if (!KenjiAlive && !SowolAlive)
        {
            while (true)
            {
                printf("\n=== �̵� ������ �� ===\n");
                printf("1. ???????????\n");
                printf("0. �ڷΰ���\n");

                printf("> ����: ");
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
                    printf("�߸��� �Է��Դϴ�.\n");
                }
            }
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

// Ư�� ����(PoetID id)�� ���� ����ִ��� ���θ� Ȯ���ϴ� �Լ�
bool Chapters::IsPoetAlive(PoetID id) const
{
    // DefeatedPoets ���Ϳ��� id�� ã�ƺ���.
    // - begin() ~ end() �������� id�� ���� ���Ҹ� ã���� �ش� ������ �̹� ������ ��.
    // - �� ã�Ҵٸ�(end() ��ȯ) ���� �����߸��� ���� ���̹Ƿ� ����ִ�.
    return std::find(DefeatedPoets.begin(), DefeatedPoets.end(), id) == DefeatedPoets.end();
}