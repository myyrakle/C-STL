# C-STL  
  
![](https://img.shields.io/badge/language-C-red) ![](https://img.shields.io/badge/version-0.1.0-brightgreen) [![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/myyrakle/C-STL/blob/master/LICENSE)  
  
## 소개
C의 매크로 함수를 응용하여 C++의 STL(Standard Template Library)을 흉내낸 라이브러리입니다.  
멤버-함수포인터를 사용하여 객체지향적 형식을 가집니다.  
사용 조건은 C99입니다. C99의 몇몇 표준 라이브러리(stdbool.h 등)에 종속적입니다. 이 문제는 차후 해결할 예정에 있습니다...
  
***  
  
## 라이센스
  
라이센스는 MIT 라이센스를 적용합니다.  
막 갖다쓰셔도 됩니다.  
  
***  
  
[레퍼런스용 위키로 이동](https://github.com/myyrakle/C-STL/wiki)  
  
***  
  
## 구현 현황  
  
매크로의 목록과 현황은 아래와 같습니다.  
- decl_array : 컴파일타임 정적 배열(compiletime static array).   
- decl_darray : 런타임 고정배열(runtime dynamic fixed array).    
- decl_vector : 런타임 가변배열(runtime dynamic mutable array).   
- decl_stack : 스택(stack).   
- decl_queue : 큐(queue).   
- decl_list : 양방향 연결리스트(linked list).  
- decl_forward_list : 단방향 연결리스트(single linked list).  
- decl_circular_lisr : 원형 연결리스트(circular linked list). 구현중
- decl_treeset : 트리셋(tree set). Not Implemented  
- decl_treemap : 트리맵(tree map). Not Implemented  
- decl_hashset : 해시셋(hashtable set). Not Implemented  
- decl_hashmap : 해시맵(hashtable map). 구현중  
- decl_maxheap : 최대 힙(max heap). Not Implemented  
- decl_minheap : 최소 힙(min heap). Not Implemented  
  
***  

## 사용례
  
C++의 std::array에 해당하는 매크로는 decl_array, def_array 입니다.  
아래와 같이 선언하면 int 타입에 길이가 10인 배열 타입이 IntArray라는 이름으로 구체화됩니다.  
```
decl_array(IntArray, int, 10)
def_array(IntArray, int, 10)
```
decl_XXX 는 .h파일에 들어갈 전방선언이 포함되어있습니다.
def_XXX 는 .c파일에 들어갈 메서드 구현이 포함되어있습니다. def_XXX를 .h 파일에서 사용하시면 안됩니다.
  
  
그리고 객체의 생성은 아래와 같이 합니다. 꼭 new를 사용해야 하는 건 아니지만, 추천하지 않습니다.  
```
IntArray arr = new_IntArray();
```
  
  
그리고 메서드를 사용할 때는 아래와 같이 합니다.  
꼭 자기 자신의 주소를 첫번째 인자로 전달해야 합니다.
```
arr.find(&arr, 100);
```
  
  
아래는 예시 이미지입니다.  
![ArrayTest](./image/ArraySimpleTest.png)
***  
  
## 기여자  
- [sean9892](https://github.com/sean9892) (스택, 큐 구현. 다방면의 피드백과 개선)
