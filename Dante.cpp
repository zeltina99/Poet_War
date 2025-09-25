#include "Dante.h"

void Dante::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower
    int PoemAttackPower = AttackPower;

    if (AttackEventNumber < 7)    // 기본 공격 (맞을 확률 70%)
    {
        printf("%s: 지옥의 불길을 거쳐라!\n", Name.c_str());
        //PoemAttackPower만큼 공격함
        InTarget->TakeDamage(AttackPower);
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // 치명타 공격 (맞을 확률 20%)
    {
        printf("%s: 천국의 빛이 너를 태워 없앤다!\n", Name.c_str());
        //AttackPower의 약 2배 만큼 공격함 
        PoemAttackPower = AttackPower * 2;
        InTarget->TakeDamage(PoemAttackPower);
    }
    else        // 빗나갈 확률 (10%)  
    {
        printf("%s: 너는 아직 연옥의 길목에 있구나....\n", Name.c_str());
        //AttackPower가 안 들어감
    }
}

void Dante::TakeDamage(int InDamage)
{
    if (IgnoreNextDamage)
    {
        printf("%s는 지옥의 힘으로 이번 피해를 무시했다!\n", Name.c_str());
        IgnoreNextDamage = false;  // 한 번만 무시하므로 다시 false
        return;
    }

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
        printf("%s: 고통은 나의 서사일 뿐.\n", Name.c_str());
    }
    break;
    case 2:
    {
        printf("%s: 베아트리체여...\n", Name.c_str());
    }
    break;
    case 3:
    {
        printf("%s: 신곡의 길은 멈추지 않는다.\n", Name.c_str());
    }
    break;
    default:
        //ERROR!!
        break;
    }
    printf("\n");
    // 단테 체력 - 플레이어 공격력
}

void Dante::DantePoemSkill()
{
    if (Health <= 26)   //최대 체력이 20% 이하일 때 발동
    {
        printf("|| Lasciate ogne speranza, voi ch’intrate ||\n");   // 단테의 신곡 [지옥]편에 나오는 구절
        printf("%s는 잠시 지옥의 문에 서서, 다음 피해를 무시한다!\n\n", Name.c_str());

        IgnoreNextDamage = true; // 다음 데미지를 무시하게 플래그 설정
    }

}

