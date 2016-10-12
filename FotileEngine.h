#ifndef _FOTILE_ENGINE_H
#define _FOTILE_ENGINE_H

#ifdef WIN32
#include <Windows.h>
#else
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <semaphore.h>

typedef int BOOL;
typedef unsigned long DWORD;
#define FALSE 0
#define TRUE  1
#endif
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <malloc.h>
#include <android/log.h>
#include <stdio.h>
#include <string.h>
#include "RingBuffer.h"
#include "SemaphoreEx.h"
#include "Thread.h"
#include "List.h"
#include "SerialPort.h"
#include "CookerProtocol.h"
#include "SteamerProtocol.h"
#include "CloudProtocol.h"
#include "Translator.h"
#include "SteamerTranslator.h"

#include <pthread.h>
//#include <linux/mutex.h>
//using namespace std;

#define _ASSERT(x)


#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__))


enum tagCOOKER_DEVICE_TYPE
{
	COOKER_DEVICE_TYPE_STEAMER = 0,
	COOKER_DEVICE_TYPE_OVEN = 1,
};

class FotileEngine
{
public:
	FotileEngine();
	~FotileEngine();

public:
	void initialize(int cooker);
	void deinitialize();

public:
	CookerProtocol*  mCookerProtocol;
	CloudProtocl* mCloudProtocl;
	Translator*   mTranslator;
};

extern FotileEngine gFotileEngine;

#endif
