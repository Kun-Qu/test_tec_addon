/*
****************************************************************
****************** BEGIN DEVELOPMENT NOTES *********************
****************************************************************


****************************************************************
****************** END DEVELOPMENT NOTES ***********************
****************************************************************
****************************************************************
*  D in column 1 marks date information.                       *
*  C in column 1 marks notes on new changes.                   *
*  B in column 1 marks notes on bug fixes.                     *
****************************************************************

*/

#include "TecplotVersion.h"
#define ADDON_VERSION TecVersionId
#define ADDON_NAME "AdvPick Sample"
#ifdef __DATE__
# define ADDON_DATE __DATE__
#else
# define ADDON_DATE ""
#endif /* __DATE__ */
#define MinTecplotVersionAllowed 740400
