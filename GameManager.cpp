#include "GameManager.h"
#include <iostream>
#include <cstdio>
#include <locale>
#include <codecvt>   // string <-> wstring ��ȯ
#include "Map.h"
#include "Chapters.h"
#include "Battles.h"
//#include "Charles.h"
//#include "Conan.h"
//#include "Dante.h"
//#include "Goethe.h"
//#include "Kenji.h"
//#include "KimSowol.h"


void GameManager::StartGame()
{
    
    printf("=========================================\n");
    printf("              P O E T   W A R            \n");
    printf("=========================================\n");
    printf("1. ���� ����\n2. ����\n");

    int Choice;
    std::cin >> Choice;

    if (Choice == 2)
    {
        return;
    }

    Intro();
    ExploreMenu();
}



GameManager::~GameManager()
{
}

void GameManager::Intro()
{
    Map Fmap;
    Fmap.TutorialMap();

    setlocale(LC_ALL, ""); // �ܼ� ������ ���߱�

    std::wstring PlayerName;
    wprintf(L"������: ���� �̸��� �����̴�?\n> ");
    std::wcin >> PlayerName;

    wprintf(L"������: %ls... ���� �̸��̳�.\n", PlayerName.c_str());
    printf("������: �� ����� [Word World]��, �� ���� ���� �ٽ����� �ڵ�, '����'�� ��������.\n");
    printf("������: �� ������ ������ ���������� �ڵ��� ���ƾ� �Ѵ�.\n\n");

    wprintf(L"������: �װ� ���� ���� �� �� ������ ����ƶ�. �� 20���� ������ ��Ź�Ұ�...\n> ");
    std::wcin.ignore();
    std::wstring Poem;
    std::getline(std::wcin, Poem);

    player.Init(PlayerName);
    player.SetPoem(Poem);
    player.DecideAttackPower();

    TwilightPoet yoon("������", 100, 5);
    TutorialBattle(&player, &yoon);
}

