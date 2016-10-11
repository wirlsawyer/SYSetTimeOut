
#include <string>
//http://www.cppblog.com/prayer/archive/2008/08/18/59253.html
#include <signal.h>     /* signal */
#include <setjmp.h>  

static sigjmp_buf jmpbuf;  

static void alarm_func()  
{  
	siglongjmp(jmpbuf, 1);  
}  

static std::wstring TestWithTimeout(const wchar_t *domain, int timeout)  
{  
	struct hostent *ipHostent = NULL;  
	signal(SIGALRM, alarm_func);  
	if(sigsetjmp(jmpbuf, 1) != 0)  
	{  
		SIGTERM

		alarm(0);//timout  
		signal(SIGALRM, SIG_IGN);  
		return L"Timeout.";  
	} 
	
	alarm(timeout);//setting alarm  
	
	while(true)
	{
		OutputDebugString(domain);
		OutputDebugString(L"\n");
		Sleep(1000);
	}

	signal(SIGALRM, SIG_IGN);  
	return L"Finish.";  
}  