#include "TwilightPoet.h"

void TwilightPoet::Attack(ICanBattle* InTarget)
{
    if (!IsTransformed)
    {
        printf("%s: '너의 시를 보여다오!'\n", Name.c_str());
    }
    else
    {
        printf("%s: '시간과 죽음 앞에서 너는 무력하다!'\n", Name.c_str());
    }
    InTarget->TakeDamage(AttackPower);
}

void TwilightPoet::TakeDamage(int InDamage)
{
    Health -= InDamage;
    if (Health < 0) Health = 0;

    printf("%s는 %d의 피해를 입었다! (남은 체력: %d)\n", Name.c_str(), InDamage, Health);
}

void TwilightPoet::TransformToShakespeare()
{
    printf("윤동주의 모습이 뒤틀리며, 셰익스피어가 나타났다!\n");
    Name = "William Shakespeare";
    Health = 300;      // 강화된 체력
    AttackPower = 25;  // 강화된 공격력
    IsTransformed = true;
}