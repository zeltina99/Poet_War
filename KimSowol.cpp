#include "KimSowol.h"

void KimSowol::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("������ ��� ���Ŷ�!\n");
        //PoemAttackPower��ŭ ������
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("�̺��� �ɺ� �ʸ� ���´�!\n");
        //PoemAttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("���� ���ذ��ٴ�...\n");
        //PoemAttackPower�� �� ��
    }
}

void KimSowol::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // ���� �¾��� �� ���� ��� 3�� ���� �ϳ�
    {
    case 1:
    {
        printf("�������� ���� ������ ����...\n");
    }
    break;
    case 2:
    {
        printf("���޷��� ������ �ٽ� �ɴ�.\n");
    }
    break;
    case 3:
    {
        printf("�� �ô� �� �������� ǰ�´�.\n");
    }
    break;
    default:
        //ERROR!!
        break;
    }
    // ��ҿ� ü�� - �÷��̾� ���ݷ�
}

void KimSowol::KimSowolPoemSkill()
{
    //���� ü���� 20 �̸��� �� �ߵ�

    if (Health <= 20)
    {
        printf("|| �� ���Ⱑ ���ܿ� ���� ������ ������ ���� ���� �帮�츮��. ||\n");   // ��ҿ��� ���޷� �ɿ� ������ �����̴�.
        //��ҿ��� ���� ü�¿� +100�� �Ѵ�.
    }
}


void KimSowol::KimSowolDefeat()
{
}
