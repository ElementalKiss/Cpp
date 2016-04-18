#pragma once 
// test comment
 
// counted_ptr
template <class T>
class counted_ptr 
{
public:
    // �����͸� �̿��� �ʱ�ȭ new�� ���� �ʱ�ȭ�Ѵ�.
    explicit counted_ptr (T* p = 0) : m_ptr(p), m_count(new long(1)) { }
 
    // ���� ������
    counted_ptr (const counted_ptr<T>& p) throw() : m_ptr(p.m_ptr), m_count(p.m_count)
    {
        // ī���� ����
        (*m_count)++;
    }
 
    // �Ҹ���
    ~counted_ptr () throw() { dispose(); }
 
    // ���� ������ �����ε�
    counted_ptr<T>& operator= (const counted_ptr<T>& p) throw() 
    {
        // �ڽ��� ��츦 �����ؾ��ϹǷ� 
        if (this != &p) 
        {
            dispose();
            m_ptr = p.m_ptr;
            m_count = p.m_count;
            (*m_count)++;
        }
        return *this;
    }
 
    // * ������ �����ε�
    T& operator*() const throw() { return *m_ptr; }
 
    // -> ������ �����ε�
    T* operator->() const throw() { return m_ptr; }
 
private:
    // �����Լ� ����
    void dispose() 
    {
        // ī���͸� ���ҽ�Ű�� �� ���� 0�̸� �޸𸮸� ����
        --(*m_count);
        if (*m_count == 0) 
        {
            delete m_count;
            delete m_ptr;
        }
    }
 
#ifdef __TEST
    // ������ �������̽��� �����Ǽ� �ȵǴ� �Լ����� �׽�Ʈ�� ����!
public:
    // ī���� ������ ��� �Լ�
    inline int getCount() { return *m_count; }
#endif
 
    // �ɹ� ����
private:
    // ���� ���� ������
    T* m_ptr;      
    // �����ϴ� ����
    long* m_count;   
};
