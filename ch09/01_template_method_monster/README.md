# 몬스터 템플릿 메서드 패턴 예제

## 📁 파일 구조 설명

### 1. character.h
- **역할**: 캐릭터 관련 클래스 선언
- **내용**: 
  - `character` 클래스 (기본 캐릭터)
  - `player` 클래스 (플레이어)
- **왜 분리?**: 캐릭터는 독립적인 개념이므로 별도 파일로 관리

### 2. monster.h
- **역할**: 몬스터 클래스 선언
- **내용**:
  - `monster` 추상 클래스 (인터페이스)
  - `monster_a`, `monster_b`, `monster_c` 클래스 선언
- **왜 분리?**: 몬스터 관련 설계도만 모아서 보기 쉽게

### 3. monster.cpp
- **역할**: 몬스터 클래스 구현
- **내용**: 각 몬스터의 실제 동작 코드
- **왜 분리?**: 선언(설계도)과 구현(실제 코드)을 분리

### 4. monster_factory.h
- **역할**: 몬스터 팩토리 클래스 선언
- **내용**: 몬스터 생성/관리 함수 선언
- **왜 분리?**: 몬스터 생성 로직은 별도로 관리

### 5. monster_factory.cpp
- **역할**: 몬스터 팩토리 구현
- **내용**: 실제 몬스터 생성/삭제 코드
- **왜 분리?**: 구현 코드를 헤더와 분리

### 6. main.cpp
- **역할**: 프로그램 시작점
- **내용**: main 함수와 실행 로직
- **왜 분리?**: 실행 코드는 항상 별도 파일

## 🔧 컴파일 방법

### Visual Studio에서:
1. 모든 .cpp 파일을 프로젝트에 추가
2. F5 또는 Ctrl+F5로 실행

### 명령줄에서:
```bash
# 모든 cpp 파일을 함께 컴파일
g++ main.cpp monster.cpp monster_factory.cpp -o game.exe

# 실행
game.exe
```

## 💡 초보자를 위한 팁

### #ifndef, #define, #endif는 뭔가요?
```cpp
#ifndef CHARACTER_H  // "CHARACTER_H가 정의되지 않았다면"
#define CHARACTER_H  // "CHARACTER_H를 정의해라"
// ... 코드 ...
#endif              // "조건문 끝"
```
- **목적**: 같은 헤더 파일이 여러 번 포함되는 것을 방지
- **예시**: A.cpp와 B.cpp가 모두 character.h를 include해도 문제없음
- **이름 규칙**: 보통 파일명을 대문자로 변환 (character.h → CHARACTER_H)

### 왜 .h와 .cpp로 나누나요?
- **.h (헤더)**: "이런 함수가 있어요" (선언)
- **.cpp (구현)**: "함수가 실제로 이렇게 동작해요" (정의)
- **장점**: 
  - 다른 파일에서 .h만 include하면 사용 가능
  - .cpp 수정해도 .h를 include한 다른 파일은 재컴파일 안 해도 됨

### static 멤버 변수는 왜 .cpp에서 초기화하나요?
```cpp
// monster_factory.cpp
list<monster*> monster_factory::mon_list = {};
```
- **이유**: static 변수는 프로그램 전체에서 하나만 존재
- **규칙**: .h에서 선언, .cpp에서 초기화
- **만약 .h에서 초기화하면?**: 여러 파일에서 include할 때 중복 정의 오류 발생

## 📊 파일 분리 전후 비교

### 분리 전:
```
01_template_method_monster.cpp (250줄)
```

### 분리 후:
```
character.h           (30줄)
monster.h            (50줄)
monster.cpp          (90줄)
monster_factory.h    (45줄)
monster_factory.cpp  (70줄)
main.cpp            (40줄)
```

## ✅ 실무 파일 분리 원칙

1. **한 파일 = 한 가지 역할**
   - character.h: 캐릭터만
   - monster.h: 몬스터만
   - monster_factory.h: 팩토리만

2. **헤더와 구현 분리**
   - 선언(.h)과 정의(.cpp)를 나눔
   - 컴파일 시간 단축

3. **의존성 최소화**
   - main.cpp는 필요한 헤더만 include
   - monster.cpp는 monster.h만 include

4. **파일명 = 클래스명**
   - monster 클래스 → monster.h, monster.cpp
   - 찾기 쉬움!

## 🎯 이렇게 분리하면 좋은 점

1. **버그 수정**: monster_a에 문제? → monster.cpp만 열면 됨
2. **기능 추가**: 새 몬스터 추가? → monster.h와 monster.cpp만 수정
3. **협업**: A는 monster.cpp, B는 main.cpp 동시 작업 가능
4. **재사용**: character.h는 다른 프로젝트에서도 사용 가능