void GameManager::TutorialBattle(Player* player, TwilightPoet* twilight)
{
    Map Fmap;
    printf("\n������: �ʿ��� ������ ��� ���� ���� ������ �˷��ٰ�.\n");
    printf("������: �̷��� �� ó�� ������ ������ ���� ���°� �Ǵµ� �ʰ� �� �ø� �о��ָ� ��.\n\n");

    int InputNumber = 0;
    int InputNumber2 = 0;

    while (player->IsAlivePlayer() && twilight->IsAlive())
    {
        printf("�� �ø� �д´�\n");
        printf("> ����: ");
        std::cin >> InputNumber;
        if (InputNumber == 1)
        {
            // �÷��̾� ��
            player->Attack(twilight);
            if (!twilight->IsAlive())
            {
                break;
            }

            // ������ ��
            twilight->Attack(player);
            if (!player->IsAlivePlayer())
            {
                break;
            }
        }
        else
        {
            printf("\n�߸��� �Է��̾�! �ٽ� �Է�����\n");
        }
    }

    if (player->IsAlivePlayer())
    {
        printf("\n������: ���߾�! �̰� ���� �ɷ��̾�. ���� �ٽ� ȸ�� �����ٰ�.\n");
        player->PlayerHeal(100);
        printf("\n������: ���� �ٸ� ���ε��� ������ ���ž�, ���� ���ΰ� �ο��� �̱�� ������ ��ȭ���� ���� �ø� ���� ÷�����ٰ�.\n");
        while (InputNumber2 != 1)
        {
            printf("\n�� �̵��ϱ�\n");
            printf("> ����: ");
            std::cin >> InputNumber2;

            if (InputNumber2 != 1)
            {
                printf("\n�߸��� �Է��̾�! �ٽ� �Է�����\n");
            }
            else
            {
                while (true)
                {
                    printf("\n�� ����� �帷\n");
                    printf("> ����: ");
                    std::cin >> InputNumber2;
                    if (InputNumber2 != 1)
                    {
                        printf("\n�߸��� �Է��̾�! �ٽ� �Է�����\n");
                    }
                    else
                    {
                        Fmap.ScentveilMap();
                        printf("������: ���� ����� �帷�̾�... �츰 ���⼭ ��¡������ ���� [���� ���鷹��]�� ã�ƾ���.\n\n");
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\n������: �̾�, ���� �ʹ� ���߳�?\n");
    }
}




void GameManager::ExploreMenu()
{
    /*
    �� player.TalkToYoon();      ��ȭ�ϱ�
    �� player.MoveToLocation();  �̵��ϱ�
    �� player.InvestigateArea(); �����ϱ� (������ ����)
    �� player.OpenInventory();   ���濭�� (�÷��̾��� ������ ������ �ܿ� ��尡 ����)
    */
    int SelectNumber = 0;

    while(true)
    {
        printf("�� ��ȭ�ϱ� �� �̵��ϱ� �� �����ϱ� �� ���濭��\n");
        printf("> ����: ");
        std::cin >> SelectNumber;
        switch (SelectNumber)
        {  
        case 1:
        {
            player.TalkToYoon();
        }
        break;
        case 2:
        {
            player.MoveToLocation(&Level);
        }
        break;
        case 3:
        {
            player.InvestigateArea(&Level);
        }
        break;
        case 4:
        {
            // enum class�� ���� �������� ������
            player.OpenInventory();
        }
        break;
        default:
        {
            printf("\n�߸��� �Է��̾�! �ٽ� �Է�����\n");
        }
        break;
        }
       
    }// if (������ �װų� ���� �װų�) -> return
}

void GameManager::BattleMenu(Player* InPlayer, Poet* InPoet)
{
    int InputNumber = 0;

    while (InPlayer->IsAlivePlayer() && InPoet->GetPoetHealth() > 0)
    {
        printf("\n--- ���� �޴� ---\n");
        printf("�� �ø� �д´� (�⺻ ����)\n");
        printf("�� ������ ��ģ�� (��ų)\n");
        printf("> ����: ");
        std::cin >> InputNumber;

        if (InputNumber == 1)
        {
            // �÷��̾� �� (�⺻����)
            InPlayer->RecitePoemAttack(InPoet);
            if (InPoet->GetPoetHealth() <= 0)
            {
                break;
            }

            // ��(����) ��
            InPoet->Attack(InPlayer);
            if (!InPlayer->IsAlivePlayer())
            {
                break;
            }
        }
        else if (InputNumber == 2)
        {
            // ������ ���� ��ų Ȯ��
            const auto& poems = InPlayer->GetPoems();
            if (poems.empty())
            {
                printf("���� ȹ���� ������ ����!\n");
                continue;  // ���� �Һ����� �ʰ� �ٽ� ����
            }

            printf("\n--- ��� ������ ���� ---\n");
            for (size_t i = 0; i < poems.size(); ++i)
            {
                switch (poems[i])
                {
                case Poem::CharlesPoem:
                    printf("%d. ���� �� (���ݷ� 2��)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::DantePoem:
                    printf("%d. �Ű� (�߰� ����)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::GoethePoem:
                    printf("%d. ���� (�߰� ����)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::KimSowolPoem:
                    printf("%d. ���޷��� (ü�� ȸ��)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::ConanPoem:
                    printf("%d. Ȱ�� �뷡 (�߰� ����)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::KenjiPoem:
                    printf("%d. �񿡵� ���� �ʰ� (ü�� ȸ��)\n", static_cast<int>(i) + 1);
                    break;
                }
            }
            printf("0. ���\n");

            int poemChoice;
            printf("> ����: ");
            std::cin >> poemChoice;

            if (poemChoice == 0)
            {
                continue;
            }
            if (poemChoice < 1 || poemChoice >static_cast<int>(poems.size()))
            {
                printf("�߸��� �Է��̴�.\n");
                continue;
            }

            Poem chosenPoem = poems[poemChoice - 1];

            // ���� ��ų �ߵ� (������ �Ҹ� X)
            InPlayer->UnleashPoemSkill(chosenPoem, InPoet);

            if (InPoet->GetPoetHealth() <= 0)
            {
                break;
            }

            // �� ��
            InPoet->Attack(InPlayer);
            if (!InPlayer->IsAlivePlayer())
            {
                break;
            }
        }
        else
        {
            printf("�߸��� �Է��̾�! �ٽ� �Է�����\n");
        }
    }

    if (InPlayer->IsAlivePlayer())
    {
        printf("\n�¸��ߴ�!\n");
    }
    else
    {
        printf("\n�й��ߴ�...\n");
    }
}
