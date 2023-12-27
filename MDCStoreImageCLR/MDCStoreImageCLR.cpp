#include "pch.h"

#include "MDCStoreImageCLR.h"
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;

using namespace MDCStoreImageCLR;

// The one and only application object

MDCStoreImageWrapper::MDCStoreImageWrapper()
{
	LibObj = new MDCStoreImageLibrary();
}

extern "C" bool MDCStoreImageWrapper::CLR_MDCStoreUtils_Init()
{
	if (LibObj->Lib_MDCStoreUtils_Init())
	{
		return true;
	}
	else
	{
		return false;
	}
}

extern "C" bool MDCStoreImageWrapper::CLR_UserLogin(String^ UserName, String^ Password, String^ DSN, String^ DBName)
{
	msclr::interop::marshal_context context;
	std::string strUserName = context.marshal_as<std::string>(UserName);
	std::string strPassword = context.marshal_as<std::string>(Password);
	std::string strDSN = context.marshal_as<std::string>(DSN);
	std::string strDBName = context.marshal_as<std::string>(DBName);

	if (LibObj->Lib_UserLogin(strUserName, strPassword, strDSN, strDBName))
	{
		return true;
	}
	else
	{
		return false;
	}
}

extern "C" bool MDCStoreImageWrapper::CLR_GetImage(int lPlateID)
{
	if (LibObj->Lib_GetImage(lPlateID))
	{
		return true;
	}
	else
	{
		return false;
	}

}

extern "C" List<MyMDCS_ST_PlateInfo^>^ MDCStoreImageWrapper::CLR_GetPlateInfo(int lPlateID)
{
	vector<MDCS_ST_PlateInfo> vst_PlateInfo;
	LibObj->Lib_GetPlateInfo(lPlateID, vst_PlateInfo);

	List<MyMDCS_ST_PlateInfo^>^ cs_v = gcnew List<MyMDCS_ST_PlateInfo^>();
	for (size_t i = 0; i < vst_PlateInfo.size(); i++)
	{
		MyMDCS_ST_PlateInfo^ p = gcnew MyMDCS_ST_PlateInfo();
		p->lPlateID			= vst_PlateInfo[i].lPlateID;
		p->lAcqID			= vst_PlateInfo[i].lAcqID;
		p->lCreatorID		= vst_PlateInfo[i].lCreatorID;		
		p->tTimeCreated		= vst_PlateInfo[i].tTimeCreated;	
		p->tTimeAnnotated	= vst_PlateInfo[i].tTimeAnnotated;	
		p->tTimeModified	= vst_PlateInfo[i].tTimeModified;	
		p->lAnnotatedBy		= vst_PlateInfo[i].lAnnotatedBy;	
		p->lModifierID		= vst_PlateInfo[i].lModifierID;		
		p->nXWells			= vst_PlateInfo[i].nXWells;			
		p->nYWells			= vst_PlateInfo[i].nYWells;		

		p->szPlateName		= gcnew System::String(vst_PlateInfo[i].szPlateName);
		p->szCreator		= gcnew System::String(vst_PlateInfo[i].szCreator);
		p->szBarcode		= gcnew System::String(vst_PlateInfo[i].szBarcode);
		p->szAcqName		= gcnew System::String(vst_PlateInfo[i].szAcqName);
		p->szGlobalID		= gcnew System::String(vst_PlateInfo[i].szGlobalID);
		p->szDesc			= gcnew System::String(vst_PlateInfo[i].szDesc);

		cs_v->Add(p);
	}

	return cs_v;
}