# Visual Studio 파일 추가 가이드 (초보자용)

## 🤔 왜 파일이 안 보이나요?

Visual Studio는 **두 가지 개념**을 구분합니다:

### 1. 실제 폴더의 파일 (윈도우 탐색기)
```
📁 01_template_method_monster/
  ├── character.h          ✅ 있음
  ├── monster.h            ✅ 있음
  ├── main.cpp             ✅ 있음
  └── ...
```

### 2. 프로젝트에 포함된 파일 (VS 솔루션 탐색기)
```
📦 01_template_method_monster
  └── 01_template_method_monster.cpp  ❌ 이것만 보임
```

**파일을 만들었다고 자동으로 프로젝트에 추가되지 않습니다!**

---

## ✅ 해결 완료!

제가 이미 프로젝트 파일을 수정해서 새 파일들을 추가했습니다.

### 다음 단계:

1. **Visual Studio를 닫았다면 다시 열기**
   - 솔루션 파일(.sln)을 더블클릭해서 열기

2. **이미 열려있다면 프로젝트 다시 로드**
   - 솔루션 탐색기에서 프로젝트 이름 우클릭
   - "프로젝트 다시 로드" 선택
   - 또는 Visual Studio를 닫았다가 다시 열기

3. **솔루션 탐색기 확인**
   ```
   📦 01_template_method_monster
     ├── 📂 헤더 파일
     │   ├── character.h
     │   ├── monster.h
     │   └── monster_factory.h
     ├── 📂 소스 파일
     │   ├── 01_template_method_monster.cpp (빌드 제외됨)
     │   ├── main.cpp
     │   ├── monster.cpp
     │   └── monster_factory.cpp
   ```

4. **빌드 및 실행**
   - F5 (디버그 모드) 또는 Ctrl+F5 (일반 실행)

---

## 🎓 초보자를 위한 설명

### .vcxproj 파일이란?
- **Visual Studio 프로젝트 설정 파일**
- XML 형식으로 작성됨
- 어떤 파일들을 컴파일할지 정의
- 직접 수정하거나 VS에서 파일 추가로 자동 수정됨

### .vcxproj.filters 파일이란?
- **솔루션 탐색기의 폴더 구조 정의**
- "헤더 파일", "소스 파일" 같은 가상 폴더
- 실제 폴더 구조와는 무관 (보기 편하게 하는 용도)

### 제가 수정한 내용:

#### 1. .vcxproj 파일에 추가:
```xml
<ItemGroup>
  <!-- .cpp 파일들 (컴파일 대상) -->
  <ClCompile Include="main.cpp" />
  <ClCompile Include="monster.cpp" />
  <ClCompile Include="monster_factory.cpp" />
</ItemGroup>
<ItemGroup>
  <!-- .h 파일들 (헤더 파일) -->
  <ClInclude Include="character.h" />
  <ClInclude Include="monster.h" />
  <ClInclude Include="monster_factory.h" />
</ItemGroup>
```

#### 2. 기존 파일 빌드 제외:
```xml
<ClCompile Include="01_template_method_monster.cpp">
  <ExcludedFromBuild>true</ExcludedFromBuild>
</ClCompile>
```
- 기존 파일은 남겨두되 컴파일하지 않음
- 나중에 참고용으로 볼 수 있음

---

## 🔧 수동으로 파일 추가하는 방법 (다음에 참고)

### 방법 1: 솔루션 탐색기에서 추가

1. **솔루션 탐색기**에서 프로젝트 이름 우클릭
2. **추가 > 기존 항목** 선택
3. 추가할 파일 선택 (Ctrl 누르고 여러 개 선택 가능)
4. **추가** 버튼 클릭

### 방법 2: 파일을 드래그 앤 드롭

1. **윈도우 탐색기**에서 파일 선택
2. **Visual Studio 솔루션 탐색기**로 드래그
3. 자동으로 프로젝트에 추가됨

### 방법 3: 새 파일 만들 때 VS에서 직접 생성

1. 솔루션 탐색기에서 프로젝트 우클릭
2. **추가 > 새 항목**
3. 파일 형식 선택 (C++ 파일(.cpp) 또는 헤더 파일(.h))
4. 이름 입력 후 **추가**
5. ✅ 자동으로 프로젝트에 포함됨!

---

## ⚠️ 주의사항

### 1. main 함수는 하나만!
- 현재 `main.cpp`에 main 함수가 있음
- `01_template_method_monster.cpp`에도 main 함수가 있음
- **둘 다 빌드하면 오류 발생!**
- 해결: 기존 파일을 빌드에서 제외 (이미 처리됨)

### 2. 파일 이름과 클래스 이름
- 파일명: `monster.h`, `monster.cpp`
- 클래스명: `monster`, `monster_a`, `monster_b`, `monster_c`
- 보통 파일명 = 주요 클래스명 (찾기 쉬움)

### 3. #include 경로
```cpp
#include "character.h"  // 같은 폴더
#include <iostream>     // 시스템 헤더
```
- `" "`: 프로젝트 폴더에서 찾기
- `< >`: 시스템 폴더에서 찾기

---

## 🎯 빌드 오류가 나면?

### "main이 이미 정의되어 있습니다" 오류
- **원인**: 여러 .cpp 파일에 main 함수가 있음
- **해결**: 기존 파일을 빌드에서 제외 (이미 처리됨)

### "파일을 열 수 없습니다" 오류
- **원인**: #include 경로가 잘못됨
- **해결**: 파일명 확인, 대소문자 확인

### "정의되지 않은 참조" 오류
- **원인**: .h는 있는데 .cpp가 프로젝트에 없음
- **해결**: .cpp 파일을 프로젝트에 추가

---

## 📚 정리

| 작업 | 윈도우 탐색기 | VS 솔루션 탐색기 |
|------|--------------|-----------------|
| 파일 생성 | ✅ 보임 | ❌ 안 보임 |
| 프로젝트 추가 후 | ✅ 보임 | ✅ 보임 |
| 컴파일 대상 | ❌ 아님 | ✅ 맞음 |

**핵심**: Visual Studio는 프로젝트에 명시적으로 추가된 파일만 컴파일합니다!
