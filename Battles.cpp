#include "Battles.h"
#include <iostream>
#include "Map.h"
#include "GameManager.h"


void Battles::CharlesBattle(Player* InPlayer, Charles* InPoet)
{
    int InputNumber = 0;

    while (InPlayer->IsAlivePlayer() && InPoet->IsAliveCharles())
    {
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
        InPlayer->TakeInk(300);   // 단테 전투 보상
        InPlayer->AddPoem(Poem::DantePoem);
        printf("단테를 쓰러트리고 시집 [신곡]을 얻었다!\n\n");
        printf("윤동주: 이제 다음 마을로 가자.\n");
    }
}

void Battles::DanteBattle(Player* InPlayer, Dante* InPoet)
{
}

void Battles::GoetheBattle(Player* InPlayer, Goethe* InPoet)
{
}

void Battles::KenjiBattle(Player* InPlayer, Kenji* InPoet)
{
}

void Battles::KimSowolBattle(Player* InPlayer, KimSowol* InPoet)
{
}