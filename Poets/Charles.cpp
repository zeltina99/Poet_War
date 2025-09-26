#include "Charles.h"
#include <iostream>
#include <cstdio>

int Index = 1;

void Charles::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower
    int PoemAttackPower = AttackPower;

    CharlesPoemSkill();

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("%s: ���� ���а� �ڼ��� ���� ���ø� �޾ƶ�!\n", Name.c_str());
        InTarget->TakeDamage(AttackPower);
        //AttackPower��ŭ ������
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("%s: Ÿ���� ��̰� �� ��ȥ�� �񷶴�!\n", Name.c_str());
        PoemAttackPower = AttackPower * 2;
        InTarget->TakeDamage(PoemAttackPower);
        //AttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("%s: ��� �ӿ����� ����� �������....\n", Name.c_str());
        InTarget->TakeDamage(0);
        //AttackPower�� �� ��
    }

}

void Charles::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    Health -= InDamage;
    if (Health < 0)
    {
        Health = 0;
    }
    switch (TakeEventNumber)    // ���� �¾��� �� ���� ��� 3�� ���� �ϳ�
    {   
    case 1:
    {
        printf("%s: ���������� �ð� �ȴ�...\n", Name.c_str());
    }
        break;
    case 2:
    {
        printf("%s: ���� ���� �õ��� �ʾ�.\n", Name.c_str());
    }
        break;
    case 3:
    {
        printf("%s: ������ �� �����̴�!\n", Name.c_str());
    }
        break;
    default:
        //ERROR!!
        break;
    }
    printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    printf("\n");

}

void Charles::CharlesPoemSkill()
{
    // �ִ� ü���� ��30% �̸��� �� �ѹ��� �ߵ�

    if ((Health <= 30) && (Index == 1))
    {
        printf("[���� ��]\n\n");
        printf("|| �� ���ο���! �� ���ο���! �ð��� '��'�� ���� �Ծ������ ||\n\n");    // ���� ���� <���� ��>�� ������ [��]�̶�� ���� �� �����̴�.
        // �⺻ AttackPower�� 2�谡 �Ǿ� �ٽ� �����Ѵ�.
        AttackPower = AttackPower * 2;
        Index = 0;
    }

}

