/***************************************************************
 * Name:      CypherWalkerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    PeCeT_full (pecetfull@komputermania.pl.eu.org)
 * Created:   2015-02-13
 * Copyright: PeCeT_full (http://www.komputermania.pl.eu.org/)
 * Licence:   The MIT License
 **************************************************************/

#include "CypherWalkerApp.h"
#include <wx/filename.h>

//(*AppHeaders
#include "CypherWalkerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(CypherWalkerApp);

bool CypherWalkerApp::OnInit()
{
    m_TranslationHelper = new wxTranslationHelper(*this);

    wxString *parameters;
    ConfigFile *newConfigFile = new ConfigFile();
    if(!wxFileName::FileExists(newConfigFile->configFileName))
        newConfigFile->NewFileContents();
    else
    {
        parameters = newConfigFile->ReadFileContents();

        const wxChar equalitySign = '=';
        size_t equalitySignPos;
        equalitySignPos = parameters[1].Find(equalitySign);
        languageID = wxAtoi(_T(parameters[1].SubString(equalitySignPos + 1, parameters[1].Length())));
        equalitySignPos = parameters[2].Find(equalitySign);
        newGameSoundFileName = parameters[2].SubString(equalitySignPos + 1, parameters[2].Length());
        equalitySignPos = parameters[3].Find(equalitySign);
        makingMoveSoundFileName = parameters[3].SubString(equalitySignPos + 1, parameters[3].Length());
        equalitySignPos = parameters[4].Find(equalitySign);
        lostGameSoundFileName = parameters[4].SubString(equalitySignPos + 1, parameters[4].Length());
        equalitySignPos = parameters[5].Find(equalitySign);
        newHiScoreSoundFileName = parameters[5].SubString(equalitySignPos + 1, parameters[5].Length());
    }
    wxDELETE(newConfigFile);
    m_TranslationHelper->Load(languageID);

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	CypherWalkerDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}

int CypherWalkerApp::OnExit()
{
    if(m_TranslationHelper)
        wxDELETE(m_TranslationHelper);
    return 0;
}

void CypherWalkerApp::OnSetLanguage(short languageID)
{
    m_TranslationHelper->SetLanguage(languageID);
}

short CypherWalkerApp::SelectLanguage()
{
    wxArrayString names;
    wxArrayShort identifiers;
    m_TranslationHelper->GetInstalledLanguages(names, identifiers);
    return m_TranslationHelper->AskUserForLanguage(names, identifiers);
}
