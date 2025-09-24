#include "Kenji.h"

void Kenji::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // 기본 공격 (맞을 확률 70%)
    {
        printf("은하의 역은 이제 은빛의 작은 별 무리입니다.\n");
        //PoemAttackPower만큼 공격함
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // 치명타 공격 (맞을 확률 20%)
    {
        printf("비와 바람처럼 몰아친다!\n");
        //PoemAttackPower의 약 2배 만큼 공격함 (고유 스킬을 쓰고 치명타가 터지면 4배)
    }
    else        // 빗나갈 확률 (10%)  
    {
        printf("...구름이 가려졌구나.\n");
        //PoemAttackPower가 안 들어감
    }
}

void Kenji::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // 공격 맞았을 시 나올 대사 3개 중의 하나
    {
    case 1:
    {
        printf("너의 시에는 지지 않는다...\n");
    }
    break;
    case 2:
    {
        printf("흙과 들풀이 날 지탱한다.\n");
    }
    break;
    case 3:
    {
        printf("가뭄이 들면 눈물을 흘리는 법.\n");
    }
    break;
    default:
        //ERROR!!
        break;
    }
    // 미야자와 켄지 체력 - 플레이어 공격력
}

void Kenji::KenjiPoemSkill()
{
    // 상시 패시브로 플레이어의 공격을 -5 만큼 깎아서 데미지 받음
    // PoetHealth = PoetHealth - (PlayerAttackPower - 5)
    printf("|| 비에도 지지 않고 바람에도 지지 않으며, 눈에도 여름의 더위에도 지지 않고. ||\n");   // 미야자와 켄지의 비에도 지지 않고의 시 구절이다.

}

inline bool Kenji::IsAliveKenji()
{
    return false;
}

void Kenji::KenjiDefeat()
{
}
