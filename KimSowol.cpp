#include "KimSowol.h"

void KimSowol::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // 기본 공격 (맞을 확률 70%)
    {
        printf("꽃잎을 밟고 가거라!\n");
        //PoemAttackPower만큼 공격함
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // 치명타 공격 (맞을 확률 20%)
    {
        printf("이별의 꽃비가 너를 덮는다!\n");
        //PoemAttackPower의 약 2배 만큼 공격함 (고유 스킬을 쓰고 치명타가 터지면 4배)
    }
    else        // 빗나갈 확률 (10%)  
    {
        printf("꽃을 피해가다니...\n");
        //PoemAttackPower가 안 들어감
    }
}

void KimSowol::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // 공격 맞았을 시 나올 대사 3개 중의 하나
    {
    case 1:
    {
        printf("떠나가는 이의 슬픔은 깊구나...\n");
    }
    break;
    case 2:
    {
        printf("진달래는 꺾여도 다시 핀다.\n");
    }
    break;
    case 3:
    {
        printf("내 시는 이 고통조차 품는다.\n");
    }
    break;
    default:
        //ERROR!!
        break;
    }
    // 김소월 체력 - 플레이어 공격력
}

void KimSowol::KimSowolPoemSkill()
{
    //현재 체력이 20 미만일 때 발동

    if (Health <= 20)
    {
        printf("|| 나 보기가 역겨워 가실 때에는 말없이 고이 보내 드리우리다. ||\n");   // 김소월의 진달래 꽃에 나오는 구절이다.
        //김소월의 현재 체력에 +100을 한다.
    }
}


void KimSowol::KimSowolDefeat()
{
}
