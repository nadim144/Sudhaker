//#pragma once
////******************************************************************************
////   
//// Copyright (c) 2005 Molecular Devices
//// All rights reserved.
////******************************************************************************
//// Module:  GetSitesByPlate_CallBack.h
//// Purpose: Provide functions to process data and get all Site IDs belonging to a plate
////  
///////////////////////////////////////////////////////////////////////////////////
//
//#pragma once
//#include "mdcstoreutilsapi.h"
//#include <afxtempl.h>
//
//class CGetAllForPlate_CallBack :
//    public MDCS_GetDBResultsCCallback
//{
//public:
//    CGetAllForPlate_CallBack(CArray<LONGLONG, LONGLONG>* m_plarrAssayID,
//        CArray<LPCSTR, LPCSTR>* m_plarrAssayName,
//        CArray<LPCSTR, LPCSTR>* m_plarrAssayDescription,
//        CArray<LPCSTR, LPCSTR>* m_plarrcreatedby);
//
//    virtual ~CGetAllForPlate_CallBack(void) {}
//
//    //called to get next row of data
//    virtual BOOL GetNextResult(MDCS_QueryResults* pQueryRes);
//
//    //called to get number of results
//    virtual void SetResultNumber(LONGLONG nCount)
//    {};
//
//    //called when there is an error 
//    virtual void Error(LPCSTR pErrorText)
//    {
//        return;
//    }
//
//    //called when completely done
//    virtual void Done()
//    {
//        return;
//    }
//
//    //called by functions to check if results should be returned in their original format
//    virtual BOOL ProcessResultsInOriginalFormat() const
//    {
//        return TRUE;
//    }
//
//    //called to get info about results structure (field names and types)
//    //all fields  will be empty
//    virtual BOOL GetResultInfo(MDCS_QueryResults* pQueryRes) { return TRUE; };
//
//
//private:
//    // hide the default copy constructors
//    CGetAllForPlate_CallBack(MDCS_GetDBResultsCCallback const&);
//    const CGetAllForPlate_CallBack& operator=(MDCS_GetDBResultsCCallback const&);
//
//    //pointer to array of site ID 
//    CArray<LONGLONG, LONGLONG>* m_plarrAssayID;
//    CArray<LPCSTR, LPCSTR>* m_plarrAssayName;
//    CArray<LPCSTR, LPCSTR>* m_plarrAssayDescription;
//    CArray<LPCSTR, LPCSTR>* m_plarrcreatedby;
//
//
//};
