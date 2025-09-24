#include "Charles.h"
#include <iostream>
#include <cstdio>

void Charles::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // 기본 공격 (맞을 확률 70%)
    {
        printf("향기와 부패가 뒤섞인 꽃의 가시를 받아라!\n");
        //PoemAttackPower만큼 공격함
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // 치명타 공격 (맞을 확률 20%)
    {
        printf("타락의 장미가 네 영혼을 찔렀다!\n");
        //PoemAttackPower의 약 2배 만큼 공격함 (고유 스킬을 쓰고 치명타가 터지면 4배)
    }
    else        // 빗나갈 확률 (10%)  
    {
        printf("허공 속에서도 악취는 스며들지....\n");
        //PoemAttackPower가 안 들어감
    }

}

void Charles::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // 공격 맞았을 시 나올 대사 3개 중의 하나
    {   
    case 1:
    {
        printf("고통조차도 시가 된다...\n");
    }
        break;
    case 2:
    {
        printf("악의 꽃은 시들지 않아.\n");
    }
        break;
    case 3:
    {
        printf("나약한 시 구절이다!\n");
    }
        break;
    default:
        //ERROR!!
        break;
    }
    // 샤를 체력 - 플레이어 공격력

}

void Charles::CharlesPoemSkill()
{
    // 최대 체력이 약30% 미만일 때 발동

    if (PoetHealth <= 30)
    {
        printf("|| 오 괴로워라! 오 괴로워라! 시간이 '삶'을 갉아 먹어버리고 ||\n");    // 실제 시집 <악의 꽃>에 나오는 [적]이라는 시의 한 구절이다.
        // 기본 PoemAttackPower가 2배가 되어 다시 공격한다.
    }

}

inline bool Charles::IsAliveCharles()
{


    return false;
}

void Charles::CharlesDefeat()
{
}
