/***************************************************************
 * Name:      CypherWalkerMain.h
 * Purpose:   Defines Application Frame
 * Author:    PeCeT_full (pecetfull@komputermania.pl.eu.org)
 * Created:   2015-02-13
 * Copyright: PeCeT_full (http://www.komputermania.pl.eu.org/)
 * Licence:   The MIT License
 **************************************************************/

#ifndef CYPHERWALKERMAIN_H
#define CYPHERWALKERMAIN_H

#include <wx/sound.h>

//(*Headers(CypherWalkerDialog)
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CypherWalkerDialog: public wxDialog
{
    public:

        CypherWalkerDialog(wxWindow* parent, wxWindowID id = -1);
        virtual ~CypherWalkerDialog();

    private:

        void CleanGamePanel();
        void CheckIfNoPossibleMovements(wxButton* DownButton, wxButton* RightButton, wxButton* LeftButton, wxButton* UpButton, int& totalScore);
        wxPanel *drawPanel = NULL;
        wxSound *soundFile = new wxSound();
        const wxString boardBackgroundFileName = wxT("splash.png");
        wxString titleWithScore = _("Cypher Walker - Score: ");
        bool firstLaunch = true;
        int totalScore;
        int lastPassedX;
        int lastPassedY;

        //(*Handlers(CypherWalkerDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPlayButtonClick(wxCommandEvent& event);
        void OnDownButtonClick(wxCommandEvent& event);
        void OnRightButtonClick(wxCommandEvent& event);
        void OnLeftButtonClick(wxCommandEvent& event);
        void OnUpButtonClick(wxCommandEvent& event);
        void OnHiScoresButtonClick(wxCommandEvent& event);
        void OnOptionsButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(CypherWalkerDialog)
        static const long ID_GAMEPANEL;
        static const long ID_UPBUTTON;
        static const long ID_LEFTBUTTON;
        static const long ID_RIGHTBUTTON;
        static const long ID_DOWNBUTTON;
        static const long ID_STATICLINE1;
        static const long ID_PLAYBUTTON;
        static const long ID_HISCORESBUTTON;
        static const long ID_OPTIONSBUTTON;
        static const long ID_ABOUTBUTTON;
        static const long ID_QUITBUTTON;
        //*)

        //(*Declarations(CypherWalkerDialog)
        wxButton* UpButton;
        wxButton* PlayButton;
        wxButton* HiScoresButton;
        wxButton* AboutButton;
        wxButton* DownButton;
        wxStaticLine* StaticLine1;
        wxButton* QuitButton;
        wxPanel* GamePanel;
        wxButton* LeftButton;
        wxButton* OptionsButton;
        wxButton* RightButton;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CYPHERWALKERMAIN_H
