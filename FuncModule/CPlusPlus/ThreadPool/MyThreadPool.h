#pragma once
#include<list>
#include "MyMutex.h"
#include "MyStack.h"
#include "MyList.h"
#include"MyQueue.h"
#include "Singleton.h"
class CMyThread;
class CTask;
enum PRIORITY
{
	NORMAL,
	HIGH
};
class CBaseThreadPool
{
public:
	virtual bool SwitchActiveThread(CMyThread*)=0;
};
class CMyThreadPool:public CBaseThreadPool
{
public:
	CMyThreadPool(int num=5);//�̳߳����߳�����
	~CMyThreadPool(void);
public:
	virtual CMyThread* PopIdleThread();
	virtual bool SwitchActiveThread(CMyThread*);
	virtual CTask*GetNewTask();
public:
	//priorityΪ���ȼ��������ȼ������񽫱����뵽���ס�
    bool addTask(const std::function<BOOL()>& fun,PRIORITY priority,int id=-1);
	bool addTask(CTask*t,PRIORITY priority);
    bool removeTask(int id);
	bool start();//��ʼ���ȡ�
	bool destroyThreadPool();
    bool clearThreadPool();

private:
	int m_nThreadNum;
	bool m_bIsExit;
	
	CMyStack m_IdleThreadStack;
	CMyList m_ActiveThreadList;
	CMyQueue m_TaskQueue;
};
template class Singleton<CMyThreadPool>;
#define THREADPOOL_MGR Singleton<CMyThreadPool>::GetInstance()
