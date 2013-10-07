#include "TECADDON.h"
#include "ADDGLBL.h"
#include "GUIDEFS.h"

static int ApplyButton = 0;

static void Clear_BTN_D1_CB(void)
{
    TecUtilLockOn();
    TecGUITextSetString(Message_T_D1, "");
    TecUtilLockOff();
}


static void Clear_BTN_D4_CB(void)
{
    TecUtilLockOn();
    TecGUITextSetString(Message_T_D4, "");
    TecUtilLockOff();
}

static void Apples_TOG_T1_1_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Toggle Value Changed,  New value is: %d\n", *I);
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}




static void Oranges_TOG_T1_1_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Toggle Value Changed,  New value is: %d\n", *I);
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}




static void Apples_BTN_T2_1_CB(void)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Apples Button Pushed\n");
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}




static void Oranges_BTN_T2_1_CB(void)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Oranges Button Pushed\n");
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}




static void AppleOrang_RADIO_T3_1_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "RadioBox Value Changed,  New value is: %d\n", *I);
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}



char *AppleOrange_OPT_T1_2_List = "Cowabunga!,Doh!";


static void AppleOrange_OPT_T1_2_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Option Menu value changed,  New value is: %d\n", *I);
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}




static void AppleOrange_SLST_T2_2_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Single selection list item selected,  Item is: %d\n", *I);
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}




static void Apples_TOG_F1_3_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Toggle Value Changed,  New value is: %d\n", *I);
    TecGUITextAppendString(Message_T_D4, buffer);
    TecUtilLockOff();
}




static void Oranges_TOG_F1_3_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Toggle Value Changed,  New value is: %d\n", *I);
    TecGUITextAppendString(Message_T_D4, buffer);
    TecUtilLockOff();
}




static void Apples_BTN_F2_3_CB(void)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Apples Button Pushed\n");
    TecGUITextAppendString(Message_T_D4, buffer);
    TecUtilLockOff();
}




static void Oranges_BTN_F2_3_CB(void)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Oranges Button Pushed\n");
    TecGUITextAppendString(Message_T_D4, buffer);
    TecUtilLockOff();
}




static void AppleOrang_RADIO_F3_3_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "RadioBox (AppleOrang_RADIO_F3_3) Value Changed,  New value is: %d\n", *I);
    TecGUITextAppendString(Message_T_D4, buffer);
    TecUtilLockOff();
}



char *AppleOrange_OPT_F1_4_List = "Doh!,Cowabunga!";




static void AppleOrange_OPT_F1_4_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Option Menu value changed,  New value is: %d\n", *I);
    TecGUITextAppendString(Message_T_D4, buffer);
    TecUtilLockOff();
}


static void AppleOrange_SLST_F2_4_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "Single selection list item selected,  Item is: %d\n", *I);
    TecGUITextAppendString(Message_T_D4, buffer);
    TecUtilLockOff();
}


static void Dialog9HelpButton_CB(void)
{
    TecUtilLockOn();
    TecUtilDialogMessageBox("On-line Help not available for this dialog.",
                            MessageBox_Information);
    TecUtilLockOff();
}




static void Dialog9CloseButton_CB(void)
{
    TecUtilLockOn();
    TecGUIDialogDrop(Dialog9Manager);
    TecUtilLockOff();
}




static void Dialog9Init_CB(void)
{
    TecUtilLockOn();
    TecGUITextFieldSetString(TestSpin_TFS_D9, "1");
    TecUtilLockOff();
}




static int  TestSpin_TFS_D9_ValueChanged_CB(const char *S)
{
    int IsOk = 1;
    int n;
    TecUtilLockOn();
    n = atoi(S);
    if (n < 1 || n > 100)
    {
        TecUtilDialogErrMsg("Please enter a number from 1 - 100");
        IsOk = 0;
        TecGUITextFieldSetString(TestSpin_TFS_D9, "1");
    }
    TecUtilLockOff();
    return (IsOk);
}




static void TestSpin_TFS_D9_ButtonUp_CB(void)
{
    int n;
    char *Str;
    TecUtilLockOn();

    Str = TecGUITextFieldGetString(TestSpin_TFS_D9);
    n = atoi(Str);
    if (n < 100)
    {
        char buffer[32];
        sprintf(buffer, "%d", n + 1);
        TecGUITextFieldSetString(TestSpin_TFS_D9, buffer);
    }

    TecUtilStringDealloc(&Str);

    TecUtilLockOff();
}




