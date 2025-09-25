#include "KimSowol.h"

void KimSowol::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower
    int PoemAttackPower = AttackPower;

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("%s: ������ ��� ���Ŷ�!\n", Name.c_str());
        //PoemAttackPower��ŭ ������
        InTarget->TakeDamage(AttackPower);
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("%s: �̺��� �ɺ� �ʸ� ���´�!\n", Name.c_str());
        //PoemAttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
        PoemAttackPower = AttackPower * 2;
        InTarget->TakeDamage(PoemAttackPower);
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("%s: ���� ���ذ��ٴ�...\n", Name.c_str());
        //PoemAttackPower�� �� ��
    }
}

void KimSowol::TakeDamage(int InDamage)
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
        printf("%s: �������� ���� ������ ����...\n", Name.c_str());
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    break;
    case 2:
    {
        printf("%s: ���޷��� ������ �ٽ� �ɴ�.\n", Name.c_str());
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    break;
    case 3:
    {
        printf("%s: �� �ô� �� �������� ǰ�´�.\n", Name.c_str());
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
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
