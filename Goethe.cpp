#include "Goethe.h"

void Goethe::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("������ �뷡�� ����!\n");
        //PoemAttackPower��ŭ ������
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("��������� ���̾�, ����, ���� �Բ� ����!\n");
        //PoemAttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("���̾�, �̳��� ���Ŷ�...\n");
        //PoemAttackPower�� �� ��
    }
}

void Goethe::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // ���� �¾��� �� ���� ��� 3�� ���� �ϳ�
    {
    case 1:
    {
        printf("...�� ���븶�� �뷡�ϸ���.\n");
    }
    break;
    case 2:
    {
        printf("���� ���� �뷡�� �������� �ʾҴ�!\n");
    }
    break;
    case 3:
    {
        printf("���� ���Ͼ߿��� ���� ����...\n");
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

void Goethe::GoetheDefeat()
{
}
