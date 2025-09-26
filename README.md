# 📖 Poet War (포엣 워)

**시인들의 싸움이 시작된다.**  
플레이어는 이름과 시 한 구절을 정하고, 시를 무기로 삼아 전투를 펼친다.  
시인을 이길 때마다 그들의 **시집**을 얻고, 모두 모으면 최종 보스와 맞설 수 있다.  

---

## 🎮 게임 개요
- **플레이어**: 이름 입력 + 자신의 시 한 구절 입력  
  - ✍️ 시를 쓰면 → 글자 수에 비례해 공격력 상승  
  

- **동료 시인**: 윤동주  
  - 플레이어에게 명분과 첫 전투(튜토리얼)를 가르쳐주는 존재
  - 여타 다른 RPG에서 강화나 체력회복을 도맡아주는 존재
  - 📖 윤동주의 시를 읽으면 → 최대 체력 상승
  - ✍️ 윤동주에게 시를 첨삭받으면 → 공격력 상승

---

## ⚔️ 진행 구조
1. **라운드 전투**
   - 1라운드: 윤동주 (튜토리얼)  
   - 2~7라운드: 전설적인 시인(문호)들과의 전투  

2. **시집 획득**
   - 승리 시, 각 시인의 대표작을 상징하는 시집 획득  

3. **최종 보스전**
   - 모든 시집을 모으면 보스로 가는 맵이 열림

---

## 📚 등장 시인 & 시집
- 샤를 보들레르 — *악의 꽃*  
- 단테 — *신곡*  
- 괴테 — *마왕*  
- 김소월 — *진달래꽃*  
- 아서 코난 도일 — *활의 노래*  
- 미야자와 겐지 — *비에도 지지 않고*  
- 윤동주 — (플레이어 조력자)  

---

## 🌟 엔딩 연출
플레이어 체력이 **1** 남았을 때, 모은 시집이 한 구절로 합쳐진다:

> “악의 꽃에서 피어난 마왕은  
> 비에도 지지 않는 진달래 꽃처럼  
> 활을 들고 신곡을 노래하네.”

이 문장으로 최종 일격을 날리고 게임이 마무리된다.  

---

## 💻 코드 설명

### 1. ⌨️ 타자기 효과 함수 (`TypeWriterPrint`)

게임 속 대사를 **한 글자씩 타자기처럼 출력**하는 연출을 담당하는 핵심 함수입니다.  
플레이어가 읽는 시나 보스의 대사가 살아 움직이는 듯한 분위기를 줍니다.  

```cpp
// 문자열을 타자기처럼 한 글자씩 출력하는 함수
#include <chrono>     // 시간 단위(std::chrono::milliseconds) 사용
#include <thread>     // std::this_thread::sleep_for 사용

void GameManager::TypeWriterPrint(const std::string& text, int delay_ms)
{
    for (char c : text)
    {
        printf("%c", c);        // 현재 문자를 콘솔에 출력
        fflush(stdout);         // 출력 버퍼를 즉시 비워 화면에 보이게 함
        std::this_thread::sleep_for(
            std::chrono::milliseconds(delay_ms));  // 출력 간격 (타자기 속도)
    }
}
```
### 2. 📝 플레이어 입력 (이름 & 시 한 구절)

게임 시작 시, 플레이어는 자신의 **이름**과 **시 한 구절**을 입력합니다.  
이 시 구절은 곧 플레이어의 **공격력 계산**에 사용됩니다.  

```cpp

#include <locale>    //setlocale(LC_ALL, ""); 같이 쓰면 콘솔 입출력 로케일을 시스템 기본(예: UTF-8, CP949 등)으로 맞춰줍니다. (즉, 콘솔창에서 한글이 안 깨지려면 필요한 헤더 파일)
#include <codecvt>   // string <-> wstring 변환 (파일 입출력이나 string 변환이 필요한 경우에만 필요합니다.)
std::wstring PlayerName;
wprintf(L"윤동주: 너의 이름은 무엇이니?\n> ");
std::wcin >> PlayerName;

wprintf(L"윤동주: %ls... 좋은 이름이네.\n", PlayerName.c_str());
wprintf(L"윤동주: 네가 쓰고 싶은 시 한 구절을 적어보아라. 단 20글자 안으로 부탁할게...\n> ");
std::wstring Poem;
std::getline(std::wcin, Poem);

player.Init(PlayerName);    // 플레이어 초기화
player.SetPoem(Poem);       // 입력한 시 저장
player.DecideAttackPower(); // 시 길이에 따라 공격력 결정
```
### 📝 wprintf와 L 설명

- **`wprintf`**  
  - `printf`의 와이드 버전 (`wchar_t` 기반)  
  - `std::wstring` 또는 `wchar_t*` 문자열을 출력할 때 사용  

- **`L` 접두사**  
  - 문자열을 **와이드 문자열 리터럴**로 선언  
  - `"문자열"` → `const char*`  
  - `L"문자열"` → `const wchar_t*`  


📸 스크린샷

<img width="336" height="232" alt="01" src="https://github.com/user-attachments/assets/82de0ed4-e220-4414-8bf6-2fa632f7900e" />

<img width="722" height="304" alt="02" src="https://github.com/user-attachments/assets/675cc011-ec26-4833-9e91-e8d5801805c6" />

<img width="514" height="361" alt="03" src="https://github.com/user-attachments/assets/f59cad4b-6bc4-411f-ae1d-d5efdad9d71b" />

<img width="471" height="101" alt="4" src="https://github.com/user-attachments/assets/261f5fe6-192d-4b26-bd78-8cf0c8ac6f76" />

<img width="664" height="603" alt="5" src="https://github.com/user-attachments/assets/cb45e753-a0ad-4f43-a530-a2cde107d81f" />



