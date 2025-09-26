#include "GameManager.h"
#include <iostream>
#include <cstdio>
#include <locale>
#include <codecvt>   // string <-> wstring ��ȯ
#include "Map.h"
#include "Chapters.h"
#include "Battles.h"
#include <string>
#include <windows.h>
#include <chrono>     // �ð� ����(std::chrono::milliseconds) ���
#include <thread>     // std::this_thread::sleep_for ���
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

void GameManager::TypeWriterPrint(const std::string& text, int delay_ms)
{
    for (char c : text)
    {
        printf("%c", c);        // ���� ���ڸ� �ֿܼ� ���
        fflush(stdout);         // ��� ���۸� ��� ��� ȭ�鿡 ���̰� ��
        std::this_thread::sleep_for(
            std::chrono::milliseconds(delay_ms));
        // delay_ms �и��� ���� ��� (Ÿ�ڱ� �ӵ� ����) 
    }
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

void GameManager::TutorialBattle(Player* player, TwilightPoet* Yoon)
{
    Map Fmap;
    printf("\n������: �ʿ��� ������ ��� ���� ���� ������ �˷��ٰ�.\n");
    printf("������: �̷��� �� ó�� ������ ������ ���� ���°� �Ǵµ� �ʰ� �� �ø� �о��ָ� ��.\n\n");

    int InputNumber = 0;
    int InputNumber2 = 0;

    while (player->IsAlivePlayer() && Yoon->IsAlive())
    {
        printf("\n--- ���� �޴� ---\n");
        printf("[���ݷ� : %d]\t[ü�� : %d/%d]\n", player->GetPlayerAttackPower(), player->GetPlayerHealth(), player->GetPlayerMaxHealth());
        printf("�� �ø� �д´�\n");
        printf("> ����: ");
        std::cin >> InputNumber;
        if (InputNumber == 1)
        {
            // �÷��̾� ��
            player->Attack(Yoon);
            if (!Yoon->IsAlive())
            {
                break;
            }

            // ������ ��
            Yoon->Attack(player);
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
            printf("\n--- Ž�� �޴� ---\n");
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
                    printf("\n--- �̵��ϱ� ---\n");
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

        // �÷��̾ ����ְ�, ���� ��ġ�� ���� �������� �ƴ� ����
    while (player.IsAlivePlayer() && Level.GetCurrentLocation() != LocationID::AvonSanctum) 
    {
        printf("\n--- Ž�� �޴� ---\n");
        printf("�� ��ȭ�ϱ� �� �̵��ϱ� �� �����ϱ� �� ���濭��\n");
        printf("> ����: ");
        std::cin >> SelectNumber;
        switch (SelectNumber)
        {  
        case 1:
        {
            printf("\n--- ��ȭ�ϱ� ---\n");
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
            printf("\n--- ���濭�� ---\n");
            player.OpenInventory();
        }
        break;
        default:
        {
            printf("\n�߸��� �Է��̾�! �ٽ� �Է�����\n");
        }
        break;
        }
        if (!player.IsAlivePlayer())    // ������ �ٽ� ó������ ����
        {
            printf("������ ���� �� �ĸ� ������ �ɾ����....\n");
            return StartGame();
        }
        if (Level.GetCurrentLocation() == LocationID::AvonSanctum)
        {
            // ���� ���� �̺�Ʈ�� ����
            LastBossEvent(&player);
        }
    }
}

void GameManager::BattleMenu(Player* InPlayer, Poet* InPoet)
{
    int InputNumber = 0;

    while (InPlayer->IsAlivePlayer() && InPoet->GetPoetHealth() > 0)
    {
        printf("\n--- ���� �޴� ---\n");
        printf("[���ݷ� : %d]\t[ü�� : %d/%d]\n", InPlayer->GetPlayerAttackPower(), InPlayer->GetPlayerHealth(), InPlayer->GetPlayerMaxHealth());
        printf("�� �ø� �д´�\t�� ������ ��ģ��\n");
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
                    printf("%d. ���� �� (���ݷ� +5)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::DantePoem:
                    printf("%d. �Ű� (20~45�� ����)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::GoethePoem:
                    printf("%d. ���� (ü�� 10�� �Ҹ��ϰ� �߰� ����)\n", static_cast<int>(i) + 1);
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
        printf("\n�й��ߴ�...\n\n\n");
    }
}

void GameManager::LastBossEvent(Player* player)
{
    int SelectNumber = 0;
    bool EndGame = false;

    while (!EndGame && player->IsAlivePlayer())
    {
        printf("\n=== (Avon Sanctum) ===\n");
        printf("�� ��ȭ�ϱ� �� ���濭��\n");
        printf("> ����: ");
        std::cin >> SelectNumber;

        switch (SelectNumber)
        {
        case 1: // ��ȭ�ϱ�
        {
            printf("\n������: ���ݱ��� ���� ������ ��� ���� �ٿ�.\n\n");
            printf("�� �ش�\n�� �����Ѵ�");
            printf("\n> ����: ");
            int Choice = 0;
            std::cin >> Choice;

            if (Choice == 1) // �ش� �� ��� ����
            {
                int Current = player->GetPlayerHealth();
                printf("??? : %ls... �׵��� ��ſ���.\n", player->GetName().c_str());
                player->TakeDamage(player->GetPlayerHealth()); // ü�� 0����
                printf("\n[ü�� : %d] -> [ü�� : %d]\n", Current, player->GetPlayerHealth());
                printf("\n--- ��� ���� ---\n\n\n\n\n");
                return StartGame();
            }
            else if (Choice == 2) // �����Ѵ� �� ���� ������
            {
                printf("������\n");
                Sleep(1500);
                printf("����X\n");
                Sleep(1500);
                printf("��XX\n");
                Sleep(1500);
                printf("XXX\n");
                Sleep(1500);
                printf("?????????\n");
                Sleep(1500);
                printf("������ ���ͽ��Ǿ�: ��¿ �� ����... ���븦 �غ��ϴ� �� �ۿ�...\n");
                FinalBossBattle(player);   // ���ͽ��Ǿ� ���� �Լ� ȣ��
                EndGame = true;
            }
            else
            {
                printf("�߸��� �Է��Դϴ�.\n");
            }
        }
        break;

        case 2: // ���� ����
        {
            player->OpenInventory();
        }
        break;

        default:
            printf("�߸��� �Է��Դϴ�.\n");
            break;
        }
    }
}

void GameManager::FinalBossBattle(Player* InPlayer)
{
    TwilightPoet finalBoss("������ ���ͽ��Ǿ�", 500, 30);

    // ===== ���� ���� =====
    int InputNumber = 0;
    int ShakespearePhase = 1;  // ������1 (�Ϲ�), ������2 (ü�� ���� �����϶� Ư�� ��ų ��)
    int Script = 1; 
    while (InPlayer->IsAlivePlayer() && finalBoss.IsAlive())
    {
        printf("\n--- ���� ���� ���� ---\n");
        printf("[���ݷ� : %d]\t[ü�� : %d/%d]\n", InPlayer->GetPlayerAttackPower(), InPlayer->GetPlayerHealth(), InPlayer->GetPlayerMaxHealth());
        printf("�� �ø� �д´�\t�� ������ ��ģ��\n");
        printf("> ����: ");
        std::cin >> InputNumber;

        if (InputNumber == 1)
        {
            printf("[%s�� ü��: %d/500]\n\n", finalBoss.GetName().c_str(), finalBoss.GetHealth());
            // �÷��̾� ����
            InPlayer->RecitePoemAttack(&finalBoss);
            if (!finalBoss.IsAlive()) break;

            // ���ͽ��Ǿ� ����
            if(ShakespearePhase == 1)
            {
                finalBoss.Attack(InPlayer);
                if (!InPlayer->IsAlivePlayer()) break;
            }
            else if ((ShakespearePhase == 2)&&(Script < 4))
            {
                switch (Script)
                {
                case 1:
                {
                    printf("������ ���ͽ��Ǿ�: �����ϱ��� ������.\n");
                    Script++;
                }
                break;
                case 2:
                {
                    printf("������ ���ͽ��Ǿ�: ���� �ô� ������ ���� �ʴ´�.\n");
                    Script++;
                }
                break;
                case 3:
                {
                    printf("������ ���ͽ��Ǿ�: �̷��ϰ� �߹��� ġ�� �ڿ�.\n");
                    Script++;
                }
                break;
                default:
                    break;
                }                
            }
            printf("[%s�� ü��: %d/500]\n\n", finalBoss.GetName().c_str(), finalBoss.GetHealth());
        }
        else if (InputNumber == 2)
        {
            if ((ShakespearePhase == 1) || (ShakespearePhase == 2))
            {
                printf("\n%s: �̹� �ʰ� ������ �� ��ġ�� ���� ���Ƴ���!\n", finalBoss.GetName().c_str());
            }
            if (ShakespearePhase == 3)
            {
                while(true)
                {
                    printf("\n1. ��?????��\n");
                    int SkillChoice;
                    std::cin >> SkillChoice;
                    printf("\n> ����: ");
                    if (SkillChoice == 1)
                    {
                        printf("��[���� ��]���� �Ǿ [����]�� [�񿡵� ���� �ʴ�] [���޷� ��] ó�� [Ȱ]�� ��� [�Ű�]�� �뷡�ϳ�.��\n");
                        finalBoss.TakeDamage(500);
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
            printf("�߸��� �Է��Դϴ�.\n");
        }

        // ===== ü�� ���� ���� ������ ��ȯ =====
        if ((ShakespearePhase == 1) && (finalBoss.GetHealth() <= 250))
        {
            ShakespearePhase = 2;
            printf("\n%s: ���� ���� �ø� ÷��������� �����غ���!\n", finalBoss.GetName().c_str());
            InPlayer->ForceSetAttackPower(1);   // ���ݷ��� 1�� ����
            InPlayer->ForceSetHealth(1);        // ���� ü���� 1�� ����
            InPlayer->ForceSetMaxHealth(1);     // �ִ� ü���� 1�� ����
            printf("�÷��̾��� ���ݷ°� ü���� 1�� ���εǾ���!\n");
        }

        // ===== �÷��̾ �⺻ ���� 3�� �ϸ� ������ ������ =====

        if ((ShakespearePhase == 2) && (Script == 4))
        {
            printf("\n����� ���� ��� ������ �ϳ��� �������� ��������!\n");
            printf("������ ���ͽ��Ǿ�: �����Ͽ� �ʸ��� �����ϴ°�! \n");
            ShakespearePhase = 3;
        }

        // ===== ���� ��ų �ߵ� =====
        if ((ShakespearePhase == 3)&&EndTrigger)
        {
            printf("\n--- ������ �ٽ� ��ĥ �� �ֽ��ϴ�. ---\n");
            EndTrigger = false;
        }
    }

    if (InPlayer->IsAlivePlayer())
    {
        std::string bossLine = "\nTime shall pluck the crown from off my brow, " "and Death shall hush this mortal clay to silence.\n\n\n";

        printf("%s: ", finalBoss.GetName().c_str());   // ���� �̸� ���� ���
        TypeWriterPrint(bossLine, 50);   // ���� ��� ��� (50ms �������� �� ���ھ�)
        printf("=========================================\n");
        printf("              P O E T   W A R            \n");
        printf("                                         \n");
        printf("               T H E    E N D            \n");
        printf("=========================================\n\n\n");
        wprintf(L"\"%ls\"\n", InPlayer->GetPoem().c_str());
    }
    else
    {
        printf("\n�÷��̾�� ��������...\n");
        printf("\n--- ��� ���� ---\n\n\n\n\n");
        return StartGame();
    }
}


/*
            ���� ���� ��
    1. AvonSanctumMap()�� ����
    2. ExploreMenu()���� ��ȭ�ϱ�� ���濭�⸸ ����
    3. ��ȭ�ϱ⸦ �ϸ� ������ ��ũ�� ����ؼ� ��ȭ �� ü�� ȸ���� ����µ�, �����ְ� ���ݱ��� ���� ������ �޶�� �ϴ� �������� �ٲ�
    4. ���⼭ �÷��̾�� 1. �ش�, 2. �� �ش� ������ �� �� ����
    5. �شٷ� �����ϸ�, �����ְ� ???��� �̸����� �ٲ�� "(�÷��̾�)... �׵��� ��� �־���." �ϸ鼭 �ٷ� �÷��̾��� ü���� 0���� ����� ��� ���� ���
    6. �� �شٷ� �����ϸ� ���� ���·� ������. �����ְ� ������ ���ͽ��Ǿ�� �̸��� �ٲ�
    7. ���ͽ��Ǿ��� ü���� ���� �Ʒ��� �������� �÷��̾��� �ִ� ü�°� ���ݷ��� 1�� �ٲٰ� ��ųâ�� (������)
    8. �⺻ ���� 3���� �ϸ�, ���ݱ��� ���� ������ �ϳ��� �������� �������� ��ųâ�� �ٽ� ����
    9. ��ųâ���� �� �ϳ��� ���常 �����ϰ�, �� ��ų�� �Է��ҽ� ���� ���� ���ͽ��Ǿ��� �й�
    10. ������ ���ߴٴ� �� �� ������ �߸鼭, �÷��̾ ���� �� ������ �߰� ���� ��

*/