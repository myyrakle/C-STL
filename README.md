# C-STL

C의 매크로 함수를 응용하여 C++의 STL(Standard Template Library)을 흉내낸 라이브러리입니다.  
  
  
C++의 std::array에 해당하는 매크로는 decl_array입니다.  
아래와 같이 선언하면 int 타입에 길이가 10인 배열 타입이 int_array라는 이름으로 구체화됩니다.  
decl_array(int_array, int, 10);
  
그리고 객체의 생성은 아래와 같이 합니다. 꼭 make를 쓰지 않아도 되지만 권장하지 않습니다.  
int_array arr = make_int_array();
  
  
매크로의 목록과 현황은 아래와 같습니다.  
decl_array : 컴파일타임 정적 배열. 구현 완료  
decl_darray : 런타임 고정배열. 미구현  
decl_vector : 런타임 가변배열. 구현중  
decl_list : 연결리스트. 미구현  
decl_treeset : 트리셋. 미구현  
decl_treemap : 트리맵. 미구현  
decl_hashset : 해시셋. 미구현  
decl_hashmap : 해시맵. 미구현  
decl_stack : 스택. 구현 
decl_queue : 큐. 미구현  
decl_maxheap : 최대 힙. 미구현  
decl_minheap : 최소 힙. 미구현  
