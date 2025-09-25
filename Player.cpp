#include "Player.h"
#include <cwchar>   // wprintf
#include <cstdlib>
#include <random>

void Player::PlayerHeal(int InPoetHealth)
{
    int Current = PlayerHealth;
    SetPlayerHealth(Current + InPoetHealth);
    printf("체력이 회복됐습니다. [체력 : %d] -> [체력 : %d]\n", Current, PlayerHealth);
}

void Player::PayInk(int InPutInk)
{
    SetPlayerInk(Ink - InPutInk);
    printf("[잉크 : %d ]를 사용했습니다.\n", InPutInk);
}

void Player::TakeInk(int InPutInk)
{
    SetPlayerInk(Ink + InPutInk);
    printf("[잉크 : %d ]를 얻었습니다.\n", InPutInk);
}

void Player::AttackPowerUP()
{
    const int PowerPoint = 10;
    int Current = PlayerAttackPower;
    SetPlayerAttackPower(PlayerAttackPower + PowerPoint);
    std::wstring poem = Poems.back();
    wprintf(L"\n(\"%ls\")가 윤동주의 첨삭으로 강해졌다.\n",  poem.c_str());
    printf("[공격력 : %d] -> [공격력 : %d]\n", Current, PlayerAttackPower);
}

void Player::HealthPowerUP()
{
    const int PowerPoint = 50;
    int Current = MaxHealth;
    SetPlayerMaxHealth(PowerPoint);
    wprintf(L"\n[%ls]가 윤동주의 시를 읽어서 강해졌다.\n", Name.c_str());
    printf("[쵀대 체력 : %d] -> [최대 체력 : %d]\n", Current, MaxHealth);
}

void Player::Attack(ICanBattle* InTarget)
{
    int BonusAttack = rand() % 6;
    int AttackPower = PlayerAttackPower + BonusAttack;


    if (!Poems.empty())
    {
        std::wstring poem = Poems.back();
        wprintf(L"\n%ls의 시구가 울려 퍼진다! (\"%ls\")\n", Name.c_str(), poem.c_str());
    }
    else
    {
        wprintf(L"%ls의 공격! (공격력: %d)\n", Name.c_str(), AttackPower);
    }

    InTarget->TakeDamage(AttackPower);
}

void Player::TakeDamage(int InDamage)
{
    SetPlayerHealth(PlayerHealth - InDamage);
    if (PlayerHealth < 0)
    {
        PlayerHealth = 0;
        printf("당신의 시는 세상에 닿지 못 했습니다... (게임 패배)");
    }

    wprintf(L"%ls는 %d의 피해를 입었다! (남은 체력: %d)\n\n", Name.c_str(), InDamage, PlayerHealth);
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
    int length = (int)poem.length();   // wstring으로 한글 글자 수 계산

    if (length > 20)
    {
        PlayerAttackPower = 5;
        printf("윤동주: 20글자가 넘어갔어! 리바운드로 시의 능력이 떨어질거야... (공격력: %d)\n", PlayerAttackPower);
    }
    else if (length >= 10 && length <= 20)
    {
        PlayerAttackPower = 20;
        printf("윤동주: 좋아! 아주 적당한 길이야 그리고 너무 멋지고 강한 문장이야! (공격력: %d)\n", PlayerAttackPower);
    }
    else
    {
        PlayerAttackPower = 10 + (rand() % 6);  // 10~15 랜덤
        printf("윤동주: 너도 이제 시의 힘을 얻은거야. (공격력: %d)\n", PlayerAttackPower);
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
    printf("\n=== 플레이어의 시집 목록 ===\n");
    if (Inventory.empty()) {
        printf("아직 얻은 시집이 없습니다.\n");
    }
    else {
        for (size_t i = 0; i < Inventory.size(); i++) {
            printf("%d. %s\n", (int)i + 1, GetPoemName(Inventory[i]).c_str());
        }
    }
}