static void TestSpin_TFS_D9_ButtonDown_CB(void)
{
    int n;
    char *Str;
    TecUtilLockOn();

    Str = TecGUITextFieldGetString(TestSpin_TFS_D9);
    n = atoi(Str);
    if (n > 1)
    {
        char buffer[32];
        sprintf(buffer, "%d", n - 1);
        TecGUITextFieldSetString(TestSpin_TFS_D9, buffer);
    }

    TecUtilStringDealloc(&Str);

    TecUtilLockOff();
}




static void Dialog6HelpButton_CB(void)
{
    TecUtilLockOn();
    TecUtilDialogMessageBox("On-line Help not available for this dialog.",
                            MessageBox_Information);
    TecUtilLockOff();
}




static void Dialog6CloseButton_CB(void)
{
    TecUtilLockOn();
    TecGUIDialogDrop(Dialog6Manager);
    TecUtilLockOff();
}




static void Dialog6Init_CB(void)
{
    TecUtilLockOn();
    TecGUIToggleSet(ApplySen_TOG_D6, TRUE);
    TecUtilLockOff();
}




static void Dialog1HelpButton_CB(void)
{
    TecUtilLockOn();
    TecUtilDialogMessageBox("On-line Help not available for this dialog.",
                            MessageBox_Information);
    TecUtilLockOff();
}




static void Dialog1CloseButton_CB(void)
{
    TecUtilLockOn();
    TecGUIDialogDrop(Dialog1Manager);
    TecUtilLockOff();
}




static void Dialog1Init_CB(void)
{
    TecUtilLockOn();

    TecUtilLockOff();
}


static const char *GetTabName(int I)
{
    static char Name[200];

    if (I == Tab1_1Manager)
        strcpy(Name, "Homer");
    else if (I == Tab2_1Manager)
        strcpy(Name, "Marge");
    else if (I == Tab3_1Manager)
        strcpy(Name, "Bart");
    else if (I == Tab1_2Manager)
        strcpy(Name, "Lisa");
    else if (I == Tab2_2Manager)
        strcpy(Name, "Maggie");
    else
        strcpy(Name, "Unknown");

    return Name;
}



static void TAB1_TBA_D1_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "%s tab activated.\n", GetTabName(*I));
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}




static void TAB1_TBD_D1_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "%s tab deactivated.\n", GetTabName(*I));
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}




static void TAB2_TBA_D1_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "%s tab activated.\n", GetTabName(*I));
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}




static void TAB2_TBD_D1_CB(const int *I)
{
    char buffer[200];
    TecUtilLockOn();
    sprintf(buffer, "%s tab deactivated.\n", GetTabName(*I));
    TecGUITextAppendString(Message_T_D1, buffer);
    TecUtilLockOff();
}



char *ActiveTab_OPT_D1_List = "Homer,Marge,Bart";




static void ActiveTab_OPT_D1_CB(const int *I)
{
    TecUtilLockOn();
    TRACE1("Option Menu (ActiveTab_OPT_D1) value changed,  New value is: %d\n", *I);
    TecUtilLockOff();
}




static void Set_BTN_D1_CB(void)
{
    int WhichTab;

    TecUtilLockOn();
    TRACE("Set Button Pushed\n");

    WhichTab = TecGUIOptionMenuGet(ActiveTab_OPT_D1);
    switch (WhichTab)
    {
        case 1:
            TecGUITabSetCurrentPage(TAB1_TB_D1, Tab1_1Manager);
            break;
        case 2:
            TecGUITabSetCurrentPage(TAB1_TB_D1, Tab2_1Manager);
            break;
        default:
            TecGUITabSetCurrentPage(TAB1_TB_D1, Tab3_1Manager);
            break;
    }

    TecUtilLockOff();
}




static void Dialog4HelpButton_CB(void)
{
    TecUtilLockOn();
    TecUtilDialogMessageBox("On-line Help not available for this dialog.",
                            MessageBox_Information);
    TecUtilLockOff();
}




static void Dialog4CloseButton_CB(void)
{
    TecUtilLockOn();
    TecGUIDialogDrop(Dialog4Manager);
    TecUtilLockOff();
}




