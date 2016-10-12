#include "FotileEngine.h"

#define TAG "cooker-fcp-jni"

FotileEngine::FotileEngine()
{
	mCookerProtocol = NULL;
	mCloudProtocl = NULL;
	mTranslator = NULL;
}


FotileEngine::~FotileEngine()
{

}



void FotileEngine::initialize(int cooker)
{
	if (cooker == COOKER_DEVICE_TYPE_STEAMER)
	{
		LOGE("fotile engine init");
		mCookerProtocol = new SteamerProtocol();
		mCloudProtocl = new CloudProtocl();
		mTranslator = new SteamerTranslator();
	}
	else
		return;

	mTranslator->initialize(mCookerProtocol, mCloudProtocl);
	mCookerProtocol->initialize(mTranslator);
	mCloudProtocl->initialize(mTranslator);
//	LOGE("fotile engine init end");
}


void FotileEngine::deinitialize()
{
	if (mCloudProtocl)
	{
		mCloudProtocl->deinitialize();
		delete mCloudProtocl;
	}

	if (mCookerProtocol)
	{
		mCookerProtocol->deinitialize();
		delete mCloudProtocl;
	}

	if (mTranslator)
	{
		mTranslator->deinitialize();
		delete mTranslator;
	}
}


FotileEngine gFotileEngine;


