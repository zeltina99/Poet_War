#include "Kenji.h"

void Kenji::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("������ ���� ���� ������ ���� �� �����Դϴ�.\n");
        //PoemAttackPower��ŭ ������
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("��� �ٶ�ó�� ����ģ��!\n");
        //PoemAttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("...������ ����������.\n");
        //PoemAttackPower�� �� ��
    }
}

void Kenji::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // ���� �¾��� �� ���� ��� 3�� ���� �ϳ�
    {
    case 1:
    {
        printf("���� �ÿ��� ���� �ʴ´�...\n");
    }
    break;
    case 2:
    {
        printf("��� ��Ǯ�� �� �����Ѵ�.\n");
    }
    break;
    case 3:
    {
        printf("������ ��� ������ �긮�� ��.\n");
    }
    break;
    default:
        //ERROR!!
        break;
    }
    // �̾��ڿ� ���� ü�� - �÷��̾� ���ݷ�
}

void Kenji::KenjiPoemSkill()
{
    // ��� �нú�� �÷��̾��� ������ -5 ��ŭ ��Ƽ� ������ ����
    // PoetHealth = PoetHealth - (PlayerAttackPower - 5)
    printf("|| �񿡵� ���� �ʰ� �ٶ����� ���� ������, ������ ������ �������� ���� �ʰ�. ||\n");   // �̾��ڿ� ������ �񿡵� ���� �ʰ��� �� �����̴�.

}

inline bool Kenji::IsAliveKenji()
{
    return false;
}

void Kenji::KenjiDefeat()
{
}
