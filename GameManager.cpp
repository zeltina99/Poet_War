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
            if (player.GetInk() >= 50)
            {
                // ��ũ�� �ִٸ�
                printf("������: ���� �� ȸ���ҷ�? �ƴϸ� �ø� ÷�� ���ٱ�?\n");
                int InputNumber1 = -1;
                while(InputNumber1 != 1 && InputNumber1 != 2 && InputNumber1 != 3)
                {
                    printf("�� ��ũ 50�� �Ἥ ü���� ȸ���Ѵ�\n��ø� ÷���Ѵ�\n�� �ڷΰ���  : ");
                    std::cin >> InputNumber1;
                    if (InputNumber1 == 1)
                    {
                        player.PlayerHeal(50);
                    }
                    else if(InputNumber1 == 2)
                    {
                        if (player.GetInk() >= 150)
                        {
                            printf("������: ����! �ø� ÷�� ���ٰ�.\n");
                            int InputNumber2 = -1;
                            // �� ��ũ 150�� �Ἥ �ø� ��ȭ�ϱ�(�⺻ ���ݷ� ����), �� ��ũ 150�� �Ἥ �������� �ø� �б�(�ִ� ü�� ����)
                            while (InputNumber2 != 1 && InputNumber2 != 2 && InputNumber2 != 3)   // 1,2,3���� �ϳ��� �Է��� �ȵǸ� ��� �ݺ�
                            {
                                printf("�� ��ũ 150�� �Ἥ �ø� ��ȭ�ϱ�\n�� ��ũ 150�� �Ἥ �������� �ø� �б�\n�� �ڷΰ��� : ");
                                std::cin >> InputNumber2;
                                if (InputNumber2 == 1)
                                {
                                    player.PayInk(150);
                                    player.AttackPowerUP();
                                }
                                else if (InputNumber2 == 2)
                                {
                                    player.PayInk(150);
                                    player.HealthPowerUP();
                                }
                                else if (InputNumber2 == 3)
                                {
                                    //�ڷΰ���
                                }
                                else
                                {
                                    printf("\n�߸��� �Է��̾�! �ٽ� �Է�����\n");
                                }
                            }
                        }
                        else
                        {
                            printf("������: ���� �ø� ÷�� ���ְ� �; ��ũ�� �ּ��� 150�� �־����.\n");
                        }
                    }
                    else if (InputNumber1 == 3)
                    {
                        //�ڷΰ���
                    }
                    else
                    {
                        printf("\n�߸��� �Է��̾�! �ٽ� �Է�����\n");
                    }
                }
                
            }
            else
            {
                // ��ũ�� ���ٸ�
                printf("������: ������ ��ũ�� �ʿ���...\n");
            }
        }
        break;
        case 2:
        {
            Level.LevelChapters(&player);
        }
        break;
        case 3:
        {
            LocationID loc = Level.GetCurrentLocation();    // enum class�� �� ��ġ ���� ����

            switch (loc)
            {
            case LocationID::Scentveil:
            {
                if (Level.IsPoetAlive(PoetID::CharlesID))   // ������ ��� ������
                {
                    printf("���� ���鷹��: Ÿ�� �ӿ��� ���� �ǿ��ָ�.\n");
                    // ���� ���� ����
                    Level.CharlesChapter(&player);  // ���� �Լ� ����
                }
                else
                {
                    printf("���� �̹� ����ϴ�... (������ ����Ʈ�ȴ�)\n");
                }
            }
                break;
            case LocationID::Infernia:
            {
                if (Level.IsPoetAlive(PoetID::DanteID))     // ���װ� ��� ������
                {
                    printf("����: ���� ��ȥ�� ���� �÷ν� ������ �����ڴ�.\n");
                    // ���� ���� ����
                    Level.DanteChapter(&player);  // ���� �Լ� ����
                }
                else
                {
                    printf("�̹� ������ �帥��... (���׸� ����Ʈ�ȴ�)\n");
                }
            }
                break;

            case LocationID::Shercroft:
            {
                if (Level.IsPoetAlive(PoetID::ConanID))     // �ڳ������� ��� ������
                {
                    printf("�Ƽ� �ڳ�����: �Ұ����� ���� ��� ���ָ�, ���� �� ���� ��.\n");
                    Level.ConanChapter(&player);
                }
                else
                {
                    printf("���� �̹� ����ϴ�... (�ڳ������� ����Ʈ�ȴ�)\n");
                }
            }
                break;

            case LocationID::Faustburg:
            {
                if (Level.IsPoetAlive(PoetID::GoetheID))    // ���װ� ��� ������
                {
                    printf("����: ����� ����� ����� ������ �������.\n");
                    Level.GoetheChapter(&player);
                }
                else
                {
                    printf("�̹� ������ �帥��... (���׸� ����Ʈ�ȴ�)\n");
                }
            }
                break;

            case LocationID::Kazehamura:
            {
                if (Level.IsPoetAlive(PoetID::KenjiID))     // ������ ��� ������
                {
                    printf("�̾��ڿ� ����: �ҹ��� ���������� ������ ǰ�´�.\n");
                    Level.KenjiChapter(&player);
                }
                else
                {
                    printf("���� �̹� ����ϴ�... (������ ����Ʈ�ȴ�)\n");
                }
            }
                break;

            case LocationID::Azalean:
            {
                if (Level.IsPoetAlive(PoetID::KimSowolID))      // ��ҿ��� ��� ������
                {
                    printf("��ҿ�: �������� ���� �̺��� ȥ, ���� ���� ȥ�� ������.\n");
                    Level.KimSowolChapter(&player);
                }
                else
                {
                    printf("�̹� ������ �帥��... (��ҿ��� ����Ʈ�ȴ�)\n");
                }
            }
                break;

            case LocationID::AvonSanctum:
            {
                printf("�������� ���� ��...\n");
                Level.BoseChapter(&player);
            }
                break;

            case LocationID::None:
            default:
                printf("���⼭�� �ƹ��� �߰ߵ��� �ʾҴ�...\n");
                break;
            }
        }
        break;
        case 4:
        {
            // enum class�� ���� �������� ������
            player.ShowInventory();
            printf("\n �̸� : ");
            player.GetName();
            printf("\n ���� ��ũ�� : ");
            player.GetInk();
            printf("\n ���ݷ� : ");
            player.GetPlayerAttackPower();
            printf("\n ü�� : ");
            player.GetPlayerHealth();
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

void GameManager::BattleMenu()
{

    /*
    �� player.RecitePoemAttack();    �⺻���� (�� �Լ� �ȿ� Attack �Լ� ó����)
    �� player.UnleashPoemSkill();    ��ų���� (������ �̱�� ���� �������� ��ų�� �� �� ���� (�ణ �ް��� ����?)
    */


}
