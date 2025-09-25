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
            if (player.GetInk() >= 50)
            {
                // 잉크가 있다면
                printf("윤동주: 몸을 좀 회복할래? 아니면 시를 첨삭 해줄까?\n");
                int InputNumber1 = -1;
                while(InputNumber1 != 1 && InputNumber1 != 2 && InputNumber1 != 3)
                {
                    printf("① 잉크 50을 써서 체력을 회복한다\n②시를 첨삭한다\n③ 뒤로가기  : ");
                    std::cin >> InputNumber1;
                    if (InputNumber1 == 1)
                    {
                        player.PlayerHeal(50);
                    }
                    else if(InputNumber1 == 2)
                    {
                        if (player.GetInk() >= 150)
                        {
                            printf("윤동주: 좋아! 시를 첨삭 해줄게.\n");
                            int InputNumber2 = -1;
                            // ① 잉크 150을 써서 시를 강화하기(기본 공격력 증가), ② 잉크 150을 써서 윤동주의 시를 읽기(최대 체력 증가)
                            while (InputNumber2 != 1 && InputNumber2 != 2 && InputNumber2 != 3)   // 1,2,3에서 하나라도 입력이 안되면 계속 반복
                            {
                                printf("① 잉크 150을 써서 시를 강화하기\n② 잉크 150을 써서 윤동주의 시를 읽기\n③ 뒤로가기 : ");
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
                                    //뒤로가기
                                }
                                else
                                {
                                    printf("\n잘못된 입력이야! 다시 입력해줘\n");
                                }
                            }
                        }
                        else
                        {
                            printf("윤동주: 내가 시를 첨삭 해주고 싶어도 잉크가 최소한 150은 있어야해.\n");
                        }
                    }
                    else if (InputNumber1 == 3)
                    {
                        //뒤로가기
                    }
                    else
                    {
                        printf("\n잘못된 입력이야! 다시 입력해줘\n");
                    }
                }
                
            }
            else
            {
                // 잉크가 없다면
                printf("윤동주: 시인은 잉크가 필요해...\n");
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
            LocationID loc = Level.GetCurrentLocation();    // enum class로 한 위치 값을 받음

            switch (loc)
            {
            case LocationID::Scentveil:
            {
                if (Level.IsPoetAlive(PoetID::CharlesID))   // 샤를이 살아 있으면
                {
                    printf("샤를 보들레르: 타락 속에서 꽃을 피워주마.\n");
                    // 샤를 전투 실행
                    Level.CharlesChapter(&player);  // 전투 함수 연결
                }
                else
                {
                    printf("여긴 이미 고요하다... (샤를을 쓰러트렸다)\n");
                }
            }
                break;
            case LocationID::Infernia:
            {
                if (Level.IsPoetAlive(PoetID::DanteID))     // 단테가 살아 있으면
                {
                    printf("단테: 나는 영혼의 길을 시로써 밝혀줄 순례자다.\n");
                    // 단테 전투 실행
                    Level.DanteChapter(&player);  // 전투 함수 연결
                }
                else
                {
                    printf("이미 정적만 흐른다... (단테를 쓰러트렸다)\n");
                }
            }
                break;

            case LocationID::Shercroft:
            {
                if (Level.IsPoetAlive(PoetID::ConanID))     // 코난도일이 살아 있으면
                {
                    printf("아서 코난도일: 불가능한 것을 모두 없애면, 남는 건 진실 뿐.\n");
                    Level.ConanChapter(&player);
                }
                else
                {
                    printf("여긴 이미 고요하다... (코난도일을 쓰러트렸다)\n");
                }
            }
                break;

            case LocationID::Faustburg:
            {
                if (Level.IsPoetAlive(PoetID::GoetheID))    // 괴테가 살아 있으면
                {
                    printf("괴테: 욕망과 운명을 꿰뚫은 눈으로 상대하지.\n");
                    Level.GoetheChapter(&player);
                }
                else
                {
                    printf("이미 정적만 흐른다... (괴테를 쓰러트렸다)\n");
                }
            }
                break;

            case LocationID::Kazehamura:
            {
                if (Level.IsPoetAlive(PoetID::KenjiID))     // 켄지가 살아 있으면
                {
                    printf("미야자와 켄지: 소박한 강인함으로 세상을 품는다.\n");
                    Level.KenjiChapter(&player);
                }
                else
                {
                    printf("여긴 이미 고요하다... (켄지를 쓰러트렸다)\n");
                }
            }
                break;

            case LocationID::Azalean:
            {
                if (Level.IsPoetAlive(PoetID::KimSowolID))      // 김소월이 살아 있으면
                {
                    printf("김소월: 꽃잎으로 남은 이별의 혼, 너의 상대는 혼의 정수다.\n");
                    Level.KimSowolChapter(&player);
                }
                else
                {
                    printf("이미 정적만 흐른다... (김소월을 쓰러트렸다)\n");
                }
            }
                break;

            case LocationID::AvonSanctum:
            {
                printf("성스러운 제단 앞...\n");
                Level.BoseChapter(&player);
            }
                break;

            case LocationID::None:
            default:
                printf("여기서는 아무도 발견되지 않았다...\n");
                break;
            }
        }
        break;
        case 4:
        {
            // enum class에 넣은 시집들을 보여줌
            player.ShowInventory();
            printf("\n 이름 : ");
            player.GetName();
            printf("\n 보유 잉크량 : ");
            player.GetInk();
            printf("\n 공격력 : ");
            player.GetPlayerAttackPower();
            printf("\n 체력 : ");
            player.GetPlayerHealth();
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

void GameManager::BattleMenu()
{

    /*
    ① player.RecitePoemAttack();    기본공격 (이 함수 안에 Attack 함수 처리함)
    ② player.UnleashPoemSkill();    스킬공격 (시인을 이기고 얻은 시집들을 스킬로 쓸 수 있음 (약간 메가멘 느낌?)
    */


}
