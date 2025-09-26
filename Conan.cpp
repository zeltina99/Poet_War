#include "Conan.h"

void Conan::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower
    int PoemAttackPower = AttackPower;
    int SkillEventNumber = rand() % 5;

    bool DoubleAttak = false;

    if (SkillEventNumber == 4)  // 전투 할 때 마다 20% 확률로 공격을 두번 한다.
    {
        printf("|| It is there that our mark will be. ||\n");   // 아서 코난도일의 활의 노래의 시 구절
        DoubleAttak = true;
    }


    if (AttackEventNumber < 7)    // 기본 공격 (맞을 확률 70%)
    {
        printf("%s: 이 화살은 노래하듯 날아간다!\n", Name.c_str());
        //PoemAttackPower만큼 공격함
        InTarget->TakeDamage(AttackPower);
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // 치명타 공격 (맞을 확률 20%)
    {
        printf("%s: 바스커빌 가의 사냥개여!\n", Name.c_str());
        //PoemAttackPower의 약 2배 만큼 공격함 (고유 스킬을 쓰고 치명타가 터지면 4배)
        PoemAttackPower = AttackPower * 2;
        InTarget->TakeDamage(PoemAttackPower);
    }
    else        // 빗나갈 확률 (10%)  
    {
        printf("%s: 명탐정이라도 예측 못 한 순간인가...\n", Name.c_str());
        //PoemAttackPower가 안 들어감
    }
    if (DoubleAttak)
    {
        InTarget->TakeDamage(AttackPower);
    }

}

void Conan::TakeDamage(int InDamage)
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
        printf("%s: 하! 증거는 고통 속에 남지.\n", Name.c_str());
    }
    break;
    case 2:
    {
        printf("%s: 영국의 안개보다 가볍군.\n", Name.c_str());
    }
    break;
    case 3:
    {
        printf("%s: 너의 시는 흉기가 되지 못해.\n", Name.c_str());
    }
    break;
    default:
        //ERROR!!
        break;
    }
    printf("%s는 %d의 피해를 입었다! ([%s]의 현재 체력: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    printf("\n");
}


