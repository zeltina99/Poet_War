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
        wprintf(L"\n%ls: \"%ls\"\n", Name.c_str(), poem.c_str());
    }
    else
    {
        wprintf(L"%ls�� ����! (���ݷ�: %d)\n", Name.c_str(), AttackPower);
    }
    printf("\n");

    if (PlayerAttackPower == 1) // ���� ���� ����� �ʿ��� ���ݷ�
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
        printf("����� �ô� ���� ���� �� �߽��ϴ�... (���� �й�)");
    }

    wprintf(L"%ls�� %d�� ���ظ� �Ծ���! ([%ls]�� ���� ü��: %d)\n\n", Name.c_str(), InDamage, Name.c_str(), PlayerHealth);
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
    if (GetInk() >= 50)
    {
        // ��ũ�� �ִٸ�
        printf("������: ���� �� ȸ���ҷ�? �ƴϸ� �ø� ÷�� ���ٱ�?\n\n");
        int InputNumber1 = -1;
        while (InputNumber1 != 1 && InputNumber1 != 2 && InputNumber1 != 3)
        {
            printf("�� ��ũ 50�� �Ἥ ü���� ȸ���Ѵ�\n�� �ø� ÷���Ѵ�\n�� �ڷΰ���\n");
            printf("> ����: ");
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
                    printf("������: ����! �ø� ÷�� ���ٰ�.\n\n");
                    int InputNumber2 = -1;
                    // �� ��ũ 150�� �Ἥ �ø� ��ȭ�ϱ�(�⺻ ���ݷ� ����), �� ��ũ 150�� �Ἥ �������� �ø� �б�(�ִ� ü�� ����)
                    while (InputNumber2 != 1 && InputNumber2 != 2 && InputNumber2 != 3)   // 1,2,3���� �ϳ��� �Է��� �ȵǸ� ��� �ݺ�
                    {
                        printf("�� ��ũ 150�� �Ἥ �ø� ��ȭ�ϱ�\n�� ��ũ 150�� �Ἥ �������� �ø� �б�\n�� �ڷΰ���\n");
                        printf("> ����: ");
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
                            //�ڷΰ���
                        }
                        else
                        {
                            printf("\n�߸��� �Է��̾�! �ٽ� �Է�����\n");
                        }
                    }
                }
                else
                {
                    printf("������: ���� �ø� ÷�� ���ְ� �; ��ũ�� �ּ��� 150�� �־����.\n\n");
                }
            }
            else if (InputNumber1 == 3)
            {
                //�ڷΰ���
            }
            else
            {
                printf("\n�߸��� �Է��̾�! �ٽ� �Է�����\n");
            }
        }

    }
    else
    {
        // ��ũ�� ���ٸ�
        printf("������: ������ ��ũ�� �ʿ���...\n\n");
    }
}

void Player::MoveToLocation(Chapters* Level)
{
    Level->LevelChapters(this);
}

