#include "StdAfx.h"
#include "FuncTask.h"
CFuncask::CFuncask(int id)
	:CTask(id)
{
}
CFuncask::~CFuncask(void)
{
}

void CFuncask::SetTaskFunc(std::function<BOOL()> func){
    m_fun = func;
}

void CFuncask::taskProc()
{
	//ִ��������
    m_fun();
}
