#include "GameManager.h"
#include <iostream>
#include <cstdio>
#include <locale>
#include <codecvt>   // string <-> wstring 변환
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
    printf("1. 게임 시작\n2. 종료\n");

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

    setlocale(LC_ALL, ""); // 콘솔 로케일 맞추기

    std::wstring PlayerName;
    wprintf(L"윤동주: 너의 이름은 무엇이니?\n> ");
    std::wcin >> PlayerName;

    wprintf(L"윤동주: %ls... 좋은 이름이네.\n", PlayerName.c_str());
    printf("윤동주: 이 세계는 [Word World]야, 즉 글의 힘을 다스리는 자들, '시인'이 존재하지.\n");
    printf("윤동주: 그 힘으로 세상을 어지럽히는 자들을 막아야 한다.\n\n");

    wprintf(L"윤동주: 네가 쓰고 싶은 시 한 구절을 적어보아라. 단 20글자 안으로 부탁할게...\n> ");
    std::wcin.ignore();
    std::wstring Poem;
    std::getline(std::wcin, Poem);

    player.Init(PlayerName);
    player.SetPoem(Poem);
    player.DecideAttackPower();

    TwilightPoet yoon("윤동주", 100, 5);
    TutorialBattle(&player, &yoon);
}

void GameManager::TutorialBattle(Player* player, TwilightPoet* twilight)
{
    Map Fmap;
    printf("\n윤동주: 너에게 시인이 어떻게 글의 힘을 쓰는지 알려줄게.\n");
    printf("윤동주: 이렇게 나 처럼 시인을 만나면 전투 상태가 되는데 너가 쓴 시를 읽어주면 돼.\n\n");

    int InputNumber = 0;
    int InputNumber2 = 0;

    while (player->IsAlivePlayer() && twilight->IsAlive())
    {
        printf("① 시를 읽는다\n");
        printf("> 선택: ");
        std::cin >> InputNumber;
        if (InputNumber == 1)
        {
            // 플레이어 턴
            player->Attack(twilight);
            if (!twilight->IsAlive())
            {
                break;
            }

            // 윤동주 턴
            twilight->Attack(player);
            if (!player->IsAlivePlayer())
            {
                break;
            }
        }
        else
        {
            printf("\n잘못된 입력이야! 다시 입력해줘\n");
        }
    }

    if (player->IsAlivePlayer())
    {
        printf("\n윤동주: 잘했어! 이게 시의 능력이야. 내가 다시 회복 시켜줄게.\n");
        player->PlayerHeal(100);
        printf("\n윤동주: 이제 다른 시인들을 만나러 갈거야, 만약 시인과 싸워서 이기면 나한테 대화해줘 너의 시를 내가 첨삭해줄게.\n");
        while (InputNumber2 != 1)
        {
            printf("\n① 이동하기\n");
            printf("> 선택: ");
            std::cin >> InputNumber2;

            if (InputNumber2 != 1)
            {
                printf("\n잘못된 입력이야! 다시 입력해줘\n");
            }
            else
            {
                while (true)
                {
                    printf("\n① 향기의 장막\n");
                    printf("> 선택: ");
                    std::cin >> InputNumber2;
                    if (InputNumber2 != 1)
                    {
                        printf("\n잘못된 입력이야! 다시 입력해줘\n");
                    }
                    else
                    {
                        Fmap.ScentveilMap();
                        printf("윤동주: 여긴 향기의 장막이야... 우린 여기서 상징주의의 시인 [샤를 보들레르]를 찾아야해.\n\n");
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\n윤동주: 미안, 내가 너무 강했나?\n");
    }
}




void GameManager::ExploreMenu()
{
    /*
    ① player.TalkToYoon();      대화하기
    ② player.MoveToLocation();  이동하기
    ③ player.InvestigateArea(); 조사하기 (시인을 만남)
    ④ player.OpenInventory();   가방열기 (플레이어의 정보와 시집과 잔여 골드가 나옴)
    */
    int SelectNumber = 0;

    while(true)
    {
        printf("① 대화하기 ② 이동하기 ③ 조사하기 ④ 가방열기\n");
        printf("> 선택: ");
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
            // enum class에 넣은 시집들을 보여줌
            player.OpenInventory();
        }
        break;
        default:
        {
            printf("\n잘못된 입력이야! 다시 입력해줘\n");
        }
        break;
        }
       
    }// if (보스가 죽거나 내가 죽거나) -> return
}

void GameManager::BattleMenu(Player* InPlayer, Poet* InPoet)
{
    int InputNumber = 0;

    while (InPlayer->IsAlivePlayer() && InPoet->GetPoetHealth() > 0)
    {
        printf("\n--- 전투 메뉴 ---\n");
        printf("① 시를 읽는다 (기본 공격)\n");
        printf("② 시집을 펼친다 (스킬)\n");
        printf("> 선택: ");
        std::cin >> InputNumber;

        if (InputNumber == 1)
        {
            // 플레이어 턴 (기본공격)
            InPlayer->RecitePoemAttack(InPoet);
            if (InPoet->GetPoetHealth() <= 0)
            {
                break;
            }

            // 적(시인) 턴
            InPoet->Attack(InPlayer);
            if (!InPlayer->IsAlivePlayer())
            {
                break;
            }
        }
        else if (InputNumber == 2)
        {
            // 보유한 시집 스킬 확인
            const auto& poems = InPlayer->GetPoems();
            if (poems.empty())
            {
                printf("아직 획득한 시집이 없다!\n");
                continue;  // 턴을 소비하지 않고 다시 선택
            }

            printf("\n--- 사용 가능한 시집 ---\n");
            for (size_t i = 0; i < poems.size(); ++i)
            {
                switch (poems[i])
                {
                case Poem::CharlesPoem:
                    printf("%d. 악의 꽃 (공격력 2배)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::DantePoem:
                    printf("%d. 신곡 (추가 피해)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::GoethePoem:
                    printf("%d. 마왕 (추가 피해)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::KimSowolPoem:
                    printf("%d. 진달래꽃 (체력 회복)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::ConanPoem:
                    printf("%d. 활의 노래 (추가 피해)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::KenjiPoem:
                    printf("%d. 비에도 지지 않고 (체력 회복)\n", static_cast<int>(i) + 1);
                    break;
                }
            }
            printf("0. 취소\n");

            int poemChoice;
            printf("> 선택: ");
            std::cin >> poemChoice;

            if (poemChoice == 0)
            {
                continue;
            }
            if (poemChoice < 1 || poemChoice >static_cast<int>(poems.size()))
            {
                printf("잘못된 입력이다.\n");
                continue;
            }

            Poem chosenPoem = poems[poemChoice - 1];

            // 시집 스킬 발동 (아이템 소모 X)
            InPlayer->UnleashPoemSkill(chosenPoem, InPoet);

            if (InPoet->GetPoetHealth() <= 0)
            {
                break;
            }

            // 적 턴
            InPoet->Attack(InPlayer);
            if (!InPlayer->IsAlivePlayer())
            {
                break;
            }
        }
        else
        {
            printf("잘못된 입력이야! 다시 입력해줘\n");
        }
    }

    if (InPlayer->IsAlivePlayer())
    {
        printf("\n승리했다!\n");
    }
    else
    {
        printf("\n패배했다...\n");
    }
}
