// MDCStoreImageLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "MDCStoreImageLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// The one and only application object
CWinApp theApp;

MDCStoreImageLibrary::MDCStoreImageLibrary() : m_DBHandle(nullptr)
{
	// Default Constructor
}

extern "C" bool MDCStoreImageLibrary::Lib_MDCStoreUtils_Init()
{
	if (MDCStoreUtils_Init())
	{
		return true;
	}
	else
	{
		return false;
	}
}

extern "C" bool MDCStoreImageLibrary::Lib_UserLogin(string UserName, string Password, string DSN, string DBName)
{
	strncpy_s(m_uLoging.szUserName, UserName.c_str(), min(sizeof(m_uLoging.szUserName) - 1, strlen(UserName.c_str())));
	strncpy_s(m_uLoging.szPassword, Password.c_str(), min(sizeof(m_uLoging.szUserName) - 1, strlen(Password.c_str())));
	strncpy_s(m_uLoging.szDSN, DSN.c_str(), min(sizeof(m_uLoging.szUserName) - 1, strlen(DSN.c_str())));
	strncpy_s(m_uLoging.szDatabase, DBName.c_str(), min(sizeof(m_uLoging.szUserName) - 1, strlen(DBName.c_str())));

	//get database handle 
	MDCS_DBHandleSmartPtr ptrDB(m_uLoging);
	if (ptrDB.GetHandle())
	{
		m_DBHandle = ptrDB.GetHandle();
		return true;
	}
	else
	{
		return false;
	}
}

extern "C" bool MDCStoreImageLibrary::Lib_GetImage(int PlateId)
{
	///* 1. MDCS_PLATE_GetSitesByPlate() API*/
	////Get all sites belonging to the plate
	////======================================
	//CArray<LONGLONG, LONGLONG> larrSiteIDs;
	//MDCS_PLATE_GetSitesByPlate_CallBack pResultSites(&larrSiteIDs);
	//if (!MDCS_PLATE_GetSitesByPlate(m_DBHandle, PlateId, &pResultSites))
	//{
	//	return FALSE;
	//}

	///* 1. MDCS_PLATE_GetSitesByPlate() API*/
	////Get all sites belonging to the plate
	////======================================
	//CArray<LONGLONG, LONGLONG> assayIDs;
	//CArray<LPCSTR, LPCSTR> assayNames;
	//CArray<LPCSTR, LPCSTR> assayDescriptions;
	//CArray<LPCSTR, LPCSTR> createdbys;

	////MDCS_ASSAY_GetAllForPlate_CallBack pResult(&assayPlateLis);
	//MDCS_ASSAY_GetAllForPlate_CallBack pResult(&assayIDs, &assayNames, &assayDescriptions, &createdbys);
	//if (MDCS_ASSAY_GetAllForPlate(m_DBHandle, PlateId, &pResult))
	//{
	//	cout << "MDCS_ASSAY_GetAllForPlate() API call Succesful .." << endl;
	//	cout << "assayIDs[0] = " << assayIDs[0] << endl;
	//}
	return true;
}

extern "C" void MDCStoreImageLibrary::Lib_GetPlateInfo(int lPlateID, vector<MDCS_ST_PlateInfo>& vec_st_PlateInfo)
{
	MDCS_ST_PlateInfo st_PlateInfo;
	MDCS_PLATE_GetInfo(m_DBHandle, lPlateID, st_PlateInfo);

	//Dummy data for testing
	st_PlateInfo.lPlateID = 10;
	st_PlateInfo.lAcqID = 20;
	st_PlateInfo.lCreatorID = 30;
	st_PlateInfo.tTimeCreated = 40;
	st_PlateInfo.tTimeAnnotated = 50;
	st_PlateInfo.tTimeModified = 60;
	st_PlateInfo.lAnnotatedBy = 70;
	st_PlateInfo.lModifierID = 80;
	st_PlateInfo.nXWells = 90;
	st_PlateInfo.nYWells = 100;

	strncpy_s(st_PlateInfo.szPlateName, "Sudhakar", min(sizeof(st_PlateInfo.szPlateName) - 1, strlen("Sudhakar")));
	strncpy_s(st_PlateInfo.szCreator, "Kumar", min(sizeof(st_PlateInfo.szCreator) - 1, strlen("Kumar")));
	strncpy_s(st_PlateInfo.szBarcode, "Nadim", min(sizeof(st_PlateInfo.szBarcode) - 1, strlen("Nadim")));
	strncpy_s(st_PlateInfo.szAcqName, "Ahmad", min(sizeof(st_PlateInfo.szAcqName) - 1, strlen("Ahmad")));
	strncpy_s(st_PlateInfo.szGlobalID, "GUID", min(sizeof(st_PlateInfo.szGlobalID) - 1, strlen("GUID")));
	strncpy_s(st_PlateInfo.szDesc, "This dummy data to test", min(sizeof(st_PlateInfo.szDesc) - 1, strlen("This dummy data to test")));

	vec_st_PlateInfo.push_back(st_PlateInfo);
}


