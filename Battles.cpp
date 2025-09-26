#include "Battles.h"
#include <iostream>
#include "Map.h"
#include "GameManager.h"


void Battles::CharlesBattle(Player* InPlayer, Charles* InPoet)
{
    int InputNumber = 0;

    while (InPlayer->IsAlivePlayer() && InPoet->IsAliveCharles())
    {
        printf("\n--- 전투 메뉴 ---\n");
        printf("[공격력 : %d]\t[체력 : %d/%d]\n", InPlayer->GetPlayerAttackPower(), InPlayer->GetPlayerHealth(), InPlayer->GetPlayerMaxHealth());
        printf("① 시를 읽는다\n");
        printf("> 선택: ");
        std::cin >> InputNumber;
        if (InputNumber == 1)
        {
            // 플레이어 턴
            InPlayer->Attack(InPoet);
            if (!InPoet->IsAliveCharles())
            {
                break;
            }

            // 샤를 턴
            InPoet->Attack(InPlayer);
            if (!InPlayer->IsAlivePlayer())
            {
                break;
            }
        }
        else
        {
            printf("\n잘못된 입력이야! 다시 입력해줘\n");
        }
    }
    if (InPlayer->IsAlivePlayer())
    {
        InPlayer->TakeInk(200);
        printf("샤를 보들레르를 쓰러트리고 시집 [악의 꽃]을 얻었다!\n\n");
        InPlayer->AddPoem(Poem::CharlesPoem);
        printf("윤동주: 이제 다음 마을로 가자.\n");
    }
}

void Battles::ConanBattle(Player* InPlayer, Conan* InPoet)
{
    GameManager gm;
    gm.BattleMenu(InPlayer, InPoet);

    if (InPoet->GetPoetHealth() <= 0)
    {
        InPlayer->TakeInk(250);   // 코난 전투 보상
        InPlayer->AddPoem(Poem::ConanPoem);
        printf("아서 코난도일을 쓰러트리고 시집 [활의 노래]를 얻었다!\n\n");
        printf("윤동주: 이제 다음 마을로 가자.\n");
    }
}

void Battles::DanteBattle(Player* InPlayer, Dante* InPoet)
{
    GameManager gm;
    gm.BattleMenu(InPlayer, InPoet);

    if (InPoet->GetPoetHealth() <= 0)
    {
        InPlayer->TakeInk(300);   // 단테 전투 보상
        InPlayer->AddPoem(Poem::DantePoem);
        printf("단테를 쓰러트리고 시집 [신곡]을 얻었다!\n\n");
        printf("윤동주: 이제 다음 마을로 가자.\n");
    }
}

void Battles::GoetheBattle(Player* InPlayer, Goethe* InPoet)
{
    GameManager gm;
    gm.BattleMenu(InPlayer, InPoet);

    if (InPoet->GetPoetHealth() <= 0)
    {
        InPlayer->TakeInk(250);   // 괴테 전투 보상
        InPlayer->AddPoem(Poem::GoethePoem);
        printf("괴테를 쓰러트리고 시집 [마왕]을 얻었다!\n\n");
        printf("윤동주: 이제 다음 마을로 가자.\n");
    }
}

void Battles::KenjiBattle(Player* InPlayer, Kenji* InPoet)
{
    GameManager gm;
    gm.BattleMenu(InPlayer, InPoet);

    if (InPoet->GetPoetHealth() <= 0)
    {
        InPlayer->TakeInk(250);   // 켄지 전투 보상
        InPlayer->AddPoem(Poem::KenjiPoem);
        printf("미야자와 켄지를 쓰러트리고 시집 [비에도 지지 않고]를 얻었다!\n\n");
        printf("윤동주: 이제 다음 마을로 가자.\n");
    }
}

void Battles::KimSowolBattle(Player* InPlayer, KimSowol* InPoet)
{
    GameManager gm;
    gm.BattleMenu(InPlayer, InPoet);

    if (InPoet->GetPoetHealth() <= 0)
    {
        InPlayer->TakeInk(250);   // 김소월 전투 보상
        InPlayer->AddPoem(Poem::KimSowolPoem);
        printf("김소월을 쓰러트리고 시집 [진달래꽃]을 얻었다!\n\n");
        printf("윤동주: 이제 다음 마을로 가자.\n");
    }
}