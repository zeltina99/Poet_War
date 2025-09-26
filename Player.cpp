#include "Player.h"
#include "Chapters.h"
#include <cwchar>   // wprintf
#include <cstdlib>
#include <random>
#include <iostream>

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
        wprintf(L"\n%ls: \"%ls\"\n", Name.c_str(), poem.c_str());
    }
    else
    {
        wprintf(L"%ls의 공격! (공격력: %d)\n", Name.c_str(), AttackPower);
    }
    printf("\n");

    if (PlayerAttackPower == 1) // 최종 보스 연출상 필요한 공격력
    {
        InTarget->TakeDamage(PlayerAttackPower);
    }
    else
    {
        InTarget->TakeDamage(AttackPower);  
    }
}

void Player::TakeDamage(int InDamage)
{
    SetPlayerHealth(PlayerHealth - InDamage);
    if (PlayerHealth < 0)
    {
        PlayerHealth = 0;
        printf("당신의 시는 세상에 닿지 못 했습니다... (게임 패배)");
    }

    wprintf(L"%ls는 %d의 피해를 입었다! ([%ls]의 현재 체력: %d)\n\n", Name.c_str(), InDamage, Name.c_str(), PlayerHealth);
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
    if (GetInk() >= 50)
    {
        // 잉크가 있다면
        printf("윤동주: 몸을 좀 회복할래? 아니면 시를 첨삭 해줄까?\n\n");
        int InputNumber1 = -1;
        while (InputNumber1 != 1 && InputNumber1 != 2 && InputNumber1 != 3)
        {
            printf("① 잉크 50을 써서 체력을 회복한다\n② 시를 첨삭한다\n③ 뒤로가기\n");
            printf("> 선택: ");
            std::cin >> InputNumber1;
            if (InputNumber1 == 1)
            {
                PayInk(50);
                PlayerHeal(50);
            }
            else if (InputNumber1 == 2)
            {
                if (GetInk() >= 150)
                {
                    printf("윤동주: 좋아! 시를 첨삭 해줄게.\n\n");
                    int InputNumber2 = -1;
                    // ① 잉크 150을 써서 시를 강화하기(기본 공격력 증가), ② 잉크 150을 써서 윤동주의 시를 읽기(최대 체력 증가)
                    while (InputNumber2 != 1 && InputNumber2 != 2 && InputNumber2 != 3)   // 1,2,3에서 하나라도 입력이 안되면 계속 반복
                    {
                        printf("① 잉크 150을 써서 시를 강화하기\n② 잉크 150을 써서 윤동주의 시를 읽기\n③ 뒤로가기\n");
                        printf("> 선택: ");
                        std::cin >> InputNumber2;
                        if (InputNumber2 == 1)
                        {
                            PayInk(150);
                            AttackPowerUP();
                        }
                        else if (InputNumber2 == 2)
                        {
                            PayInk(150);
                            HealthPowerUP();
                        }
                        else if (InputNumber2 == 3)
                        {
                            //뒤로가기
                        }
                        else
                        {
                            printf("\n잘못된 입력이야! 다시 입력해줘\n");
                        }
                    }
                }
                else
                {
                    printf("윤동주: 내가 시를 첨삭 해주고 싶어도 잉크가 최소한 150은 있어야해.\n\n");
                }
            }
            else if (InputNumber1 == 3)
            {
                //뒤로가기
            }
            else
            {
                printf("\n잘못된 입력이야! 다시 입력해줘\n");
            }
        }

    }
    else
    {
        // 잉크가 없다면
        printf("윤동주: 시인은 잉크가 필요해...\n\n");
    }
}

void Player::MoveToLocation(Chapters* Level)
{
    Level->LevelChapters(this);
}

