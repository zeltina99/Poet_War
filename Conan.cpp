#include "Conan.h"

void Conan::Attack(ICanBattle* InTarget)
{
    int AttackEventNumber = rand() % 10;
    //PoemAttackPower

    if (AttackEventNumber < 7)    // �⺻ ���� (���� Ȯ�� 70%)
    {
        printf("�� ȭ���� �뷡�ϵ� ���ư���!\n");
        //PoemAttackPower��ŭ ������
    }
    else if ((7 <= AttackEventNumber) && (AttackEventNumber < 9))   // ġ��Ÿ ���� (���� Ȯ�� 20%)
    {
        printf("�ٽ�Ŀ�� ���� ��ɰ���!\n");
        //PoemAttackPower�� �� 2�� ��ŭ ������ (���� ��ų�� ���� ġ��Ÿ�� ������ 4��)
    }
    else        // ������ Ȯ�� (10%)  
    {
        printf("��Ž���̶� ���� �� �� �����ΰ�...\n");
        //PoemAttackPower�� �� ��
    }
}

void Conan::TakeDamage(int InDamage)
{
    int TakeEventNumber = (rand() % 3) + 1;
    //PlayerAttackPower
    switch (TakeEventNumber)    // ���� �¾��� �� ���� ��� 3�� ���� �ϳ�
    {
    case 1:
    {
        printf("��! ���Ŵ� ���� �ӿ� ����.\n");
    }
    break;
    case 2:
    {
        printf("������ �Ȱ����� ������.\n");
    }
    break;
    case 3:
    {
        printf("���� �ô� ��Ⱑ ���� ����.\n");
    }
    break;
    default:
        //ERROR!!
        break;
    }
    // �Ƽ� �ڳ����� ü�� - �÷��̾� ���ݷ�
}

void Conan::ConanPoemSkill()
{
    int SkillEventNumber = rand() % 5;

    if (SkillEventNumber == 4)  // ���� �� �� ���� 20% Ȯ���� ������ �ι� �Ѵ�.
    {
        printf("|| It is there that our mark will be. ||\n");   // �Ƽ� �ڳ������� Ȱ�� �뷡�� �� ����
    }

}

inline bool Conan::IsAliveConan()
{
    return false;
}

void Conan::ConanDefeat()
{
}
