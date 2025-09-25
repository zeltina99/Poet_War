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
        printf("%s: ���� �ÿ��� ���� �ʴ´�...\n", Name.c_str());
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    break;
    case 2:
    {
        printf("%s: ��� ��Ǯ�� �� �����Ѵ�.\n", Name.c_str());
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    break;
    case 3:
    {
        printf("%s: ������ ��� ������ �긮�� ��.\n", Name.c_str());
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
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


void Kenji::KenjiDefeat()
{
}
