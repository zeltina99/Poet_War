#include "Battles.h"
#include <iostream>
#include "Map.h"
#include "GameManager.h"


void Battles::CharlesBattle(Player* InPlayer, Charles* InPoet)
{
    int InputNumber = 0;

    while (InPlayer->IsAlivePlayer() && InPoet->IsAliveCharles())
    {
        printf("\n--- ���� �޴� ---\n");
        printf("[���ݷ� : %d]\t[ü�� : %d/%d]\n", InPlayer->GetPlayerAttackPower(), InPlayer->GetPlayerHealth(), InPlayer->GetPlayerMaxHealth());
        printf("�� �ø� �д´�\n");
        printf("> ����: ");
        std::cin >> InputNumber;
        if (InputNumber == 1)
        {
            // �÷��̾� ��
            InPlayer->Attack(InPoet);
            if (!InPoet->IsAliveCharles())
            {
                break;
            }

            // ���� ��
            InPoet->Attack(InPlayer);
            if (!InPlayer->IsAlivePlayer())
            {
                break;
            }
        }
        else
        {
            printf("\n�߸��� �Է��̾�! �ٽ� �Է�����\n");
        }
    }
    if (InPlayer->IsAlivePlayer())
    {
        InPlayer->TakeInk(200);
        printf("���� ���鷹���� ����Ʈ���� ���� [���� ��]�� �����!\n\n");
        InPlayer->AddPoem(Poem::CharlesPoem);
        printf("������: ���� ���� ������ ����.\n");
    }
}

void Battles::ConanBattle(Player* InPlayer, Conan* InPoet)
{
    GameManager gm;
    gm.BattleMenu(InPlayer, InPoet);

    if (InPoet->GetPoetHealth() <= 0)
    {
        InPlayer->TakeInk(250);   // �ڳ� ���� ����
        InPlayer->AddPoem(Poem::ConanPoem);
        printf("�Ƽ� �ڳ������� ����Ʈ���� ���� [Ȱ�� �뷡]�� �����!\n\n");
        printf("������: ���� ���� ������ ����.\n");
    }
}

void Battles::DanteBattle(Player* InPlayer, Dante* InPoet)
{
    GameManager gm;
    gm.BattleMenu(InPlayer, InPoet);

    if (InPoet->GetPoetHealth() <= 0)
    {
        InPlayer->TakeInk(300);   // ���� ���� ����
        InPlayer->AddPoem(Poem::DantePoem);
        printf("���׸� ����Ʈ���� ���� [�Ű�]�� �����!\n\n");
        printf("������: ���� ���� ������ ����.\n");
    }
}

void Battles::GoetheBattle(Player* InPlayer, Goethe* InPoet)
{
    GameManager gm;
    gm.BattleMenu(InPlayer, InPoet);

    if (InPoet->GetPoetHealth() <= 0)
    {
        InPlayer->TakeInk(250);   // ���� ���� ����
        InPlayer->AddPoem(Poem::GoethePoem);
        printf("���׸� ����Ʈ���� ���� [����]�� �����!\n\n");
        printf("������: ���� ���� ������ ����.\n");
    }
}

void Battles::KenjiBattle(Player* InPlayer, Kenji* InPoet)
{
    GameManager gm;
    gm.BattleMenu(InPlayer, InPoet);

    if (InPoet->GetPoetHealth() <= 0)
    {
        InPlayer->TakeInk(250);   // ���� ���� ����
        InPlayer->AddPoem(Poem::KenjiPoem);
        printf("�̾��ڿ� ������ ����Ʈ���� ���� [�񿡵� ���� �ʰ�]�� �����!\n\n");
        printf("������: ���� ���� ������ ����.\n");
    }
}

void Battles::KimSowolBattle(Player* InPlayer, KimSowol* InPoet)
{
    GameManager gm;
    gm.BattleMenu(InPlayer, InPoet);

    if (InPoet->GetPoetHealth() <= 0)
    {
        InPlayer->TakeInk(250);   // ��ҿ� ���� ����
        InPlayer->AddPoem(Poem::KimSowolPoem);
        printf("��ҿ��� ����Ʈ���� ���� [���޷���]�� �����!\n\n");
        printf("������: ���� ���� ������ ����.\n");
    }
}