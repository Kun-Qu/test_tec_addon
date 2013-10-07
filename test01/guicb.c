#include "TECADDON.h"
#include "ADDGLBL.h"
#include "GUIDEFS.h"



/**
 */
static void Dialog1Init_CB(void)
{
    /* TODO: Add any initialization here. */
}

/**
 */
static void Dialog1CloseButton_CB(void)
{
    TecGUIDialogDrop(Dialog1Manager);
}

/**
 */
static void Dialog1HelpButton_CB(void)
{
    TecUtilLockStart(AddOnID);
    TecUtilDialogMessageBox("On-line Help not available for this dialog.",
                            MessageBox_Information);
    TecUtilLockFinish(AddOnID);
}


#include "guibld.c"

