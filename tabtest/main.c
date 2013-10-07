#include "TECADDON.h"
#include "ADDGLBL.h"
#include "GUIDEFS.h"




void STDCALL StateChangeCallback(StateChange_e StateChange, /* IN */
                                 ArbParam_t    CallData)    /* IN */
{

    switch (StateChange)
    {
            /*
             * This function will be called by Tecplot
             * each time a state change occurs.
             *
             *
             * NOTE:
             *
             * By default, when loading a layout or running a macro,
             * you will not receive any state change callbacks until
             * the macro or layout is complete. At that time you will
             * receive the StateChange_CompleteReset message.
             *
             * If you wish to receive state changes AS a macro is run
             * or a layout file is loaded, you must call
             * TecUtilStateChangeSetMode(...). See the ADK reference
             * manual for more information on this function.
             *
             */

            /* State changes which use 'CallData' */

            /* Note: before using the 'CallData' prameter, be sure to
               cast it to the appropriate type ((Set_pa), for example.) */

        case StateChange_VarsAltered:     /* 'CallData' is the set of altered variables (Set_pa type) */
        case StateChange_VarsAdded:       /* 'CallData' is the set of added variables (Set_pa type) */
        case StateChange_ZonesDeleted:    /* 'CallData' is the set of deleted zones (Set_pa type) */
        case StateChange_ZonesAdded:      /* 'CallData' is the set of added zones (Set_pa type) */
        case StateChange_NodeMapsAltered: /* 'CallData' is the set of node maps altered (Set_pa type) */
        case StateChange_MouseModeUpdate: /* 'CallData' is the new mouse mode (MouseButtonMode_e type) */
        case StateChange_Style:           /* 'CallData' is string representing the "P1" parameter */

            /* State changes which do not use 'CallData' */
        case StateChange_FrameDeleted:        /* A frame was delete */
        case StateChange_NewTopFrame:         /* A new frame has become the current frame */
        case StateChange_Text:                /* One or more text elements has changed */
        case StateChange_Geom:                /* One or more geometry elements has changed */
        case StateChange_DataSetReset:        /* A new dataset has been loaded */
        case StateChange_NewLayout:           /* The current layout has been cleared and reset */
        case StateChange_CompleteReset:       /* Anything could have happened */
        case StateChange_XYMapAssignment:/* An X-Y mapping definition has been altered (includes zone and axis information) */
        case StateChange_ContourLevels:       /* The contour levels have been altered */
        case StateChange_ModalDialogLaunch:   /* A modal dialog has been launched */
        case StateChange_ModalDialogDismiss:  /* A modal dialog has been dismissed */
        case StateChange_QuitTecplot:         /* Tecplot is about to exit */
        case StateChange_ZoneName:            /* The name of a zone has been altered */
        case StateChange_VarName:             /* The name of a variable has been altered */
        case StateChange_XYMapName:           /* The name of an X-Y mapping has been altered */
        case StateChange_XYMapAddDeleteOrReorder: /* The set of existing X-Y mappings has been altered */
        case StateChange_View:/* The view of the plot has been altered (usualy a translate, scale, or fit action) */
        case StateChange_ColorMap:            /* The color mapping has been altered */
        case StateChange_ContourVar:          /* The contour variable has been reassigned */
        case StateChange_Streamtrace:/* The set of streamtraces, a termination line, or the streamtrace delta time has been altered */
        case StateChange_NewAxisVariables:    /* The axis variables have been reassigned */
        case StateChange_PickListCleared:     /* All picked objects are unpicked */
        case StateChange_PickListGroupSelect: /* A group of objects has been added to the pick list */
        case StateChange_PickListSingleSelect:/* A single object has been added to or removed from the pick list */
        case StateChange_PickListStyle:       /* An action has been performed on all of the objects in the pick list */
        case StateChange_DataSetFileName:     /* The current data set has been saved to a file */
        case StateChange_DataSetTitle:        /* The current data set title has been changed */
        case StateChange_DataSetLockOn:       /* The dataset attached to the active frome in Tecplot has been locked */
        case StateChange_DataSetLockOff:      /* The dataset attached to the active frome in Tecplot has been unlocked */
        case StateChange_DrawingInterrupted:  /* The user has interrupted the drawing */


            /* Version 9 Note: If you are using modeless dialogs, you should
               trap the following state changes and take appropriate
               action when print preview is launched and dismissed.

               Usually you will either disable or close your dialog
               when print preview is launched. */

        case StateChange_PrintPreviewLaunch:  /* Modeless dialogs should close or disable themselves */
        case StateChange_PrintPreviewDismiss: /* Modeless dialogs can re-launch or enable themselves */


        case StateChange_SuspendInterface:    /* Replaces StateChange_DrawGraphicsOn */
        case StateChange_UnsuspendInterface:  /* Replaces StateChange_DrawGraphicsOff */

        {
            /* TODO: Insert code to handle selected state changes here */
        } break;
        default: break;
    } /* end switch */
}

