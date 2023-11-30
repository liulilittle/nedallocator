#include "stdafx.h"
#include "windows.h"
#include <string>

#include "NedAllocatedObject.h"

class TestMemObj1
{
public:
	TestMemObj1()
	{
       // printf("TestMemObj1\n ");
	}
	~TestMemObj1()
	{
        //printf("~TestMemObj1\n");
	}
	
protected:
	int a;
	char b;
	unsigned long c;

};

class TestMemObj2 : public NedAllocatedObject
{
public:
	TestMemObj2()
	  {
         // printf("TestMemObj2\n ");
	  }
	  ~TestMemObj2()
	  {
          //printf("~TestMemObj2\n");
	  }

protected:
	int a;
	char b;
	unsigned long c;
};

DWORD WINAPI ThreadProc( LPVOID lpParam ) 
{ 
    DWORD t1, t2;

    t1 = GetTickCount();
   	for(int i = 0; i < 80000000; i++)
	{
// 		TestMemObj2* obj = new TestMemObj2;
// 		delete obj;
        int *p = (int*)MemoryMalloc(sizeof(int));
       // printf("%x\n",p);
        MemoryFree(p);
	}
     t2 = GetTickCount();
     printf("thread使用NedAllocator,耗时 %d 毫秒\n", t2-t1);
    return 0; 
} 

int _tmain(int argc, _TCHAR* argv[])
{
	//getchar();
	DWORD t1, t2;

	t1 = GetTickCount();
	for(int i = 0; i < 8000000; i++)
	{
		TestMemObj1* obj = new TestMemObj1;
		delete obj;

//         int *p = (int*)malloc(sizeof(int));
//         free(p);
	}
	t2 = GetTickCount();
	printf("未使用NedAllocator,耗时 %d 毫秒\n", t2-t1);
	
	t1 = GetTickCount();
	for(int i = 0; i < 8000000; i++)
	{
		TestMemObj2* obj = new TestMemObj2;
		delete obj;
//         int *p = (int*)MemoryMalloc(sizeof(int));
//         MemoryFree(p);
	}
	t2 = GetTickCount();
	printf("使用NedAllocator,耗时 %d 毫秒\n", t2-t1);	
    system("pause");
    CreateThread( NULL,0,ThreadProc,NULL,0,NULL);  
    CreateThread( NULL,0,ThreadProc,NULL,0,NULL);  

	getchar();
    getchar();
	return 0;
}

