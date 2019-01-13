# C-STL

C의 매크로 함수를 응용하여 C++의 STL(Standard Template Library)을 흉내낸 라이브러리입니다.  
  
  
C++의 std::array에 해당하는 매크로는 decl_array입니다.  
아래와 같이 선언하면 int 타입에 길이가 10인 배열 타입이 int_array라는 이름으로 구체화됩니다.  
decl_array(int_array, int, 10);