static void STDCALL TabMenuCallback(void)
{
    TecUtilLockOn();
    BuildDialog1(MAINDIALOGID);
    TecGUIDialogLaunch(Dialog1Manager);
    TecUtilLockOff();
}

static void STDCALL FormMenuCallback(void)
{
    TecUtilLockOn();
    BuildDialog4(MAINDIALOGID);
    TecGUIDialogLaunch(Dialog4Manager);
    TecUtilLockOff();
}

static void STDCALL SpinMenuCallback(void)
{
    TecUtilLockOn();
    BuildDialog9(MAINDIALOGID);
    TecGUIDialogLaunch(Dialog9Manager);
    TecUtilLockOff();
}

static void STDCALL OptionMenuCallback(void)
{
    TecUtilLockOn();
    BuildDialog7(MAINDIALOGID);
    TecGUIDialogLaunch(Dialog7Manager);
    TecUtilLockOff();
}

static void STDCALL DialogButtonMenuCallback(void)
{
    TecUtilLockOn();
    BuildDialog5(MAINDIALOGID);
    TecGUIDialogLaunch(Dialog5Manager);
    TecUtilLockOff();
}
static void STDCALL ScaleTestCallback(void)
{
    TecUtilLockOn();
    BuildDialog8(MAINDIALOGID);
    TecGUIDialogLaunch(Dialog8Manager);
    TecUtilLockOff();
}

/*
 * When Tecplot first loads an add-on, it makes a
 * call to initialize the add-on. This function
 * must be named InitTecAddOn, as shown below.
 */
EXPORTFROMADDON void STDCALL InitTecAddOn(void)
{

    TecUtilLockOn();

    /*
     * The function TecUtilAddOnRegisterInfo() is the
     * only function that is REQUIRED to be called from
     * the initialization function.
     *
     * The information you give Tecplot by calling
     * this function will show up in the Help/About Add-ons
     * dialog box.
     */

    /*
     * Note that if your add-on requires a specific version of Tecplot,
     * you would check for that here using TecUtilGetTecplotVersion()
     */

    TecUtilAddOnRegisterInfo(ADDON_NAME,
                             "V"ADDON_VERSION"("TecVersionId") "ADDON_DATE,
                             "Tecplot, Inc.");

    /*
     * Initialize the Tecplot GUI Builder libraries.
     */
    InitTGB();


    TecUtilStateChangeAddCallback(StateChangeCallback);
    TecUtilMenuAddOption("Tools",
                         "Tab Test",
                         '\0',
                         TabMenuCallback);

    TecUtilMenuAddOption("Tools",
                         "Form Test",
                         '\0',
                         FormMenuCallback);

    TecUtilMenuAddOption("Tools",
                         "Spin Test",
                         '\0',
                         SpinMenuCallback);

    /* These ones may not quite be ready for prime time... */

    /*

    TecUtilMenuAddOption("Tools",
                         "Option Menu Test",
                         '\0',
                         OptionMenuCallback);


    TecUtilMenuAddOption("Tools",
                         "Dialog Button Test",
                         '\0',
                         DialogButtonMenuCallback);

    TecUtilMenuAddOption("Tools",
                         "Scale Control Test",
                         '\0',
                         ScaleTestCallback);
    */

    TecUtilLockOff();
}

