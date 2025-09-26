#include "TwilightPoet.h"

void TwilightPoet::Attack(ICanBattle* InTarget)
{
    if (AttackPower<20)
    {
        printf("%s: 너의 시를 보여다오!\n", Name.c_str());
        InTarget->TakeDamage(AttackPower);
    }
    else
    {
        int AttackEventNumber = (rand() % 3) + 1;

        switch (AttackEventNumber)
        {
        case 1: // 기본 공격
        {
            printf("%s: 시간과 죽음 앞에서 너는 무력하다!\n", Name.c_str());
            InTarget->TakeDamage(AttackPower);
        }
        break;
        case 2: // Time’s Scythe (시간의 낫) : 플레이어의 최대 체력의 20% 고정 피해
        {
            AttackSkill1(dynamic_cast<Player*>(InTarget));
        }
        break;
        case 3: // Crown of Death (죽음의 왕관) : 플레이어의 현재 체력의 40% 피해
        {
            AttackSkill2(dynamic_cast<Player*>(InTarget));
        }
        break;
        default:
        {
            printf("ERROR!!!");
        }
        break;
        }

       
    }
    
}

void TwilightPoet::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    Health -= InDamage;
    if (Health < 0)
    {
        Health = 0;
    }
    if (AttackPower < 20)
    {
        printf("%s는 %d의 피해를 입었다! ([%s]의 현재 체력: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    else
    {
        if(Health > 250)
        {
            switch (TakeEventNumber)    // 공격 맞았을 시 나올 대사 3개 중의 하나
            {
            case 1:
            {
                printf("%s: 상처라 부르기엔 희미하군, 마치 낡은 시구처럼.\n", Name.c_str());
            }
            break;
            case 2:
            {
                printf("%s: 피 한 방울 흘렸을 뿐, 무대는 여전히 나의 것이다.\n", Name.c_str());
            }
            break;
            case 3:
            {
                printf("%s: 그 정도의 언어로는 영원을 넘어서지 못하리라.\n", Name.c_str());
            }
            break;
            default:
                //ERROR!!
                break;
            }
        }
        printf("%s는 %d의 피해를 입었다! ([%s]의 현재 체력: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    printf("\n");
}

void TwilightPoet::AttackSkill1(Player* InPlayer)
{
    // Time’s Scythe (시간의 낫) : 플레이어의 최대 체력의 20% 고정 피해
    int Damage = (InPlayer->GetPlayerMaxHealth() / 10) * 2;
    printf("%s: Time’s Scythe\n", Name.c_str());
    InPlayer->TakeDamage(Damage);
}

void TwilightPoet::AttackSkill2(Player* InPlayer)
{
    // Crown of Death (죽음의 왕관) : 플레이어의 현재 체력의 40% 피해
    int Damage = (InPlayer->GetPlayerHealth() / 10) * 4;
    printf("%s: Crown of Death\n", Name.c_str());
    InPlayer->TakeDamage(Damage);
}
