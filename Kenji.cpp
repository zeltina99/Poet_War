#include "Kenji.h"

void Kenji::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower
    int PoemAttackPower = AttackPower;

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("%s: ������ ���� ���� ������ ���� �� �����Դϴ�.\n", Name.c_str());
        //PoemAttackPower��ŭ ������
        InTarget->TakeDamage(AttackPower);
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("%s: ��� �ٶ�ó�� ����ģ��!\n", Name.c_str());
        //PoemAttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
        PoemAttackPower = AttackPower * 2;
        InTarget->TakeDamage(PoemAttackPower);
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("%s: ...������ ����������.\n", Name.c_str());
        //PoemAttackPower�� �� ��
    }
}

void Kenji::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    if (Passive)
    {
        KenjiPoemSkill();
        Passive = false;
    }
    //PlayerAttackPower
    Health = (Health + 10) - InDamage;
    if (Health < 0)
    {
        Health = 0;
    }
    switch (TakeEventNumber)    // ���� �¾��� �� ���� ��� 3�� ���� �ϳ�
    {
    case 1:
    {
        printf("%s: ���� �ÿ��� ���� �ʴ´�...\n", Name.c_str());
    }
    break;
    case 2:
    {
        printf("%s: ��� ��Ǯ�� �� �����Ѵ�.\n", Name.c_str());
    }
    break;
    case 3:
    {
        printf("%s: ������ ��� ������ �긮�� ��.\n", Name.c_str());
    }
    break;
    default:
        //ERROR!!
        break;
    }
    printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    printf("\n");
}

void Kenji::KenjiPoemSkill()
{
    // ��� �нú�� �÷��̾��� ������ -10 ��ŭ ��Ƽ� ������ ����
    printf("\n|| �񿡵� ���� �ʰ� �ٶ����� ���� ������, ������ ������ �������� ���� �ʰ�. ||\n");   // �̾��ڿ� ������ �񿡵� ���� �ʰ��� �� �����̴�.
    printf("\n%s: ���� ������ ������ 10�� �𿩼� ���ðŴ�.\n", Name.c_str());
}

