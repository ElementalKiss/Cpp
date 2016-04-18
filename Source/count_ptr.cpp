#pragma once 
// test comment
 
// counted_ptr
template <class T>
class counted_ptr 
{
public:
    // 포인터를 이용한 초기화 new를 통해 초기화한다.
    explicit counted_ptr (T* p = 0) : m_ptr(p), m_count(new long(1)) { }
 
    // 복사 생성자
    counted_ptr (const counted_ptr<T>& p) throw() : m_ptr(p.m_ptr), m_count(p.m_count)
    {
        // 카운터 증가
        (*m_count)++;
    }
 
    // 소멸자
    ~counted_ptr () throw() { dispose(); }
 
    // 대입 연산자 오버로딩
    counted_ptr<T>& operator= (const counted_ptr<T>& p) throw() 
    {
        // 자신인 경우를 생각해야하므로 
        if (this != &p) 
        {
            dispose();
            m_ptr = p.m_ptr;
            m_count = p.m_count;
            (*m_count)++;
        }
        return *this;
    }
 
    // * 연산자 오버로딩
    T& operator*() const throw() { return *m_ptr; }
 
    // -> 연산자 오버로딩
    T* operator->() const throw() { return m_ptr; }
 
private:
    // 내부함수 정의
    void dispose() 
    {
        // 카운터를 감소시키고 그 값이 0이면 메모리를 해제
        --(*m_count);
        if (*m_count == 0) 
        {
            delete m_count;
            delete m_ptr;
        }
    }
 
#ifdef __TEST
    // 원래는 인터페이스로 제공되선 안되는 함수지만 테스트를 위해!
public:
    // 카운터 갯수를 얻는 함수
    inline int getCount() { return *m_count; }
#endif
 
    // 맴버 변수
private:
    // 값을 담을 포인터
    T* m_ptr;      
    // 공유하는 숫자
    long* m_count;   
};
