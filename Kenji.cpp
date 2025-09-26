#include "Kenji.h"

void Kenji::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower
    int PoemAttackPower = AttackPower;

    if (AttackEventNumber < 7)    // 기본 공격 (맞을 확률 70%)
    {
        printf("%s: 은하의 역은 이제 은빛의 작은 별 무리입니다.\n", Name.c_str());
        //PoemAttackPower만큼 공격함
        InTarget->TakeDamage(AttackPower);
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // 치명타 공격 (맞을 확률 20%)
    {
        printf("%s: 비와 바람처럼 몰아친다!\n", Name.c_str());
        //PoemAttackPower의 약 2배 만큼 공격함 (고유 스킬을 쓰고 치명타가 터지면 4배)
        PoemAttackPower = AttackPower * 2;
        InTarget->TakeDamage(PoemAttackPower);
    }
    else        // 빗나갈 확률 (10%)  
    {
        printf("%s: ...구름이 가려졌구나.\n", Name.c_str());
        //PoemAttackPower가 안 들어감
    }
}

void Kenji::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    if (Passive)
    {
        KenjiPoemSkill();
        Passive = false;
    }
    //PlayerAttackPower
    Health = (Health + 10) - InDamage;
    if (Health < 0)
    {
        Health = 0;
    }
    switch (TakeEventNumber)    // 공격 맞았을 시 나올 대사 3개 중의 하나
    {
    case 1:
    {
        printf("%s: 너의 시에는 지지 않는다...\n", Name.c_str());
    }
    break;
    case 2:
    {
        printf("%s: 흙과 들풀이 날 지탱한다.\n", Name.c_str());
    }
    break;
    case 3:
    {
        printf("%s: 가뭄이 들면 눈물을 흘리는 법.\n", Name.c_str());
    }
    break;
    default:
        //ERROR!!
        break;
    }
    printf("%s는 %d의 피해를 입었다! ([%s]의 현재 체력: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    printf("\n");
}

void Kenji::KenjiPoemSkill()
{
    // 상시 패시브로 플레이어의 공격을 -10 만큼 깎아서 데미지 받음
    printf("\n|| 비에도 지지 않고 바람에도 지지 않으며, 눈에도 여름의 더위에도 지지 않고. ||\n");   // 미야자와 켄지의 비에도 지지 않고의 시 구절이다.
    printf("\n%s: 너의 공격은 나에게 10씩 깎여서 들어올거다.\n", Name.c_str());
}

