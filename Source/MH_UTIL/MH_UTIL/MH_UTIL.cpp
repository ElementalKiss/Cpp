// MH_UTIL.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"
#include "MH_UTIL.h"

void MH_UTIL::ETC::some_line()
{
	cout << "==============================" << endl;
}

void MH_UTIL::ETC::some_line(const string msg)
{
	cout << "==========[" << msg << "]==========" << endl;
}
