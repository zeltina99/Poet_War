#include "TwilightPoet.h"

void TwilightPoet::Attack(ICanBattle* InTarget)
{
    if (!IsTransformed)
    {
        printf("%s: '���� �ø� �����ٿ�!'\n", Name.c_str());
    }
    else
    {
        printf("%s: '�ð��� ���� �տ��� �ʴ� �����ϴ�!'\n", Name.c_str());
    }
    InTarget->TakeDamage(AttackPower);
}

void TwilightPoet::TakeDamage(int InDamage)
{
    Health -= InDamage;
    if (Health < 0) Health = 0;

    printf("%s�� %d�� ���ظ� �Ծ���! (���� ü��: %d)\n", Name.c_str(), InDamage, Health);
}

void TwilightPoet::TransformToShakespeare()
{
    printf("�������� ����� ��Ʋ����, ���ͽ��Ǿ ��Ÿ����!\n");
    Name = "William Shakespeare";
    Health = 300;      // ��ȭ�� ü��
    AttackPower = 25;  // ��ȭ�� ���ݷ�
    IsTransformed = true;
}