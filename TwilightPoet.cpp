#include "TwilightPoet.h"

void TwilightPoet::Attack(ICanBattle* InTarget)
{
    if (AttackPower<20)
    {
        printf("%s: ���� �ø� �����ٿ�!\n", Name.c_str());
        InTarget->TakeDamage(AttackPower);
    }
    else
    {
        int AttackEventNumber = (rand() % 3) + 1;

        switch (AttackEventNumber)
        {
        case 1: // �⺻ ����
        {
            printf("%s: �ð��� ���� �տ��� �ʴ� �����ϴ�!\n", Name.c_str());
            InTarget->TakeDamage(AttackPower);
        }
        break;
        case 2: // Time��s Scythe (�ð��� ��) : �÷��̾��� �ִ� ü���� 20% ���� ����
        {
            AttackSkill1(dynamic_cast<Player*>(InTarget));
        }
        break;
        case 3: // Crown of Death (������ �հ�) : �÷��̾��� ���� ü���� 40% ����
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
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    else
    {
        if(Health > 250)
        {
            switch (TakeEventNumber)    // ���� �¾��� �� ���� ��� 3�� ���� �ϳ�
            {
            case 1:
            {
                printf("%s: ��ó�� �θ��⿣ ����ϱ�, ��ġ ���� �ñ�ó��.\n", Name.c_str());
            }
            break;
            case 2:
            {
                printf("%s: �� �� ��� ����� ��, ����� ������ ���� ���̴�.\n", Name.c_str());
            }
            break;
            case 3:
            {
                printf("%s: �� ������ ���δ� ������ �Ѿ�� ���ϸ���.\n", Name.c_str());
            }
            break;
            default:
                //ERROR!!
                break;
            }
        }
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    printf("\n");
}

void TwilightPoet::AttackSkill1(Player* InPlayer)
{
    // Time��s Scythe (�ð��� ��) : �÷��̾��� �ִ� ü���� 20% ���� ����
    int Damage = (InPlayer->GetPlayerMaxHealth() / 10) * 2;
    printf("%s: Time��s Scythe\n", Name.c_str());
    InPlayer->TakeDamage(Damage);
}

void TwilightPoet::AttackSkill2(Player* InPlayer)
{
    // Crown of Death (������ �հ�) : �÷��̾��� ���� ü���� 40% ����
    int Damage = (InPlayer->GetPlayerHealth() / 10) * 4;
    printf("%s: Crown of Death\n", Name.c_str());
    InPlayer->TakeDamage(Damage);
}