static void Dialog4Init_CB(void)
{
    TecUtilLockOn();
    /*<<< Add init code (if necessary) here>>>*/
    TecUtilLockOff();
}





static void Homer_BTN_D4_CB(void)
{
    TecUtilLockOn();
    TecGUIFormSetCurrentPage(Form1_3Manager);
    TecUtilLockOff();
}




static void Marge_BTN_D4_CB(void)
{
    TecUtilLockOn();
    TecGUIFormSetCurrentPage(Form2_3Manager);
    TecUtilLockOff();
}




static void Bart_BTN_D4_CB(void)
{
    TecUtilLockOn();
    TecGUIFormSetCurrentPage(Form3_3Manager);
    TecUtilLockOff();
}




static void Lisa_BTN_D4_CB(void)
{
    TecUtilLockOn();
    TecGUIFormSetCurrentPage(Form1_4Manager);
    TecUtilLockOff();
}




static void Maggie_BTN_D4_CB(void)
{
    TecUtilLockOn();
    TecGUIFormSetCurrentPage(Form2_4Manager);
    TecUtilLockOff();
}




static void Dialog5HelpButton_CB(void)
{
    TecUtilLockOn();
    TecUtilDialogMessageBox("On-line Help not available for this dialog.",
                            MessageBox_Information);
    TecUtilLockOff();
}




static void Dialog5CloseButton_CB(void)
{
    TecUtilLockOn();
    TecGUIDialogDrop(Dialog5Manager);
    TecUtilLockOff();
}




static void Dialog5Init_CB(void)
{
    TecUtilLockOn();
    /*<<< Add init code (if necessary) here>>>*/
    TecUtilLockOff();
}


static void ApplyCallback(void)
{
    TecUtilLockOn();
    TecUtilDialogMessageBox("Apply button pushed", MessageBox_Information);
    TecUtilLockOff();
}


static void Launch_BTN_D5_CB(void)
{
    TecUtilLockOn();
    BuildDialog6(MAINDIALOGID);


    TecGUIDialogEnableActionArea(Dialog6Manager, (Boolean_t)TecGUIToggleGet(ActionArea_TOG_D5));

    TecGUIDialogLaunch(Dialog6Manager);
    TecUtilLockOff();
}




static void ActionArea_TOG_D5_CB(const int *I)
{
    TecUtilLockOn();

    TecUtilLockOff();
}




static void Apply_TOG_D5_CB(const int *I)
{
    TecUtilLockOn();

    TecUtilLockOff();
}




static void Dialog7HelpButton_CB(void)
{
    TecUtilLockOn();
    TecUtilDialogMessageBox("On-line Help not available for this dialog.",
                            MessageBox_Information);
    TecUtilLockOff();
}




static void Dialog7CancelButton_CB(void)
{
    TecGUIDialogDrop(Dialog7Manager);
    /*Modal Dialogs must call TecUtilLockOn prior to coming*/
    /*up and then call TecUtilLockOff when the Ok or Cancel*/
    /*button is pressed.  Only TecUtilLockOff is supplied here.*/
    TecUtilLockOff();
}




static void Dialog7OkButton_CB(void)
{
    TecGUIDialogDrop(Dialog7Manager);
    /*Modal Dialogs must call TecUtilLockOn prior to coming*/
    /*up and then call TecUtilLockOff when the Ok or Cancel*/
    /*button is pressed.  Only TecUtilLockOff is supplied here.*/
    TecUtilLockOff();
}




static void Dialog7Init_CB(void)
{
    /*Modal Dialogs must call TecUtilLockOn prior to coming*/
    /*up and then call TecUtilLockOff when the Ok or Cancel*/
    /*button is pressed.*/
    TecUtilLockOn();
    /*<<< Add init code (if necessary) here>>>*/
}



char *Test_OPT_D7_List = "Homer,Marge,Bart,Lisa,Maggie";




static void Test_OPT_D7_CB(const int *I)
{
    char Message[128];

    TecUtilLockOn();

    sprintf(Message, "Item #%d selected.", *I);
    TecUtilDialogMessageBox(Message, MessageBox_Information);

    TecUtilLockOff();
}




