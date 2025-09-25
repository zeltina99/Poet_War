#include "Player.h"
#include <cwchar>   // wprintf
#include <cstdlib>
#include <random>

void Player::PlayerHeal(int InPoetHealth)
{
    int Current = PlayerHealth;
    SetPlayerHealth(Current + InPoetHealth);
    printf("ü���� ȸ���ƽ��ϴ�. [ü�� : %d] -> [ü�� : %d]\n", Current, PlayerHealth);
}

void Player::PayInk(int InPutInk)
{
    SetPlayerInk(Ink - InPutInk);
    printf("[��ũ : %d ]�� ����߽��ϴ�.\n", InPutInk);
}

void Player::TakeInk(int InPutInk)
{
    SetPlayerInk(Ink + InPutInk);
    printf("[��ũ : %d ]�� ������ϴ�.\n", InPutInk);
}

void Player::AttackPowerUP()
{
    const int PowerPoint = 10;
    int Current = PlayerAttackPower;
    SetPlayerAttackPower(PlayerAttackPower + PowerPoint);
    std::wstring poem = Poems.back();
    wprintf(L"\n(\"%ls\")�� �������� ÷������ ��������.\n",  poem.c_str());
    printf("[���ݷ� : %d] -> [���ݷ� : %d]\n", Current, PlayerAttackPower);
}

void Player::HealthPowerUP()
{
    const int PowerPoint = 50;
    int Current = MaxHealth;
    SetPlayerMaxHealth(PowerPoint);
    wprintf(L"\n[%ls]�� �������� �ø� �о ��������.\n", Name.c_str());
    printf("[���� ü�� : %d] -> [�ִ� ü�� : %d]\n", Current, MaxHealth);
}

void Player::Attack(ICanBattle* InTarget)
{
    int BonusAttack = rand() % 6;
    int AttackPower = PlayerAttackPower + BonusAttack;


    if (!Poems.empty())
    {
        std::wstring poem = Poems.back();
        wprintf(L"\n%ls�� �ñ��� ��� ������! (\"%ls\")\n", Name.c_str(), poem.c_str());
    }
    else
    {
        wprintf(L"%ls�� ����! (���ݷ�: %d)\n", Name.c_str(), AttackPower);
    }

    InTarget->TakeDamage(AttackPower);
}

void Player::TakeDamage(int InDamage)
{
    SetPlayerHealth(PlayerHealth - InDamage);
    if (PlayerHealth < 0)
    {
        PlayerHealth = 0;
        printf("����� �ô� ���� ���� �� �߽��ϴ�... (���� �й�)");
    }

    wprintf(L"%ls�� %d�� ���ظ� �Ծ���! (���� ü��: %d)\n\n", Name.c_str(), InDamage, PlayerHealth);
}

void Player::SetPoem(std::wstring InPoem)
{
    Poems.push_back(InPoem);
}

void Player::DecideAttackPower()
{
    if (Poems.empty()) return;
    Poems.reserve(50);
    std::wstring poem = Poems.back();
    int length = (int)poem.length();   // wstring���� �ѱ� ���� �� ���

    if (length > 20)
    {
        PlayerAttackPower = 5;
        printf("������: 20���ڰ� �Ѿ��! ���ٿ��� ���� �ɷ��� �������ž�... (���ݷ�: %d)\n", PlayerAttackPower);
    }
    else if (length >= 10 && length <= 20)
    {
        PlayerAttackPower = 20;
        printf("������: ����! ���� ������ ���̾� �׸��� �ʹ� ������ ���� �����̾�! (���ݷ�: %d)\n", PlayerAttackPower);
    }
    else
    {
        PlayerAttackPower = 10 + (rand() % 6);  // 10~15 ����
        printf("������: �ʵ� ���� ���� ���� �����ž�. (���ݷ�: %d)\n", PlayerAttackPower);
    }

}

void Player::TalkToYoon()
{
}

void Player::MoveToLocation()
{
}

void Player::InvestigateArea()
{
}

void Player::OpenInventory()
{
}

void Player::RecitePoemAttack()
{
}

void Player::UnleashPoemSkill()
{
}

void Player::AddPoem(Poem poem)
{
    Inventory.push_back(poem);
}

void Player::ShowInventory() const
{
    printf("\n=== �÷��̾��� ���� ��� ===\n");
    if (Inventory.empty()) {
        printf("���� ���� ������ �����ϴ�.\n");
    }
    else {
        for (size_t i = 0; i < Inventory.size(); i++) {
            printf("%d. %s\n", (int)i + 1, GetPoemName(Inventory[i]).c_str());
        }
    }
}
