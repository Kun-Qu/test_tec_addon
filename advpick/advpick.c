#include "TECADDON.h"
AddOn_pa AddOnID;

#include "ADDONVER.h"
#include "ADDGLBL.h"
#include "GUIDEFS.h"



static void STDCALL advpickMenuCB(void)
{
    TecUtilLockStart(AddOnID);
    BuildDialog1(MAINDIALOGID);
    TecGUIDialogLaunch(Dialog1Manager);
    TecUtilLockFinish(AddOnID);
}


EXPORTFROMADDON void STDCALL InitTecAddOn(void)
{
    TecUtilLockOn();
    AddOnID = TecUtilAddOnRegister(100, ADDON_NAME, ADDON_VERSION" ("TecVersionId") "ADDON_DATE,
                                   "Tecplot, Inc.");

    if (TecUtilGetTecplotVersion() < MinTecplotVersionAllowed)
    {
        char buffer[256];
        sprintf(buffer, "Add-on \"%s\" requires Tecplot version %s or greater", ADDON_NAME, TecVersionId);
        TecUtilDialogErrMsg(buffer);
    }

    else
    {
        InitTGB();

        TecUtilMenuAddOption("Tools",
                             "Advanced Pick",
                             'A',
                             advpickMenuCB);
    }
    TecUtilLockOff();
}
