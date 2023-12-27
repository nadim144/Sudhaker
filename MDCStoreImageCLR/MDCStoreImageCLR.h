#pragma once
#include "targetver.h"
#include <afx.h>
#include <afxwin.h>         // MFC core and standard components

#include <iostream>
#include <WTypesbase.h>
#include "MDCStoreUtilsApi.h"
#include "MDCStoreImageLib.h"


using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;

using namespace std;

extern "C"
{
	namespace MDCStoreImageCLR
	{
		public ref struct  MyMDCS_ST_PlateInfo
		{
			LONGLONG          lPlateID;                              //plate ID
			LONGLONG          lAcqID;                                //ID of acquisition when plate was acquired
			LONGLONG          lCreatorID;                            //id of the user who created user [out only] 
			time_t            tTimeCreated;                          //time when plate was created [out only] 
			time_t            tTimeAnnotated;                        //time when plate was annotated [out only] 
			time_t            tTimeModified;                         //time when plate was modified[out only] 
			LONGLONG          lAnnotatedBy;                          //id of the user who annotated plate [out only] 
			LONGLONG          lModifierID;                              //id of the user who annotated plate [out only] 
			int               nXWells;                               //number of X wells in plate
			int               nYWells;                               //number of Y wells in plate

			System::String^ szPlateName;	//plate name 
			System::String^ szCreator;      //name of the user who created record [out only] 
			System::String^ szBarcode;      //barcode
			System::String^ szAcqName;      //name of an acquisition that was used to acquire plate
			System::String^ szGlobalID;     //plate's global ID
			System::String^ szDesc;         //plate description

			//MDCS_ST_PlateInfo()
			//{
			//	memset(this, 0, sizeof(*this));
			//};
		};


		public ref class MDCStoreImageWrapper
		{
		private:
			MDCStoreImageLibrary* LibObj;
		public:
			MDCStoreImageWrapper();				// Constructor
			bool CLR_MDCStoreUtils_Init();
			bool CLR_UserLogin(String^ UserName, String^ Password, String^ DSN, String^ DBName);
			bool CLR_GetImage(int lPlateID);
			List<MyMDCS_ST_PlateInfo^>^ CLR_GetPlateInfo(int lPlateID);
		};
	}
}