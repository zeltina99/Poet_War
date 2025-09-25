#include "Dante.h"

void Dante::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower
    int PoemAttackPower = AttackPower;

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("%s: ������ �ұ��� ���Ķ�!\n", Name.c_str());
        //PoemAttackPower��ŭ ������
        InTarget->TakeDamage(AttackPower);
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("%s: õ���� ���� �ʸ� �¿� ���ش�!\n", Name.c_str());
        //AttackPower�� �� 2�� ��ŭ ������ 
        PoemAttackPower = AttackPower * 2;
        InTarget->TakeDamage(PoemAttackPower);
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("%s: �ʴ� ���� ������ ��� �ֱ���....\n", Name.c_str());
        //AttackPower�� �� ��
    }
}

void Dante::TakeDamage(int InDamage)
{
    if (IgnoreNextDamage)
    {
        printf("%s�� ������ ������ �̹� ���ظ� �����ߴ�!\n", Name.c_str());
        IgnoreNextDamage = false;  // �� ���� �����ϹǷ� �ٽ� false
        return;
    }

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
        printf("%s: ������ ���� ������ ��.\n", Name.c_str());
    }
    break;
    case 2:
    {
        printf("%s: ����Ʈ��ü��...\n", Name.c_str());
    }
    break;
    case 3:
    {
        printf("%s: �Ű��� ���� ������ �ʴ´�.\n", Name.c_str());
    }
    break;
    default:
        //ERROR!!
        break;
    }
    printf("\n");
    // ���� ü�� - �÷��̾� ���ݷ�
}

void Dante::DantePoemSkill()
{
    if (Health <= 26)   //�ִ� ü���� 20% ������ �� �ߵ�
    {
        printf("|| Lasciate ogne speranza, voi ch��intrate ||\n");   // ������ �Ű� [����]�� ������ ����
        printf("%s�� ��� ������ ���� ����, ���� ���ظ� �����Ѵ�!\n\n", Name.c_str());

        IgnoreNextDamage = true; // ���� �������� �����ϰ� �÷��� ����
    }

}

