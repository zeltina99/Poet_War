#include "Dante.h"

void Dante::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // 기본 공격 (맞을 확률 70%)
    {
        printf("지옥의 불길을 거쳐라!\n");
        //PoemAttackPower만큼 공격함
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // 치명타 공격 (맞을 확률 20%)
    {
        printf("천국의 빛이 너를 태워 없앤다!\n");
        //PoemAttackPower의 약 2배 만큼 공격함 (고유 스킬을 쓰고 치명타가 터지면 4배)
    }
    else        // 빗나갈 확률 (10%)  
    {
        printf("너는 아직 연옥의 길목에 있구나....\n");
        //PoemAttackPower가 안 들어감
    }
}

void Dante::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // 공격 맞았을 시 나올 대사 3개 중의 하나
    {
    case 1:
    {
        printf("고통은 나의 서사일 뿐.\n");
    }
    break;
    case 2:
    {
        printf("베아트리체여...\n");
    }
    break;
    case 3:
    {
        printf("신곡의 길은 멈추지 않는다.\n");
    }
    break;
    default:
        //ERROR!!
        break;
    }
    // 단테 체력 - 플레이어 공격력
}

void Dante::DantePoemSkill()
{
    //최대 체력이 20% 미만일 때 발동
    
    if (Health <= 20)
    {
        printf("|| Lasciate ogne speranza, voi ch’intrate ||\n");   // 단테의 신곡 [지옥]편에 나오는 구절
        //한번 플레이어의 공격을 무시한다. -> if 해서 변수 하나 더 만들고 0 데미지 넣으면 됨
    }

}

void Dante::DanteDefeat()
{
}
