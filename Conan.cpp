#include "Conan.h"

void Conan::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // 기본 공격 (맞을 확률 70%)
    {
        printf("이 화살은 노래하듯 날아간다!\n");
        //PoemAttackPower만큼 공격함
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // 치명타 공격 (맞을 확률 20%)
    {
        printf("바스커빌 가의 사냥개여!\n");
        //PoemAttackPower의 약 2배 만큼 공격함 (고유 스킬을 쓰고 치명타가 터지면 4배)
    }
    else        // 빗나갈 확률 (10%)  
    {
        printf("명탐정이라도 예측 못 한 순간인가...\n");
        //PoemAttackPower가 안 들어감
    }
}

void Conan::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // 공격 맞았을 시 나올 대사 3개 중의 하나
    {
    case 1:
    {
        printf("하! 증거는 고통 속에 남지.\n");
    }
    break;
    case 2:
    {
        printf("영국의 안개보다 가볍군.\n");
    }
    break;
    case 3:
    {
        printf("너의 시는 흉기가 되지 못해.\n");
    }
    break;
    default:
        //ERROR!!
        break;
    }
    // 아서 코난도일 체력 - 플레이어 공격력
}

void Conan::ConanPoemSkill()
{
    int SkillEventNumber = rand() % 5;

    if (SkillEventNumber == 4)  // 전투 할 때 마다 20% 확률로 공격을 두번 한다.
    {
        printf("|| It is there that our mark will be. ||\n");   // 아서 코난도일의 활의 노래의 시 구절
    }

}

inline bool Conan::IsAliveConan()
{
    return false;
}

void Conan::ConanDefeat()
{
}
