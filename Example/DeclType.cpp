#include "stdafx.h"
#include <deque>
#include <vector>
#include <iostream>

class Widget {
public:
    int value;
};

/* 
    template<class Container, class Index>
    auto authAndAccess(Container& c, Index i)
    {
        // authenticateUser();
        return c[i];
    }
    // authAndAccess(intDq, 5) = 10; // error
    // �ɰ���	�ڵ�	����	������Ʈ	����	��	��ǥ�� ����(Suppression) ����
    // ����	C2106	'=': ���� �ǿ����ڴ� l-value�̾�� �մϴ�.	Test	c:\users\jo minhyuk\documents\visual studio 2015\projects\test\test\test.cpp	39	
*/


//template<class Container, class Index>
//decltype(auto) authAndAccess(Container& c, Index i)
//{
//    // authenticateUser();
//    return c[i];
//}

// finally c++14
template<class Container, class Index>
decltype(auto) authAndAccess(Container&& c, Index i)
{
    // authenticateUser();
    return std::forward<Container>(c)[i];
}

//// finally c++11
//template<class Container, class Index>
//auto authAndAccess(Container&& c, Index i) -> decltype(std::forward<Container>(c)[i])
//{
//    // authenticateUser();
//    return std::forward<Container>(c)[i];
//}

std::deque<int> makeIntDque()
{
    std::deque<int> dq;
    dq.resize(10);

    static int i = 1000;
    for (auto& value : dq) {
        value = i++;
    }

    return dq;
}

int main()
{
    Widget w;

    const Widget& cw = w;

    auto myWidget1 = cw; // auto. type : Widget
    
    decltype(auto) myWidget2 = cw; // decltype. type : const Widget&
    
    myWidget1.value = 1;
    // myWidget2.value = 2;
    /*
        compile error
        �ɰ���	�ڵ�	����	������Ʈ	����	��	��ǥ�� ����(Suppression) ����
        ����	C2018	'0x60' ���ڸ� �ν��� �� �����ϴ�.	Test	c:\users\jo minhyuk\documents\visual studio 2015\projects\test\test\test.cpp	18
        ����	C3490	'value'��(��) const ��ü�� ���� �׼����ǰ� �����Ƿ� ������ �� �����ϴ�.	Test	c:\users\jo minhyuk\documents\visual studio 2015\projects\test\test\test.cpp	22
    */

    std::deque<int> intDq;
    intDq.resize(10);

    authAndAccess(intDq, 5) = 10;
    std::cout << intDq.at(5) << std::endl;;

    std::vector<Widget> widgetVec;
    widgetVec.resize(10);

    authAndAccess(widgetVec, 5).value = 20;
    std::cout << widgetVec.at(5).value << std::endl;

    auto copyValue = authAndAccess(intDq, 5);
    std::cout << copyValue << std::endl;

    auto copyWidget = authAndAccess(widgetVec, 5);
    std::cout << copyWidget.value << std::endl;
    
    auto copyFuncRtValue = authAndAccess(makeIntDque(), 5);
    std::cout << copyFuncRtValue << std::endl;

    return 0;
}