void Player::InvestigateArea(Chapters* Level)
{
    LocationID loc = Level->GetCurrentLocation();    // enum class로 한 위치 값을 받음

    switch (loc)
    {
    case LocationID::Scentveil:
    {
        if (Level->IsPoetAlive(PoetID::CharlesID))   // 샤를이 살아 있으면
        {
            printf("샤를 보들레르: 타락 속에서 꽃을 피워주마.\n");
            // 샤를 전투 실행
            Level->CharlesChapter(this);  // 전투 함수 연결
        }
        else
        {
            printf("\n--- 조사하기 ---\n");
            printf("여긴 이미 고요하다... (샤를을 쓰러트렸다)\n");
        }
    }
    break;
    case LocationID::Infernia:
    {
        if (Level->IsPoetAlive(PoetID::DanteID))     // 단테가 살아 있으면
        {
            printf("단테: 나는 영혼의 길을 시로써 밝혀줄 순례자다.\n");
            // 단테 전투 실행
            Level->DanteChapter(this);  // 전투 함수 연결
        }
        else
        {
            printf("\n--- 조사하기 ---\n");
            printf("이미 정적만 흐른다... (단테를 쓰러트렸다)\n");
        }
    }
    break;

    case LocationID::Shercroft:
    {
        if (Level->IsPoetAlive(PoetID::ConanID))     // 코난도일이 살아 있으면
        {
            printf("아서 코난도일: 불가능한 것을 모두 없애면, 남는 건 진실 뿐.\n");
            Level->ConanChapter(this);
        }
        else
        {
            printf("\n--- 조사하기 ---\n");
            printf("여긴 이미 고요하다... (코난도일을 쓰러트렸다)\n");
        }
    }
    break;

    case LocationID::Faustburg:
    {
        if (Level->IsPoetAlive(PoetID::GoetheID))    // 괴테가 살아 있으면
        {
            printf("괴테: 욕망과 운명을 꿰뚫은 눈으로 상대하지.\n");
            Level->GoetheChapter(this);
        }
        else
        {
            printf("\n--- 조사하기 ---\n");
            printf("이미 정적만 흐른다... (괴테를 쓰러트렸다)\n");
        }
    }
    break;

    case LocationID::Kazehamura:
    {
        if (Level->IsPoetAlive(PoetID::KenjiID))     // 켄지가 살아 있으면
        {
            printf("미야자와 켄지: 소박한 강인함으로 세상을 품는다.\n");
            Level->KenjiChapter(this);
        }
        else
        {
            printf("\n--- 조사하기 ---\n");
            printf("여긴 이미 고요하다... (켄지를 쓰러트렸다)\n");
        }
    }
    break;

    case LocationID::Azalean:
    {
        if (Level->IsPoetAlive(PoetID::KimSowolID))      // 김소월이 살아 있으면
        {
            printf("김소월: 꽃잎으로 남은 이별의 혼, 너의 상대는 혼의 정수다.\n");
            Level->KimSowolChapter(this);
        }
        else
        {
            printf("\n--- 조사하기 ---\n");
            printf("이미 정적만 흐른다... (김소월을 쓰러트렸다)\n");
        }
    }
    break;
    case LocationID::None:
    default:
        printf("여기서는 아무도 발견되지 않았다...\n");
        break;
    }
}


void Player::OpenInventory()
{
    ShowInventory();
    wprintf(L"\n 이름 :  [%ls]", GetName().c_str());
    printf("\n 잉크 :  [%d]", GetInk());
    printf("\n 체력 :  [%d/%d]", GetPlayerHealth(), GetPlayerMaxHealth());
    printf("\n 공격력 : [%d]\n\n", GetPlayerAttackPower());
}

void Player::RecitePoemAttack(Poet* target)
{
    int BonusAttack = rand() % 6;
    int AttackPower = PlayerAttackPower + BonusAttack;

    std::wstring poem = Poems.back();
    wprintf(L"\n%ls: \"%ls\"\n", Name.c_str(), poem.c_str());
    target->TakeDamage(AttackPower);
}

void Player::UnleashPoemSkill(Poem chosenPoem, Poet* target)
{
    int Bonus = (rand() % 21) + 25;   // 20~45사이에 공격 및 회복
    switch (chosenPoem)
    {
    case Poem::CharlesPoem:
        printf("『악의 꽃』을 펼쳤다! 공격력이 +5가 된다!\n");
        target->TakeDamage(PlayerAttackPower + 5);
        break;

    case Poem::DantePoem:
        printf("『신곡』을 펼쳤다! 단테의 구절이 적을 압도한다!)\n");
        target->TakeDamage(Bonus);
        break;

    case Poem::GoethePoem:
        printf("『마왕』을 펼쳤다! 공포가 시를 타고 전해진다!\n");
        SetPlayerHealth(PlayerHealth - 10);
        target->TakeDamage(PlayerAttackPower + 20);
        break;

    case Poem::KimSowolPoem:
        printf("『진달래꽃』을 펼쳤다! 체력이 회복된다!\n");
        PlayerHeal(30);
        break;

    case Poem::ConanPoem:
        printf("『활의 노래』를 펼쳤다! 정확도가 상승하여 추가 피해!\n");
        target->TakeDamage(PlayerAttackPower + (rand() % 30));
        break;

    case Poem::KenjiPoem:
        printf("『비에도 지지 않고』를 펼쳤다! 방어력이 강해졌다!\n");
        PlayerHeal(Bonus);
        break;

    default:
        printf("알 수 없는 시집을 펼쳤다...\n");
        break;
    }
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
