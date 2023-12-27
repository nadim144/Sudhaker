using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MDCStoreImageCLR;



namespace MDCStoreImageApp
{
    class Program
    {
        static void Main(string[] args)
        {
            List<MyMDCS_ST_PlateInfo> obj_MyMDCS_ST_PlateInfo;
            MDCStoreImageWrapper objMCDStoreImgWrp = new MDCStoreImageWrapper();           
            if(objMCDStoreImgWrp.CLR_MDCStoreUtils_Init())
            {
                Console.WriteLine("MDCStoreUtils_Init() API Sucessfully called ..");
            }           

            MDCS_ST_UserLogin loginInfo = new MDCS_ST_UserLogin
            {
                szUserName = "MDCadmin",
                szPassword = "Software1!",
                szDSN = "DB_ImagExpress", 
                szDatabase = "MDCStore"
            };

            objMCDStoreImgWrp.CLR_UserLogin(loginInfo.szUserName, loginInfo.szPassword, loginInfo.szDSN, loginInfo.szDatabase);
            objMCDStoreImgWrp.CLR_GetImage(536);
            obj_MyMDCS_ST_PlateInfo = objMCDStoreImgWrp.CLR_GetPlateInfo(536);
        }
    }
}
