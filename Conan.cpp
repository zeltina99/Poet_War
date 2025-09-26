#include "Conan.h"

void Conan::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower
    int PoemAttackPower = AttackPower;
    int SkillEventNumber = rand() % 5;

    bool DoubleAttak = false;

    if (SkillEventNumber == 4)  // ���� �� �� ���� 20% Ȯ���� ������ �ι� �Ѵ�.
    {
        printf("|| It is there that our mark will be. ||\n");   // �Ƽ� �ڳ������� Ȱ�� �뷡�� �� ����
        DoubleAttak = true;
    }


    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("%s: �� ȭ���� �뷡�ϵ� ���ư���!\n", Name.c_str());
        //PoemAttackPower��ŭ ������
        InTarget->TakeDamage(AttackPower);
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("%s: �ٽ�Ŀ�� ���� ��ɰ���!\n", Name.c_str());
        //PoemAttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
        PoemAttackPower = AttackPower * 2;
        InTarget->TakeDamage(PoemAttackPower);
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("%s: ��Ž���̶� ���� �� �� �����ΰ�...\n", Name.c_str());
        //PoemAttackPower�� �� ��
    }
    if (DoubleAttak)
    {
        InTarget->TakeDamage(AttackPower);
    }

}

void Conan::TakeDamage(int InDamage)
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
        printf("%s: ��! ���Ŵ� ���� �ӿ� ����.\n", Name.c_str());
    }
    break;
    case 2:
    {
        printf("%s: ������ �Ȱ����� ������.\n", Name.c_str());
    }
    break;
    case 3:
    {
        printf("%s: ���� �ô� ��Ⱑ ���� ����.\n", Name.c_str());
    }
    break;
    default:
        //ERROR!!
        break;
    }
    printf("%s�� %d�� ���ظ� �Ծ���! ([%s]�� ���� ü��: %d)\n", Name.c_str(), InDamage, Name.c_str(), Health);
    printf("\n");
}


