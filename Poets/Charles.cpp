#include "Charles.h"
#include <iostream>
#include <cstdio>

int Index = 1;

void Charles::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower
    int PoemAttackPower = AttackPower;

    CharlesPoemSkill();

    if (AttackEventNumber < 7)    // 기본 공격 (맞을 확률 70%)
    {
        printf("%s: 향기와 부패가 뒤섞인 꽃의 가시를 받아라!\n", Name.c_str());
        InTarget->TakeDamage(AttackPower);
        //AttackPower만큼 공격함
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // 치명타 공격 (맞을 확률 20%)
    {
        printf("%s: 타락의 장미가 네 영혼을 찔렀다!\n", Name.c_str());
        PoemAttackPower = AttackPower * 2;
        InTarget->TakeDamage(PoemAttackPower);
        //AttackPower의 약 2배 만큼 공격함 (고유 스킬을 쓰고 치명타가 터지면 4배)
    }
    else        // 빗나갈 확률 (10%)  
    {
        printf("%s: 허공 속에서도 악취는 스며들지....\n", Name.c_str());
        InTarget->TakeDamage(0);
        //AttackPower가 안 들어감
    }

}

void Charles::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    Health -= InDamage;
    if (Health < 0)
    {
        Health = 0;
    }
    switch (TakeEventNumber)    // 공격 맞았을 시 나올 대사 3개 중의 하나
    {   
    case 1:
    {
        printf("%s: 고통조차도 시가 된다...\n", Name.c_str());
    }
        break;
    case 2:
    {
        printf("%s: 악의 꽃은 시들지 않아.\n", Name.c_str());
    }
        break;
    case 3:
    {
        printf("%s: 나약한 시 구절이다!\n", Name.c_str());
    }
        break;
    default:
        //ERROR!!
        break;
    }
    printf("%s는 %d의 피해를 입었다! ([%s]의 현재 체력: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    printf("\n");

}

void Charles::CharlesPoemSkill()
{
    // 최대 체력이 약30% 미만일 때 한번만 발동

    if ((Health <= 30) && (Index == 1))
    {
        printf("[악의 꽃]\n\n");
        printf("|| 오 괴로워라! 오 괴로워라! 시간이 '삶'을 갉아 먹어버리고 ||\n\n");    // 실제 시집 <악의 꽃>에 나오는 [적]이라는 시의 한 구절이다.
        // 기본 AttackPower가 2배가 되어 다시 공격한다.
        AttackPower = AttackPower * 2;
        Index = 0;
    }

}

