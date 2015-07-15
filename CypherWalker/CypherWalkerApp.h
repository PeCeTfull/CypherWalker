/***************************************************************
 * Name:      CypherWalkerApp.h
 * Purpose:   Defines Application Class
 * Author:    PeCeT_full (pecetfull@komputermania.pl.eu.org)
 * Created:   2015-02-13
 * Copyright: PeCeT_full (http://www.komputermania.pl.eu.org/)
 * Licence:   The MIT License
 **************************************************************/

#ifndef CYPHERWALKERAPP_H
#define CYPHERWALKERAPP_H

#include "wxTranslationHelper.h"
#include "ConfigFile.h"
#include <wx/app.h>

class CypherWalkerApp : public wxApp
{
    wxTranslationHelper *m_TranslationHelper;
    public:
        virtual bool OnInit();
        virtual int OnExit();
        void OnSetLanguage(short languageID);
        short SelectLanguage();
        short languageID = wxLANGUAGE_ENGLISH_CANADA; // parameter 1
        wxString newGameSoundFileName = PARAM_2_DEFAULT_VALUE; // parameter 2
        wxString makingMoveSoundFileName = PARAM_3_DEFAULT_VALUE; // parameter 3
        wxString lostGameSoundFileName = PARAM_4_DEFAULT_VALUE; // parameter 4
        wxString newHiScoreSoundFileName = PARAM_5_DEFAULT_VALUE; // parameter 5
};

DECLARE_APP(CypherWalkerApp);

#endif // CYPHERWALKERAPP_H
