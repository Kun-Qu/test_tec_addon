/***************************************************
 *                                                 *
 *  NOTE!  This file is automatically generated by *
 *         the Tecplot GUI Builder.  It is highly  *
 *         recommended that you never edit this    *
 *         file directly!                          *
 *                                                 *
 ***************************************************/


void BuildDialog1(int  ParentDialog)
{
    if (Dialog1Manager != BADDIALOGID)
        return;

    Dialog1Manager = TecGUIDialogCreateModeless(ParentDialog,
                                                4607,
                                                1080,
                                                "Select like master",
                                                Dialog1Init_CB,
                                                Dialog1CloseButton_CB,
                                                Dialog1HelpButton_CB);
    SelectMatchi_BTN_D1 = TecGUIButtonAdd(Dialog1Manager,
                                          878,
                                          804,
                                          2674,
                                          154,
                                          "Select Matching Objects",
                                          SelectMatchi_BTN_D1_CB);
    ZoneAttachme_TOG_D1 = TecGUIToggleAdd(Dialog1Manager,
                                          1133,
                                          453,
                                          2470,
                                          127,
                                          "Zone Attachment",
                                          ZoneAttachme_TOG_D1_CB);
    Color_TOG_D1 = TecGUIToggleAdd(Dialog1Manager,
                                   1133,
                                   613,
                                   1273,
                                   127,
                                   "Color",
                                   Color_TOG_D1_CB);
    Chooseattrib_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                                         840,
                                         85,
                                         "Choose attributes to match \nfrom initially picked text or\ngeometry object");
}

void InitTGB(void)
{
    /* Currently not used */
}
