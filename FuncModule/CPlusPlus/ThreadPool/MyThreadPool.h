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
	
	CMyStack m_IdleThreadStack;//Stack�Ǻ���ȳ��Ľṹ��Idel�߳�����ν��һ���������ó��Ϳ�
	CMyList m_ActiveThreadList;//List�Ƿ���ɾ���Ľṹ��Active�߳���ͬʱ���еģ�����֪�ĸ��߳������н���������Ҫ�����Ƴ�����List�������
	CMyQueue m_TaskQueue;//queue��deque��˳��ṹ���Ƚ��ȳ�������������ȼ�����ͬ�ģ���ʹ��queue��������������ȼ�����ʹ��deque��������������ȼ�����ʹ��multimap
};
template class Singleton<CMyThreadPool>;
#define THREADPOOL_MGR Singleton<CMyThreadPool>::GetInstance()
