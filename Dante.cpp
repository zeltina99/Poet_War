#include "Dante.h"

void Dante::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("������ �ұ��� ���Ķ�!\n");
        //PoemAttackPower��ŭ ������
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("õ���� ���� �ʸ� �¿� ���ش�!\n");
        //PoemAttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("�ʴ� ���� ������ ��� �ֱ���....\n");
        //PoemAttackPower�� �� ��
    }
}

void Dante::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // ���� �¾��� �� ���� ��� 3�� ���� �ϳ�
    {
    case 1:
    {
        printf("������ ���� ������ ��.\n");
    }
    break;
    case 2:
    {
        printf("����Ʈ��ü��...\n");
    }
    break;
    case 3:
    {
        printf("�Ű��� ���� ������ �ʴ´�.\n");
    }
    break;
    default:
        //ERROR!!
        break;
    }
    // ���� ü�� - �÷��̾� ���ݷ�
}

void Dante::DantePoemSkill()
{
    //�ִ� ü���� 20% �̸��� �� �ߵ�
    
    if (Health <= 20)
    {
        printf("|| Lasciate ogne speranza, voi ch��intrate ||\n");   // ������ �Ű� [����]�� ������ ����
        //�ѹ� �÷��̾��� ������ �����Ѵ�. -> if �ؼ� ���� �ϳ� �� ����� 0 ������ ������ ��
    }

}

void Dante::DanteDefeat()
{
}
