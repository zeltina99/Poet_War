#include "Charles.h"
#include <iostream>
#include <cstdio>

void Charles::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("���� ���а� �ڼ��� ���� ���ø� �޾ƶ�!\n");
        //PoemAttackPower��ŭ ������
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("Ÿ���� ��̰� �� ��ȥ�� �񷶴�!\n");
        //PoemAttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("��� �ӿ����� ����� �������....\n");
        //PoemAttackPower�� �� ��
    }

}

void Charles::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // ���� �¾��� �� ���� ��� 3�� ���� �ϳ�
    {   
    case 1:
    {
        printf("���������� �ð� �ȴ�...\n");
    }
        break;
    case 2:
    {
        printf("���� ���� �õ��� �ʾ�.\n");
    }
        break;
    case 3:
    {
        printf("������ �� �����̴�!\n");
    }
        break;
    default:
        //ERROR!!
        break;
    }
    // ���� ü�� - �÷��̾� ���ݷ�

}

void Charles::CharlesPoemSkill()
{
    // �ִ� ü���� ��30% �̸��� �� �ߵ�

    if (PoetHealth <= 30)
    {
        printf("|| �� ���ο���! �� ���ο���! �ð��� '��'�� ���� �Ծ������ ||\n");    // ���� ���� <���� ��>�� ������ [��]�̶�� ���� �� �����̴�.
        // �⺻ PoemAttackPower�� 2�谡 �Ǿ� �ٽ� �����Ѵ�.
    }

}

inline bool Charles::IsAliveCharles()
{


    return false;
}

void Charles::CharlesDefeat()
{
}
