#pragma once

#include "resource.h"
#include <iostream>
#include <string>
#include <vector>

#include "MDCStoreImageLib.h"
#include "MDCStoreUtilsApi.h"

using namespace std;
extern "C"
{
	class __declspec(dllexport) MDCStoreImageLibrary
	{
	private:
		MDCS_ST_UserLogin m_uLoging;
		MDCS_DBHandleSmartPtr* ptrDB;
	public:
		MDCStoreImageLibrary();
		~MDCStoreImageLibrary();
		bool Lib_MDCStoreUtils_Init();
		bool Lib_UserLogin(std::string, std::string, std::string, std::string);
		bool Lib_GetImage(int);
		void Lib_GetPlateInfo(int lPlateID, vector<MDCS_ST_PlateInfo>& vst_PlateInfo);
	};
}