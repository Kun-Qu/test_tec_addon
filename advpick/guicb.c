#include "TECADDON.h"


#include "ADDGLBL.h"
#if !defined (MSWIN)
#include <unistd.h>
#endif
#include "GUIDEFS.h"



static Boolean_t MatchZone = FALSE;
static Boolean_t MatchColor = FALSE;



static void Dialog1HelpButton_CB(void)
{
    TecUtilLockStart(AddOnID);
    TecUtilDialogMessageBox("On-line Help not available for this dialog.",
                            MessageBox_Information);
    TecUtilLockFinish(AddOnID);
}




static void Dialog1CloseButton_CB(void)
{
    TecUtilLockStart(AddOnID);
    TecGUIDialogDrop(Dialog1Manager);
    TecUtilLockFinish(AddOnID);
}




static void Dialog1Init_CB(void)
{
    TecUtilLockStart(AddOnID);
    /*<<< Add init code (if necessary) here>>>*/
    TecUtilLockFinish(AddOnID);
}




static void SelectMatchi_BTN_D1_CB(void)
{
    int           NumPicks;
    TecUtilLockStart(AddOnID);
    NumPicks = TecUtilPickListGetCount();


    if (NumPicks > 0)
    {
        ColorIndex_t MasterColor = -1;
        EntIndex_t   MasterZone = -1;
        Geom_ID      MasterGeom = TECUTILBADID;
        Text_ID      MasterText = TECUTILBADID;
        int P;

        /*
         * Determine attributes of currently picked (master) text and geometry objects.
         */
        for (P = 1; (P <= NumPicks) && (MasterGeom == TECUTILBADID) && (MasterText == TECUTILBADID); P++)
        {
            if (TecUtilPickListGetType(P) == PickObject_Geom)
            {
                MasterGeom  = TecUtilPickListGetGeom(P);
                MasterColor = TecUtilGeomGetColor(MasterGeom);
                if (TecUtilGeomIsAttached(MasterGeom))
                    MasterZone  = TecUtilGeomGetZoneOrMap(MasterGeom);
            }
            else if (TecUtilPickListGetType(P) == PickObject_Text)
            {
                MasterText  = TecUtilPickListGetText(P);
                MasterColor = TecUtilTextGetColor(MasterText);
                if (TecUtilTextIsAttached(MasterText))
                    MasterZone  = TecUtilTextGetZoneOrMap(MasterText);
            }
        }
        /*
         * Pick all (text and geometry) objects that have attributes matching
         * the master objects. If the master object is not attached to a zone,
         * pick those objects that are also not attached to a zone.
         */
        if ((MasterGeom != TECUTILBADID) ||
            (MasterText != TECUTILBADID))
        {
            Text_ID    CurText;
            Geom_ID    CurGeom;
            Boolean_t  IsOk = TRUE;

            CurText = TecUtilTextGetBase();

            while (IsOk && CurText)
            {
                EntIndex_t AttachedZone = -1;
                if (TecUtilTextIsAttached(CurText))
                    AttachedZone = TecUtilTextGetZoneOrMap(CurText);
                if ((!MatchZone || (AttachedZone == MasterZone)) &&
                    (!MatchColor || (TecUtilTextGetColor(CurText) == MasterColor)))
                    IsOk = TecUtilPickText(CurText);
                CurText = TecUtilTextGetNext(CurText);
            }


            CurGeom = TecUtilGeomGetBase();
            while (IsOk && CurGeom)
            {
                EntIndex_t AttachedZone = -1;
                if (TecUtilGeomIsAttached(CurGeom))
                    AttachedZone = TecUtilGeomGetZoneOrMap(CurGeom);
                if ((!MatchZone || (AttachedZone == MasterZone)) &&
                    (!MatchColor || (TecUtilGeomGetColor(CurGeom) == MasterColor)))
                    IsOk = TecUtilPickGeom(CurGeom);
                CurGeom = TecUtilGeomGetNext(CurGeom);
            }
        }
    }
    TecUtilLockFinish(AddOnID);
}





static void ZoneAttachme_TOG_D1_CB(const int *I)
{
    TecUtilLockStart(AddOnID);
    MatchZone = (Boolean_t)(*I == 1);
    TecUtilLockFinish(AddOnID);
}




static void Color_TOG_D1_CB(const int *I)
{
    TecUtilLockStart(AddOnID);
    MatchColor = (Boolean_t)(*I == 1);
    TecUtilLockFinish(AddOnID);
}





#include "guibld.c"