void Player::InvestigateArea(Chapters* Level)
{
    LocationID loc = Level->GetCurrentLocation();    // enum class�� �� ��ġ ���� ����

    switch (loc)
    {
    case LocationID::Scentveil:
    {
        if (Level->IsPoetAlive(PoetID::CharlesID))   // ������ ��� ������
        {
            printf("���� ���鷹��: Ÿ�� �ӿ��� ���� �ǿ��ָ�.\n");
            // ���� ���� ����
            Level->CharlesChapter(this);  // ���� �Լ� ����
        }
        else
        {
            printf("\n--- �����ϱ� ---\n");
            printf("���� �̹� ����ϴ�... (������ ����Ʈ�ȴ�)\n");
        }
    }
    break;
    case LocationID::Infernia:
    {
        if (Level->IsPoetAlive(PoetID::DanteID))     // ���װ� ��� ������
        {
            printf("����: ���� ��ȥ�� ���� �÷ν� ������ �����ڴ�.\n");
            // ���� ���� ����
            Level->DanteChapter(this);  // ���� �Լ� ����
        }
        else
        {
            printf("\n--- �����ϱ� ---\n");
            printf("�̹� ������ �帥��... (���׸� ����Ʈ�ȴ�)\n");
        }
    }
    break;

    case LocationID::Shercroft:
    {
        if (Level->IsPoetAlive(PoetID::ConanID))     // �ڳ������� ��� ������
        {
            printf("�Ƽ� �ڳ�����: �Ұ����� ���� ��� ���ָ�, ���� �� ���� ��.\n");
            Level->ConanChapter(this);
        }
        else
        {
            printf("\n--- �����ϱ� ---\n");
            printf("���� �̹� ����ϴ�... (�ڳ������� ����Ʈ�ȴ�)\n");
        }
    }
    break;

    case LocationID::Faustburg:
    {
        if (Level->IsPoetAlive(PoetID::GoetheID))    // ���װ� ��� ������
        {
            printf("����: ����� ����� ����� ������ �������.\n");
            Level->GoetheChapter(this);
        }
        else
        {
            printf("\n--- �����ϱ� ---\n");
            printf("�̹� ������ �帥��... (���׸� ����Ʈ�ȴ�)\n");
        }
    }
    break;

    case LocationID::Kazehamura:
    {
        if (Level->IsPoetAlive(PoetID::KenjiID))     // ������ ��� ������
        {
            printf("�̾��ڿ� ����: �ҹ��� ���������� ������ ǰ�´�.\n");
            Level->KenjiChapter(this);
        }
        else
        {
            printf("\n--- �����ϱ� ---\n");
            printf("���� �̹� ����ϴ�... (������ ����Ʈ�ȴ�)\n");
        }
    }
    break;

    case LocationID::Azalean:
    {
        if (Level->IsPoetAlive(PoetID::KimSowolID))      // ��ҿ��� ��� ������
        {
            printf("��ҿ�: �������� ���� �̺��� ȥ, ���� ���� ȥ�� ������.\n");
            Level->KimSowolChapter(this);
        }
        else
        {
            printf("\n--- �����ϱ� ---\n");
            printf("�̹� ������ �帥��... (��ҿ��� ����Ʈ�ȴ�)\n");
        }
    }
    break;
    case LocationID::None:
    default:
        printf("���⼭�� �ƹ��� �߰ߵ��� �ʾҴ�...\n");
        break;
    }
}


void Player::OpenInventory()
{
    ShowInventory();
    wprintf(L"\n �̸� :  [%ls]", GetName().c_str());
    printf("\n ��ũ :  [%d]", GetInk());
    printf("\n ü�� :  [%d/%d]", GetPlayerHealth(), GetPlayerMaxHealth());
    printf("\n ���ݷ� : [%d]\n\n", GetPlayerAttackPower());
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
    int Bonus = (rand() % 21) + 25;   // 20~45���̿� ���� �� ȸ��
    switch (chosenPoem)
    {
    case Poem::CharlesPoem:
        printf("������ �ɡ��� ���ƴ�! ���ݷ��� +5�� �ȴ�!\n");
        target->TakeDamage(PlayerAttackPower + 5);
        break;

    case Poem::DantePoem:
        printf("���Ű�� ���ƴ�! ������ ������ ���� �е��Ѵ�!)\n");
        target->TakeDamage(Bonus);
        break;

    case Poem::GoethePoem:
        printf("�����ա��� ���ƴ�! ������ �ø� Ÿ�� ��������!\n");
        SetPlayerHealth(PlayerHealth - 10);
        target->TakeDamage(PlayerAttackPower + 20);
        break;

    case Poem::KimSowolPoem:
        printf("�����޷��ɡ��� ���ƴ�! ü���� ȸ���ȴ�!\n");
        PlayerHeal(30);
        break;

    case Poem::ConanPoem:
        printf("��Ȱ�� �뷡���� ���ƴ�! ��Ȯ���� ����Ͽ� �߰� ����!\n");
        target->TakeDamage(PlayerAttackPower + (rand() % 30));
        break;

    case Poem::KenjiPoem:
        printf("���񿡵� ���� �ʰ��� ���ƴ�! ������ ��������!\n");
        PlayerHeal(Bonus);
        break;

    default:
        printf("�� �� ���� ������ ���ƴ�...\n");
        break;
    }
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
