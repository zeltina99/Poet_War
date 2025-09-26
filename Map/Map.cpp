#include "Map.h"
#include <fstream>
#include <string>


void Map::TutorialMap()
{
	const char* FilePath = ".\\Data\\TutorialMap.txt";
	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// 파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기
	printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const 
	printf("\n\t       [별 헤는 언덕]\n");
}

void Map::ScentveilMap()
{

	const char* FilePath = ".\\Data\\ScentveilMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// 파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기
	printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const 
	printf("\t      [향기의 장막]\n");
}

void Map::InferniaMap()
{
	const char* FilePath = ".\\Data\\InferniaMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// 파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기
	printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const 
	printf("\t     [지옥의 문 앞 마을]\n");
	printf("\n윤동주: 저 문을 넘보려는 자들은 하나같이 사라졌다는 얘기가 있어...\n\n");
}

void Map::FaustburgMap()
{
	const char* FilePath = ".\\Data\\FaustburgMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// 파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기
	printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const 
	printf("\t\t   [파우스트의 성채]\n");
	printf("\n윤동주: 파우스트의 성채... 욕망을 팔아넘기지 않은 영혼이라면 조심하는 게 좋아.\n\n");

}

void Map::AzaleanMap()
{
	const char* FilePath = ".\\Data\\AzaleanMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// 파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기
	printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const 
	printf("\t\t[진달래의 언덕]\n");
	printf("\n윤동주: 바람에 흔들리는 꽃잎을 보게... 쓸쓸하지 않아?\n\n");

}

void Map::ShercroftMap()
{
	const char* FilePath = ".\\Data\\ShercroftMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// 파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기
	printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const 
	printf("\t\t  [추리의 뜰]\n");
	printf("\n윤동주: 그림자 하나까지도 단서가 되는 마을이야.\n\n");
}

void Map::KazehamuraMap()
{
	const char* FilePath = ".\\Data\\KazehamuraMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// 파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기
	printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const 
	printf("\t      [백풍마을]\n");
	printf("\n윤동주: 백개의 바람이 분다는 마을이야.\n\n");
}

void Map::AvonSanctumMap()
{
	const char* FilePath = ".\\Data\\AvonSanctumMap.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// 파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요.\n", FilePath);
		return;
	}
	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기
	printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const 
	printf("윤동주: ................\n\n");
}