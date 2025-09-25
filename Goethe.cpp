#include "Goethe.h"

void Goethe::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower
    int PoemAttackPower = AttackPower;

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("%s: ������ �뷡�� ����!\n", Name.c_str());
        //PoemAttackPower��ŭ ������
        InTarget->TakeDamage(AttackPower);
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("%s: ��������� ���̾�, ����, ���� �Բ� ����!\n", Name.c_str());
        //PoemAttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
        PoemAttackPower = AttackPower * 2;
        InTarget->TakeDamage(PoemAttackPower);
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("%s: ���̾�, �̳��� ���Ŷ�...\n", Name.c_str());
        //PoemAttackPower�� �� ��
    }
}

void Goethe::TakeDamage(int InDamage)
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
        printf("%s: ...�� ���븶�� �뷡�ϸ���.\n", Name.c_str());
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    break;
    case 2:
    {
        printf("%s: ���� ���� �뷡�� �������� �ʾҴ�!\n", Name.c_str());
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    break;
    case 3:
    {
        printf("%s: ���� ���Ͼ߿��� ���� ����...\n", Name.c_str());
        printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    }
    break;
    default:
        //ERROR!!
        break;
    }
    // ���� ü�� - �÷��̾� ���ݷ�
}

void Goethe::GoethePoemSkill()
{
    //�ִ� ü���� 50% �̸��� �� �ߵ�
    //int ���� = ������ �ִ� ü�� / 2
    //if (PoetHealth <= ����)
    //

    if (Health <= 50)
    {
        printf("|| ���� ���� Ÿ�� ���°�, �ż� �ٶ� �δ� �� ���� �㿡? ||\n");   // ������ ������ ù �����̴�.
        //���� ��� ü�¿� 50% ��ŭ�� ������ ��
    }
}

