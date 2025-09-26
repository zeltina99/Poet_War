#include "Map.h"
#include <fstream>
#include <string>


void Map::TutorialMap()
{
	const char* FilePath = ".\\Data\\TutorialMap.txt";
	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// ������ ���ȴ��� Ȯ���ϴ� �Լ�
	{
		printf("������ �� �� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile�� �ִ� ���ڵ��� ��� �о FileContents�� �����ϱ�
	printf("%s\n", FileContents.c_str());	// FileContents�ȿ� �ִ� ���ڿ��� const 
	printf("\n\t       [�� ��� ���]\n");
}

void Map::ScentveilMap()
{

	const char* FilePath = ".\\Data\\ScentveilMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// ������ ���ȴ��� Ȯ���ϴ� �Լ�
	{
		printf("������ �� �� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile�� �ִ� ���ڵ��� ��� �о FileContents�� �����ϱ�
	printf("%s\n", FileContents.c_str());	// FileContents�ȿ� �ִ� ���ڿ��� const 
	printf("\t      [����� �帷]\n");
}

void Map::InferniaMap()
{
	const char* FilePath = ".\\Data\\InferniaMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// ������ ���ȴ��� Ȯ���ϴ� �Լ�
	{
		printf("������ �� �� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile�� �ִ� ���ڵ��� ��� �о FileContents�� �����ϱ�
	printf("%s\n", FileContents.c_str());	// FileContents�ȿ� �ִ� ���ڿ��� const 
	printf("\t     [������ �� �� ����]\n");
	printf("\n������: �� ���� �Ѻ����� �ڵ��� �ϳ����� ������ٴ� ��Ⱑ �־�...\n\n");
}

void Map::FaustburgMap()
{
	const char* FilePath = ".\\Data\\FaustburgMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// ������ ���ȴ��� Ȯ���ϴ� �Լ�
	{
		printf("������ �� �� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile�� �ִ� ���ڵ��� ��� �о FileContents�� �����ϱ�
	printf("%s\n", FileContents.c_str());	// FileContents�ȿ� �ִ� ���ڿ��� const 
	printf("\t\t   [�Ŀ콺Ʈ�� ��ä]\n");
	printf("\n������: �Ŀ콺Ʈ�� ��ä... ����� �ȾƳѱ��� ���� ��ȥ�̶�� �����ϴ� �� ����.\n\n");

}

void Map::AzaleanMap()
{
	const char* FilePath = ".\\Data\\AzaleanMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// ������ ���ȴ��� Ȯ���ϴ� �Լ�
	{
		printf("������ �� �� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile�� �ִ� ���ڵ��� ��� �о FileContents�� �����ϱ�
	printf("%s\n", FileContents.c_str());	// FileContents�ȿ� �ִ� ���ڿ��� const 
	printf("\t\t[���޷��� ���]\n");
	printf("\n������: �ٶ��� ��鸮�� ������ ����... �������� �ʾ�?\n\n");

}

void Map::ShercroftMap()
{
	const char* FilePath = ".\\Data\\ShercroftMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// ������ ���ȴ��� Ȯ���ϴ� �Լ�
	{
		printf("������ �� �� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile�� �ִ� ���ڵ��� ��� �о FileContents�� �����ϱ�
	printf("%s\n", FileContents.c_str());	// FileContents�ȿ� �ִ� ���ڿ��� const 
	printf("\t\t  [�߸��� ��]\n");
	printf("\n������: �׸��� �ϳ������� �ܼ��� �Ǵ� �����̾�.\n\n");
}

void Map::KazehamuraMap()
{
	const char* FilePath = ".\\Data\\KazehamuraMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// ������ ���ȴ��� Ȯ���ϴ� �Լ�
	{
		printf("������ �� �� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile�� �ִ� ���ڵ��� ��� �о FileContents�� �����ϱ�
	printf("%s\n", FileContents.c_str());	// FileContents�ȿ� �ִ� ���ڿ��� const 
	printf("\t      [��ǳ����]\n");
	printf("\n������: �鰳�� �ٶ��� �дٴ� �����̾�.\n\n");
}

void Map::AvonSanctumMap()
{
	const char* FilePath = ".\\Data\\AvonSanctumMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// ������ ���ȴ��� Ȯ���ϴ� �Լ�
	{
		printf("������ �� �� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile�� �ִ� ���ڵ��� ��� �о FileContents�� �����ϱ�
	printf("%s\n", FileContents.c_str());	// FileContents�ȿ� �ִ� ���ڿ��� const 
	printf("������: ................\n\n");
}