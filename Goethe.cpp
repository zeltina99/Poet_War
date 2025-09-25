#include "Goethe.h"

void Goethe::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // 기본 공격 (맞을 확률 70%)
    {
        printf("마왕의 노래를 들어라!\n");
        //PoemAttackPower만큼 공격함
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // 치명타 공격 (맞을 확률 20%)
    {
        printf("사랑스러운 아이야, 오라, 나와 함께 가자!\n");
        //PoemAttackPower의 약 2배 만큼 공격함 (고유 스킬을 쓰고 치명타가 터지면 4배)
    }
    else        // 빗나갈 확률 (10%)  
    {
        printf("아이야, 겁내지 말거라...\n");
        //PoemAttackPower가 안 들어감
    }
}

void Goethe::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // 공격 맞았을 시 나올 대사 3개 중의 하나
    {
    case 1:
    {
        printf("...이 고통마저 노래하리라.\n");
    }
    break;
    case 2:
    {
        printf("아직 나의 노래는 시작하지 않았다!\n");
    }
    break;
    case 3:
    {
        printf("이제 백일야에서 끝을 보자...\n");
    }
    break;
    default:
        //ERROR!!
        break;
    }
    // 괴테 체력 - 플레이어 공격력
}

void Goethe::GoethePoemSkill()
{
    //최대 체력이 50% 미만일 때 발동
    //int 변수 = 괴테의 최대 체력 / 2
    //if (PoetHealth <= 변수)
    //

    if (Health <= 50)
    {
        printf("|| 누가 말을 타고 가는가, 거센 바람 부는 이 늦은 밤에? ||\n");   // 괴테의 마왕의 첫 구절이다.
        //현재 상대 체력에 50% 만큼의 공격을 함
    }
}

void Goethe::GoetheDefeat()
{
}
