#include "GameManager.h"
#include <iostream>
#include <cstdio>
#include <locale>
#include <codecvt>   // string <-> wstring 변환
#include "Map.h"
#include "Chapters.h"
#include "Battles.h"
#include <string>
#include <windows.h>
#include <chrono>     // 시간 단위(std::chrono::milliseconds) 사용
#include <thread>     // std::this_thread::sleep_for 사용
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

void GameManager::TypeWriterPrint(const std::string& text, int delay_ms)
{
    for (char c : text)
    {
        printf("%c", c);        // 현재 문자를 콘솔에 출력
        fflush(stdout);         // 출력 버퍼를 비워 즉시 화면에 보이게 함
        std::this_thread::sleep_for(
            std::chrono::milliseconds(delay_ms));
        // delay_ms 밀리초 동안 대기 (타자기 속도 조절) 
    }
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

void GameManager::TutorialBattle(Player* player, TwilightPoet* Yoon)
{
    Map Fmap;
    printf("\n윤동주: 너에게 시인이 어떻게 글의 힘을 쓰는지 알려줄게.\n");
    printf("윤동주: 이렇게 나 처럼 시인을 만나면 전투 상태가 되는데 너가 쓴 시를 읽어주면 돼.\n\n");

    int InputNumber = 0;
    int InputNumber2 = 0;

    while (player->IsAlivePlayer() && Yoon->IsAlive())
    {
        printf("\n--- 전투 메뉴 ---\n");
        printf("[공격력 : %d]\t[체력 : %d/%d]\n", player->GetPlayerAttackPower(), player->GetPlayerHealth(), player->GetPlayerMaxHealth());
        printf("① 시를 읽는다\n");
        printf("> 선택: ");
        std::cin >> InputNumber;
        if (InputNumber == 1)
        {
            // 플레이어 턴
            player->Attack(Yoon);
            if (!Yoon->IsAlive())
            {
                break;
            }

            // 윤동주 턴
            Yoon->Attack(player);
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
            printf("\n--- 탐험 메뉴 ---\n");
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
                    printf("\n--- 이동하기 ---\n");
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

        // 플레이어가 살아있고, 현재 위치가 최종 보스전이 아닐 때만
    while (player.IsAlivePlayer() && Level.GetCurrentLocation() != LocationID::AvonSanctum) 
    {
        printf("\n--- 탐험 메뉴 ---\n");
        printf("① 대화하기 ② 이동하기 ③ 조사하기 ④ 가방열기\n");
        printf("> 선택: ");
        std::cin >> SelectNumber;
        switch (SelectNumber)
        {  
        case 1:
        {
            printf("\n--- 대화하기 ---\n");
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
            printf("\n--- 가방열기 ---\n");
            player.OpenInventory();
        }
        break;
        default:
        {
            printf("\n잘못된 입력이야! 다시 입력해줘\n");
        }
        break;
        }
        if (!player.IsAlivePlayer())    // 죽으면 다시 처음부터 시작
        {
            printf("세상은 점점 더 파멸 속으로 걸어가겠지....\n");
            return StartGame();
        }
        if (Level.GetCurrentLocation() == LocationID::AvonSanctum)
        {
            // 최종 보스 이벤트로 진입
            LastBossEvent(&player);
        }
    }
}

void GameManager::BattleMenu(Player* InPlayer, Poet* InPoet)
{
    int InputNumber = 0;

    while (InPlayer->IsAlivePlayer() && InPoet->GetPoetHealth() > 0)
    {
        printf("\n--- 전투 메뉴 ---\n");
        printf("[공격력 : %d]\t[체력 : %d/%d]\n", InPlayer->GetPlayerAttackPower(), InPlayer->GetPlayerHealth(), InPlayer->GetPlayerMaxHealth());
        printf("① 시를 읽는다\t② 시집을 펼친다\n");
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
                    printf("%d. 악의 꽃 (공격력 +5)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::DantePoem:
                    printf("%d. 신곡 (20~45의 피해)\n", static_cast<int>(i) + 1);
                    break;
                case Poem::GoethePoem:
                    printf("%d. 마왕 (체력 10을 소모하고 추가 피해)\n", static_cast<int>(i) + 1);
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
        printf("\n패배했다...\n\n\n");
    }
}

void GameManager::LastBossEvent(Player* player)
{
    int SelectNumber = 0;
    bool EndGame = false;

    while (!EndGame && player->IsAlivePlayer())
    {
        printf("\n=== (Avon Sanctum) ===\n");
        printf("① 대화하기 ② 가방열기\n");
        printf("> 선택: ");
        std::cin >> SelectNumber;

        switch (SelectNumber)
        {
        case 1: // 대화하기
        {
            printf("\n윤동주: 지금까지 모은 시집을 모두 내게 다오.\n\n");
            printf("① 준다\n② 거절한다");
            printf("\n> 선택: ");
            int Choice = 0;
            std::cin >> Choice;

            if (Choice == 1) // 준다 → 배드 엔딩
            {
                int Current = player->GetPlayerHealth();
                printf("??? : %ls... 그동안 즐거웠다.\n", player->GetName().c_str());
                player->TakeDamage(player->GetPlayerHealth()); // 체력 0으로
                printf("\n[체력 : %d] -> [체력 : %d]\n", Current, player->GetPlayerHealth());
                printf("\n--- 배드 엔딩 ---\n\n\n\n\n");
                return StartGame();
            }
            else if (Choice == 2) // 거절한다 → 최종 보스전
            {
                printf("윤동주\n");
                Sleep(1500);
                printf("윤동X\n");
                Sleep(1500);
                printf("윤XX\n");
                Sleep(1500);
                printf("XXX\n");
                Sleep(1500);
                printf("?????????\n");
                Sleep(1500);
                printf("윌리엄 셰익스피어: 어쩔 수 없군... 무대를 준비하는 수 밖에...\n");
                FinalBossBattle(player);   // 셰익스피어 전투 함수 호출
                EndGame = true;
            }
            else
            {
                printf("잘못된 입력입니다.\n");
            }
        }
        break;

        case 2: // 가방 열기
        {
            player->OpenInventory();
        }
        break;

        default:
            printf("잘못된 입력입니다.\n");
            break;
        }
    }
}

void GameManager::FinalBossBattle(Player* InPlayer)
{
    TwilightPoet finalBoss("윌리엄 셰익스피어", 500, 30);

    // ===== 전투 루프 =====
    int InputNumber = 0;
    int ShakespearePhase = 1;  // 페이즈1 (일반), 페이즈2 (체력 절반 이하일때 특수 스킬 씀)
    int Script = 1; 
    while (InPlayer->IsAlivePlayer() && finalBoss.IsAlive())
    {
        printf("\n--- 최종 보스 전투 ---\n");
        printf("[공격력 : %d]\t[체력 : %d/%d]\n", InPlayer->GetPlayerAttackPower(), InPlayer->GetPlayerHealth(), InPlayer->GetPlayerMaxHealth());
        printf("① 시를 읽는다\t② 시집을 펼친다\n");
        printf("> 선택: ");
        std::cin >> InputNumber;

        if (InputNumber == 1)
        {
            printf("[%s의 체력: %d/500]\n\n", finalBoss.GetName().c_str(), finalBoss.GetHealth());
            // 플레이어 공격
            InPlayer->RecitePoemAttack(&finalBoss);
            if (!finalBoss.IsAlive()) break;

            // 셰익스피어 공격
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
                    printf("윌리엄 셰익스피어: 무력하구나 무력해.\n");
                    Script++;
                }
                break;
                case 2:
                {
                    printf("윌리엄 셰익스피어: 너의 시는 나에게 닿지 않는다.\n");
                    Script++;
                }
                break;
                case 3:
                {
                    printf("윌리엄 셰익스피어: 미력하게 발버둥 치는 자여.\n");
                    Script++;
                }
                break;
                default:
                    break;
                }                
            }
            printf("[%s의 체력: %d/500]\n\n", finalBoss.GetName().c_str(), finalBoss.GetHealth());
        }
        else if (InputNumber == 2)
        {
            if ((ShakespearePhase == 1) || (ShakespearePhase == 2))
            {
                printf("\n%s: 이미 너가 시집을 못 펼치게 내가 막아놨지!\n", finalBoss.GetName().c_str());
            }
            if (ShakespearePhase == 3)
            {
                while(true)
                {
                    printf("\n1. 『?????』\n");
                    int SkillChoice;
                    std::cin >> SkillChoice;
                    printf("\n> 선택: ");
                    if (SkillChoice == 1)
                    {
                        printf("『[악의 꽃]에서 피어난 [마왕]은 [비에도 지지 않는] [진달래 꽃] 처럼 [활]을 들고 [신곡]을 노래하네.』\n");
                        finalBoss.TakeDamage(500);
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
            printf("잘못된 입력입니다.\n");
        }

        // ===== 체력 절반 이하 페이즈 전환 =====
        if ((ShakespearePhase == 1) && (finalBoss.GetHealth() <= 250))
        {
            ShakespearePhase = 2;
            printf("\n%s: 누가 너의 시를 첨삭해줬는지 생각해봐라!\n", finalBoss.GetName().c_str());
            InPlayer->ForceSetAttackPower(1);   // 공격력을 1로 고정
            InPlayer->ForceSetHealth(1);        // 현재 체력을 1로 고정
            InPlayer->ForceSetMaxHealth(1);     // 최대 체력을 1로 고정
            printf("플레이어의 공격력과 체력이 1로 봉인되었다!\n");
        }

        // ===== 플레이어가 기본 공격 3번 하면 시집이 합쳐짐 =====

        if ((ShakespearePhase == 2) && (Script == 4))
        {
            printf("\n당신이 모은 모든 시집이 하나의 문장으로 합쳐졌다!\n");
            printf("윌리엄 셰익스피어: 어찌하여 필멸을 갈구하는가! \n");
            ShakespearePhase = 3;
        }

        // ===== 최종 스킬 발동 =====
        if ((ShakespearePhase == 3)&&EndTrigger)
        {
            printf("\n--- 시집을 다시 펼칠 수 있습니다. ---\n");
            EndTrigger = false;
        }
    }

    if (InPlayer->IsAlivePlayer())
    {
        std::string bossLine = "\nTime shall pluck the crown from off my brow, " "and Death shall hush this mortal clay to silence.\n\n\n";

        printf("%s: ", finalBoss.GetName().c_str());   // 보스 이름 먼저 출력
        TypeWriterPrint(bossLine, 50);   // 보스 대사 출력 (50ms 간격으로 한 글자씩)
        printf("=========================================\n");
        printf("              P O E T   W A R            \n");
        printf("                                         \n");
        printf("               T H E    E N D            \n");
        printf("=========================================\n\n\n");
        wprintf(L"\"%ls\"\n", InPlayer->GetPoem().c_str());
    }
    else
    {
        printf("\n플레이어는 쓰러졌다...\n");
        printf("\n--- 배드 엔딩 ---\n\n\n\n\n");
        return StartGame();
    }
}


/*
            최종 보스 전
    1. AvonSanctumMap()에 도착
    2. ExploreMenu()에서 대화하기랑 가방열기만 있음
    3. 대화하기를 하면 원래는 잉크를 사용해서 강화 및 체력 회복을 해줬는데, 윤동주가 지금까지 모은 시집을 달라고 하는 문장으로 바뀜
    4. 여기서 플레이어는 1. 준다, 2. 안 준다 선택을 할 수 있음
    5. 준다로 선택하면, 윤동주가 ???라는 이름으로 바뀌고 "(플레이어)... 그동안 재미 있었다." 하면서 바로 플레이어의 체력을 0으로 만들고 배드 엔딩 띄움
    6. 안 준다로 선택하면 전투 상태로 돌입함. 윤동주가 윌리엄 셰익스피어로 이름이 바뀜
    7. 셰익스피어의 체력이 절반 아래로 떨어지면 플레이어의 최대 체력과 공격력을 1로 바꾸고 스킬창이 (없어짐)
    8. 기본 공격 3번을 하면, 지금까지 모은 시집이 하나의 문장으로 합쳐지고 스킬창이 다시 생김
    9. 스킬창에는 그 하나의 문장만 존재하고, 그 스킬을 입력할시 최종 보스 셰익스피어의 패배
    10. 세상을 구했다는 듯 한 엔딩이 뜨면서, 플레이어가 지은 시 구절이 뜨고 게임 끝

*/