static void AppendItem_BTN_D7_CB(void)
{
    char *AppendText;
    TecUtilLockOn();

    AppendText = TecGUITextFieldGetString(AppendItem_TF_D7);

    if (strlen(AppendText) == 0)
        TecUtilDialogErrMsg("Please enter a valid string");
    else
        TecGUIOptionMenuAppendItem(Test_OPT_D7, AppendText);

    TecUtilStringDealloc(&AppendText);


    TecUtilLockOff();
}




static int  AppendItem_TF_D7_CB(const char *S)
{
    int IsOk = 1;
    TecUtilLockOn();

    TecUtilLockOff();
    return (IsOk);
}




static void DeleteAtPos_BTN_D7_CB(void)
{
    TecUtilLockOn();

    TecGUIOptionMenuDeleteItemAtPos(Test_OPT_D7, TecGUIOptionMenuGet(Test_OPT_D7));

    TecUtilLockOff();
}




static void ItemCount_BTN_D7_CB(void)
{
    char buffer[100];
    TecUtilLockOn();
    sprintf(buffer, "Item count = %d", TecGUIOptionMenuGetItemCount(Test_OPT_D7));
    TecUtilDialogMessageBox(buffer, MessageBox_Information);
    TecUtilLockOff();
}




static void DeleteAll_BTN_D7_CB(void)
{
    TecUtilLockOn();
    TecGUIOptionMenuDeleteAllItems(Test_OPT_D7);
    TecUtilLockOff();
}




static void GetString_BTN_D7_CB(void)
{
    char *ItemString;
    char buffer[200];

    TecUtilLockOn();

    ItemString = TecGUIOptionMenuGetString(Test_OPT_D7, TecGUIOptionMenuGet(Test_OPT_D7));
    sprintf(buffer, "Selected item is \"%s\"", ItemString);

    TecUtilDialogMessageBox(buffer, MessageBox_Information);

    TecUtilStringDealloc(&ItemString);

    TecUtilLockOff();
}




static int  Replace_TF_D7_CB(const char *S)
{
    int IsOk = 1;
    TecUtilLockOn();
    TecUtilLockOff();
    return (IsOk);
}




static void Replace_BTN_D7_CB(void)
{
    char *ReplaceText;
    TecUtilLockOn();

    ReplaceText = TecGUITextFieldGetString(Replace_TF_D7);

    if (strlen(ReplaceText) == 0)
        TecUtilDialogErrMsg("Please enter a valid string");
    else
        TecGUIOptionMenuReplaceItem(Test_OPT_D7, ReplaceText, TecGUIOptionMenuGet(Test_OPT_D7));

    TecUtilStringDealloc(&ReplaceText);


    TecUtilLockOff();
}




static void Dialog8HelpButton_CB(void)
{
    TecUtilLockOn();
    TecUtilDialogMessageBox("On-line Help not available for this dialog.",
                            MessageBox_Information);
    TecUtilLockOff();
}




static void Dialog8CloseButton_CB(void)
{
    TecUtilLockOn();
    TecGUIDialogDrop(Dialog8Manager);
    TecUtilLockOff();
}




static void Dialog8Init_CB(void)
{
    TecUtilLockOn();
    TecGUIToggleSet(TestScale_SC_D8, TRUE);
    TecGUIScaleShowNumericDisplay(TestScale_SC_D8, TRUE);
    TecUtilLockOff();
}




static void TestScale_SC_D8_CB(const int *I)
{
    TecUtilLockOn();
    TRACE1("Scale (TestScale_SC_D8) Value Changed,  New value is: %d\n", *I);
    TecUtilLockOff();
}




static void TestScale_SCD_D8_CB(const int *I)
{
    TecUtilLockOn();
    TRACE1("Scale (TestScale_SCD_D8) Value Changed on drag,  New value is: %d\n", *I);
    TecUtilLockOff();
}




static void ShowDisplay_TOG_D8_CB(const int *I)
{
    TecUtilLockOn();
    TecGUIScaleShowNumericDisplay(TestScale_SC_D8, (Boolean_t)*I);
    TecUtilLockOff();
}

static void ApplySen_TOG_D6_CB(const int *I)
{
    TecUtilLockOn();
    TecGUISetSensitivity(ApplyButton, (Boolean_t)*I);
    TecUtilLockOff();
}


#include "guibld.c"
