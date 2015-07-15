/***************************************************************
 * Name:      CypherWalkerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    PeCeT_full (pecetfull@komputermania.pl.eu.org)
 * Created:   2015-02-13
 * Copyright: PeCeT_full (http://www.komputermania.pl.eu.org/)
 * Licence:   The MIT License
 **************************************************************/

#include "CypherWalkerMain.h"
#include "CypherWalkerApp.h"
#include "HiScoresDialog.h"
#include "HiScoresFile.h"
#include "EnterNameDialog.h"
#include "OptionsDialog.h"
#include "wxImagePanel.h"
#include <wx/msgdlg.h>
#include <wx/filename.h>
#include <wx/aboutdlg.h>
#include <wx/busyinfo.h>
#include <unistd.h>

#define ICON_NAME "aaaa"
#define SYSTEM_FONT_NAME "MS Shell Dlg"

//(*InternalHeaders(CypherWalkerDialog)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxBuildInfoFormat {
    short_f, long_f };

wxString wxBuildInfo(wxBuildInfoFormat format)
{
    wxString wxBuild(wxVERSION_STRING);

    if (format == long_f)
    {
#if defined(__WXMSW__)
        wxBuild << _T("-Windows");
#elif defined(__UNIX__)
        wxBuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxBuild << _T("-Unicode build");
#else
        wxBuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxBuild;
}

//(*IdInit(CypherWalkerDialog)
const long CypherWalkerDialog::ID_GAMEPANEL = wxNewId();
const long CypherWalkerDialog::ID_UPBUTTON = wxNewId();
const long CypherWalkerDialog::ID_LEFTBUTTON = wxNewId();
const long CypherWalkerDialog::ID_RIGHTBUTTON = wxNewId();
const long CypherWalkerDialog::ID_DOWNBUTTON = wxNewId();
const long CypherWalkerDialog::ID_STATICLINE1 = wxNewId();
const long CypherWalkerDialog::ID_PLAYBUTTON = wxNewId();
const long CypherWalkerDialog::ID_HISCORESBUTTON = wxNewId();
const long CypherWalkerDialog::ID_OPTIONSBUTTON = wxNewId();
const long CypherWalkerDialog::ID_ABOUTBUTTON = wxNewId();
const long CypherWalkerDialog::ID_QUITBUTTON = wxNewId();
//*)

BEGIN_EVENT_TABLE(CypherWalkerDialog,wxDialog)
    //(*EventTable(CypherWalkerDialog)
    //*)
END_EVENT_TABLE()

CypherWalkerDialog::CypherWalkerDialog(wxWindow* parent, wxWindowID id)
{
    //(*Initialize(CypherWalkerDialog)
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, wxID_ANY, _("Cypher Walker"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    GamePanel = new wxPanel(this, ID_GAMEPANEL, wxDefaultPosition, wxSize(400,400), wxTAB_TRAVERSAL, _T("ID_GAMEPANEL"));
    GamePanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    FlexGridSizer1->Add(GamePanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(5, 0, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(3, 0, 0, 0);
    UpButton = new wxButton(this, ID_UPBUTTON, _("Up (&I)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_UPBUTTON"));
    UpButton->Disable();
    FlexGridSizer4->Add(UpButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
    LeftButton = new wxButton(this, ID_LEFTBUTTON, _("Left (&J)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_LEFTBUTTON"));
    LeftButton->Disable();
    FlexGridSizer5->Add(LeftButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RightButton = new wxButton(this, ID_RIGHTBUTTON, _("Right (&L)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RIGHTBUTTON"));
    RightButton->Disable();
    FlexGridSizer5->Add(RightButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DownButton = new wxButton(this, ID_DOWNBUTTON, _("Down (&K)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_DOWNBUTTON"));
    DownButton->Disable();
    FlexGridSizer4->Add(DownButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    FlexGridSizer2->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(2, 2, 0, 0);
    PlayButton = new wxButton(this, ID_PLAYBUTTON, _("&Play"), wxDefaultPosition, wxSize(68,-1), 0, wxDefaultValidator, _T("ID_PLAYBUTTON"));
    PlayButton->SetDefault();
    FlexGridSizer3->Add(PlayButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    HiScoresButton = new wxButton(this, ID_HISCORESBUTTON, _("&High scores"), wxDefaultPosition, wxSize(110,-1), 0, wxDefaultValidator, _T("ID_HISCORESBUTTON"));
    FlexGridSizer3->Add(HiScoresButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    OptionsButton = new wxButton(this, ID_OPTIONSBUTTON, _("&Options"), wxDefaultPosition, wxSize(68,-1), 0, wxDefaultValidator, _T("ID_OPTIONSBUTTON"));
    FlexGridSizer3->Add(OptionsButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AboutButton = new wxButton(this, ID_ABOUTBUTTON, _("&About..."), wxDefaultPosition, wxSize(110,-1), 0, wxDefaultValidator, _T("ID_ABOUTBUTTON"));
    FlexGridSizer3->Add(AboutButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    QuitButton = new wxButton(this, ID_QUITBUTTON, _("&Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_QUITBUTTON"));
    FlexGridSizer2->Add(QuitButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);
    Center();

    Connect(ID_UPBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CypherWalkerDialog::OnUpButtonClick);
    Connect(ID_LEFTBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CypherWalkerDialog::OnLeftButtonClick);
    Connect(ID_RIGHTBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CypherWalkerDialog::OnRightButtonClick);
    Connect(ID_DOWNBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CypherWalkerDialog::OnDownButtonClick);
    Connect(ID_PLAYBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CypherWalkerDialog::OnPlayButtonClick);
    Connect(ID_HISCORESBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CypherWalkerDialog::OnHiScoresButtonClick);
    Connect(ID_OPTIONSBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CypherWalkerDialog::OnOptionsButtonClick);
    Connect(ID_ABOUTBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CypherWalkerDialog::OnAbout);
    Connect(ID_QUITBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CypherWalkerDialog::OnQuit);
    //*)

    SetIcon(wxIcon(wxT(ICON_NAME)));

    HiScoresFile *newHiScoresFile = new HiScoresFile();
    if(!wxFileName::FileExists(newHiScoresFile->hiScoresFileName))
        newHiScoresFile->NewFileContents();
    wxDELETE(newHiScoresFile);

    if(wxFileName::FileExists(boardBackgroundFileName))
    {
        drawPanel = new wxImagePanel(GamePanel, boardBackgroundFileName, wxBITMAP_TYPE_PNG);
        drawPanel->SetSize(400,400);
        drawPanel->SetId(4949);
    }
}

CypherWalkerDialog::~CypherWalkerDialog()
{
    //(*Destroy(CypherWalkerDialog)
    //*)
}

void CypherWalkerDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CypherWalkerDialog::OnAbout(wxCommandEvent& event)
{
    wxAboutDialogInfo info;
    info.SetIcon(wxIcon(wxT(ICON_NAME)));
    info.SetName(_("Cypher Walker"));
    info.SetVersion(wxT("1.0"));
    info.SetCopyright(wxT("Copyright (C) PeCeT_full 2015 <pecetfull@komputermania.pl.eu.org>"));
    info.SetDescription(_("A dynamic logic game designed for both vintage and modern computers.\n\nBuild info: ") + wxT(wxBuildInfo(long_f) + '.'));
    info.SetWebSite(_("http://www.komputermania.pl.eu.org"));
    info.SetLicence(_("This program is published under The MIT License. For more information, please refer to the Licence.txt file included with the application."));

    wxAboutBox(info);
}

// http://www.concentric.net/~Ttwang/tech/inthash.htm
unsigned long Mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

wxInt32 ReturnRandomDigit()
{
    wxInt32 randomDigit;
    randomDigit = rand() % 9 + 1; // numbers 1 to 9
    return randomDigit;
}

void CypherWalkerDialog::CleanGamePanel()
{
    if(drawPanel != NULL)
        drawPanel->Show();
    wxYield();
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 25; j++)
        {
            wxWindow *buttonToRemove = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), j, i));
            buttonToRemove->Destroy();
        }
    }
}

wxFont buttonBoldFont(8, wxSWISS, wxFONTSTYLE_NORMAL, wxBOLD, false, _T(SYSTEM_FONT_NAME), wxFONTENCODING_DEFAULT);

void CypherWalkerDialog::OnPlayButtonClick(wxCommandEvent& event)
{
    wxBusyInfo wait(_("Generating and initialising the board, please wait..."));
    totalScore = 0;
    wxTopLevelWindow::SetTitle(_T(wxString::Format(wxT(titleWithScore + "%d"), totalScore)));
    if(!firstLaunch)
        CleanGamePanel();
    else
        firstLaunch = false;
    lastPassedX = 12;
    lastPassedY = 12;
    wxFont buttonToAddFont(8, wxSWISS, wxFONTSTYLE_NORMAL, wxNORMAL, false, _T(SYSTEM_FONT_NAME), wxFONTENCODING_DEFAULT);
    srand(Mix(clock(), time(NULL), getpid()));
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 25; j++)
        {
            if (i != lastPassedY || j != lastPassedX)
            {
                wxButton *buttonToAdd = new wxButton(GamePanel, wxNewId(), _T(wxString::Format(wxT("%d"), ReturnRandomDigit())), wxPoint(j * 16, i * 16), wxSize(16, 16), 0, wxDefaultValidator, wxString::Format(wxT("ID_BUTTON_%dX%d"), j, i));
                buttonToAdd->SetFont(buttonToAddFont);
            }
            else
            {
                wxButton *buttonToAdd = new wxButton(GamePanel, wxNewId(), _T("0"), wxPoint(j * 16, i * 16), wxSize(16, 16), 0, wxDefaultValidator, wxString::Format(wxT("ID_BUTTON_%dX%d"), j, i));
                buttonToAdd->SetFont(buttonBoldFont);
                buttonToAdd->SetForegroundColour(wxColour(*wxRED));
            }
        }
    }
    UpButton->Enable();
    LeftButton->Enable();
    RightButton->Enable();
    DownButton->Enable();
    if(drawPanel != NULL)
        drawPanel->Hide();
    soundFile->Play(wxGetApp().newGameSoundFileName);
}

void CypherWalkerDialog::CheckIfNoPossibleMovements(wxButton* DownButton, wxButton* RightButton, wxButton* LeftButton, wxButton* UpButton, int& totalScore)
{
    if(!DownButton->IsEnabled() && !RightButton->IsEnabled() && !LeftButton->IsEnabled() && !UpButton->IsEnabled())
    {
        HiScoresFile *currentHiScoresFile = new HiScoresFile();
        wxString *currentHiScores = currentHiScoresFile->ReadFileContents();
        wxDELETE(currentHiScoresFile);
        int record1 = wxAtoi(_T(currentHiScores[1]));
        int record2 = wxAtoi(_T(currentHiScores[3]));
        int record3 = wxAtoi(_T(currentHiScores[5]));
        int record4 = wxAtoi(_T(currentHiScores[7]));
        int record5 = wxAtoi(_T(currentHiScores[9]));
        short deservedPlace = 0;
        if(totalScore >= record1)
            deservedPlace = 1;
        else if(totalScore >= record2)
            deservedPlace = 2;
        else if(totalScore >= record3)
            deservedPlace = 3;
        else if(totalScore >= record4)
            deservedPlace = 4;
        else if(totalScore >= record5)
            deservedPlace = 5;
        else
        {
            soundFile->Play(wxGetApp().lostGameSoundFileName);
            wxMessageBox(wxString::Format(_("Congratulations! You've gained %d points in total."), totalScore), _("Game over"));
            return;
        }
        soundFile->Play(wxGetApp().newHiScoreSoundFileName);
        EnterNameDialog *newEnterNameDialog = new EnterNameDialog(totalScore, deservedPlace, currentHiScores, GetParent(), -1);
        newEnterNameDialog->ShowModal();
    }
    else
        soundFile->Play(wxGetApp().makingMoveSoundFileName);
}

void CheckForBottomBoundary(wxButton* DownButton, wxWindow* buttonToRead, int& lastPassedX, int& lastPassedY)
{
    if(lastPassedY == 24) // if the last zero is on the very bottom
        DownButton->Disable();
    else
    {
        buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX, lastPassedY + 1));
        int movesToPossiblyPass = wxAtoi(_T(buttonToRead->GetLabel()));
        if(movesToPossiblyPass == 0) // if the neighbouring button has the value 0
        {
            DownButton->Disable();
            return;
        }
        movesToPossiblyPass++;
        int yToPossiblyAchieve = lastPassedY + movesToPossiblyPass;
        if(yToPossiblyAchieve > 25) // if the closest button's value is too high to achieve without boundaries
            DownButton->Disable();
        else
        {
            for(int i = lastPassedY + 1; i < yToPossiblyAchieve; i++)
            {
                buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX, i));
                int valueToCheck = wxAtoi(_T(buttonToRead->GetLabel()));
                if(valueToCheck == 0) // if there's an obstacle (value 0 on its path)
                {
                    DownButton->Disable();
                    break;
                }
                if(i == yToPossiblyAchieve - 1) // if all conditions are fulfilled for a movement to the right, let's ensure the player can move there
                    DownButton->Enable();
            }
        }
    }
}

void CheckForRightBoundary(wxButton* RightButton, wxWindow* buttonToRead, int& lastPassedX, int& lastPassedY)
{
    if(lastPassedX == 24) // if the last zero is on the very right
        RightButton->Disable();
    else
    {
        buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX + 1, lastPassedY));
        int movesToPossiblyPass = wxAtoi(_T(buttonToRead->GetLabel()));
        if(movesToPossiblyPass == 0) // if the neighbouring button has the value 0
        {
            RightButton->Disable();
            return;
        }
        movesToPossiblyPass++;
        int xToPossiblyAchieve = lastPassedX + movesToPossiblyPass;
        if(xToPossiblyAchieve > 25) // if the closest button's value is too high to achieve without passing the boundary
            RightButton->Disable();
        else
        {
            for(int i = lastPassedX + 1; i < xToPossiblyAchieve; i++)
            {
                buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), i, lastPassedY));
                int valueToCheck = wxAtoi(_T(buttonToRead->GetLabel()));
                if(valueToCheck == 0) // if there's an obstacle (value 0 on its path)
                {
                    RightButton->Disable();
                    break;
                }
                if(i == xToPossiblyAchieve - 1) // if all conditions are fulfilled for a movement to the right, let's ensure the player can move there
                    RightButton->Enable();
            }
        }
    }
}

void CheckForLeftBoundary(wxButton* LeftButton, wxWindow* buttonToRead, int& lastPassedX, int& lastPassedY)
{
    if(lastPassedX == 0) // if the last zero is on the very left
        LeftButton->Disable();
    else
    {
        buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX - 1, lastPassedY));
        int movesToPossiblyPass = wxAtoi(_T(buttonToRead->GetLabel()));
        if(movesToPossiblyPass == 0) // if the neighbouring button has the value 0
        {
            LeftButton->Disable();
            return;
        }
        movesToPossiblyPass++;
        int xToPossiblyAchieve = lastPassedX - movesToPossiblyPass;
        if(xToPossiblyAchieve < -1) // if the closest button's value is too high to achieve without passing the boundary
            LeftButton->Disable();
        else
        {
            for(int i = lastPassedX - 1; i > xToPossiblyAchieve; i--)
            {
                buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), i, lastPassedY));
                int valueToCheck = wxAtoi(_T(buttonToRead->GetLabel()));
                if(valueToCheck == 0) // if there's an obstacle (value 0 on its path)
                {
                    LeftButton->Disable();
                    break;
                }
                if(i == xToPossiblyAchieve + 1) // if all conditions are fulfilled for a movement to the right, let's ensure the player can move there
                    LeftButton->Enable();
            }
        }
    }
}

void CheckForTopBoundary(wxButton* UpButton, wxWindow* buttonToRead, int& lastPassedX, int& lastPassedY)
{
    if(lastPassedY == 0) // if the last zero is on the very top
        UpButton->Disable();
    else
    {
        buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX, lastPassedY - 1));
        int movesToPossiblyPass = wxAtoi(_T(buttonToRead->GetLabel()));
        if(movesToPossiblyPass == 0) // if the neighbouring button has the value 0
        {
            UpButton->Disable();
            return;
        }
        movesToPossiblyPass++;
        int yToPossiblyAchieve = lastPassedY - movesToPossiblyPass;
        if(yToPossiblyAchieve < -1) // if the closest button's value is too high to achieve without boundaries
            UpButton->Disable();
        else
        {
            for(int i = lastPassedY - 1; i > yToPossiblyAchieve; i--)
            {
                buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX, i));
                int valueToCheck = wxAtoi(_T(buttonToRead->GetLabel()));
                if(valueToCheck == 0) // if there's an obstacle (value 0 on its path)
                {
                    UpButton->Disable();
                    break;
                }
                if(i == yToPossiblyAchieve + 1) // if all conditions are fulfilled for a movement to the right, let's ensure the player can move there
                    UpButton->Enable();
            }
        }
    }
}

void CypherWalkerDialog::OnDownButtonClick(wxCommandEvent& event)
{
    wxWindow *buttonToRead;
    int movesToPass;
    buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX, lastPassedY + 1));
    movesToPass = wxAtoi(_T(buttonToRead->GetLabel()));
    totalScore += movesToPass;
    movesToPass++;
    int yToAchieve = lastPassedY + movesToPass;
    for(int i = lastPassedY; i < yToAchieve; i++)
    {
        wxWindow *buttonToRename = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX, i));
        buttonToRename->SetLabel(_T("0"));
        buttonToRename->SetFont(buttonBoldFont);
        if(i != yToAchieve - 1)
            buttonToRename->SetForegroundColour(wxColour(255, 128, 0));
        else
            buttonToRename->SetForegroundColour(wxColour(*wxRED));
    }
    lastPassedY = yToAchieve - 1; // we've achieved it

    UpButton->Disable(); // obviously you cannot turn back
    CheckForLeftBoundary(LeftButton, buttonToRead, lastPassedX, lastPassedY);
    CheckForRightBoundary(RightButton, buttonToRead, lastPassedX, lastPassedY);
    CheckForBottomBoundary(DownButton, buttonToRead, lastPassedX, lastPassedY);

    wxTopLevelWindow::SetTitle(_T(wxString::Format(wxT(titleWithScore + "%d"), totalScore)));
    CheckIfNoPossibleMovements(DownButton, RightButton, LeftButton, UpButton, totalScore);
}

void CypherWalkerDialog::OnRightButtonClick(wxCommandEvent& event)
{
    wxWindow *buttonToRead;
    int movesToPass;
    buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX + 1, lastPassedY));
    movesToPass = wxAtoi(_T(buttonToRead->GetLabel()));
    totalScore += movesToPass;
    movesToPass++;
    int xToAchieve = lastPassedX + movesToPass;
    for(int i = lastPassedX; i < xToAchieve; i++)
    {
        wxWindow *buttonToRename = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), i, lastPassedY));
        buttonToRename->SetLabel(_T("0"));
        buttonToRename->SetFont(buttonBoldFont);
        if(i != xToAchieve - 1)
            buttonToRename->SetForegroundColour(wxColour(255, 128, 0));
        else
            buttonToRename->SetForegroundColour(wxColour(*wxRED));
    }
    lastPassedX = xToAchieve - 1; // we've achieved it

    CheckForTopBoundary(UpButton, buttonToRead, lastPassedX, lastPassedY);
    LeftButton->Disable(); // obviously you cannot turn back
    CheckForRightBoundary(RightButton, buttonToRead, lastPassedX, lastPassedY);
    CheckForBottomBoundary(DownButton, buttonToRead, lastPassedX, lastPassedY);

    wxTopLevelWindow::SetTitle(_T(wxString::Format(wxT(titleWithScore + "%d"), totalScore)));
    CheckIfNoPossibleMovements(DownButton, RightButton, LeftButton, UpButton, totalScore);
}

void CypherWalkerDialog::OnLeftButtonClick(wxCommandEvent& event)
{
    wxWindow *buttonToRead;
    int movesToPass;
    buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX - 1, lastPassedY));
    movesToPass = wxAtoi(_T(buttonToRead->GetLabel()));
    totalScore += movesToPass;
    movesToPass++;
    int xToAchieve = lastPassedX - movesToPass;
    for(int i = lastPassedX; i > xToAchieve; i--)
    {
        wxWindow *buttonToRename = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), i, lastPassedY));
        buttonToRename->SetLabel(_T("0"));
        buttonToRename->SetFont(buttonBoldFont);
        if(i != xToAchieve + 1)
            buttonToRename->SetForegroundColour(wxColour(255, 128, 0));
        else
            buttonToRename->SetForegroundColour(wxColour(*wxRED));
    }
    lastPassedX = xToAchieve + 1; // we've achieved it

    CheckForTopBoundary(UpButton, buttonToRead, lastPassedX, lastPassedY);
    CheckForLeftBoundary(LeftButton, buttonToRead, lastPassedX, lastPassedY);
    RightButton->Disable(); // obviously you cannot turn back
    CheckForBottomBoundary(DownButton, buttonToRead, lastPassedX, lastPassedY);

    wxTopLevelWindow::SetTitle(_T(wxString::Format(wxT(titleWithScore + "%d"), totalScore)));
    CheckIfNoPossibleMovements(DownButton, RightButton, LeftButton, UpButton, totalScore);
}

void CypherWalkerDialog::OnUpButtonClick(wxCommandEvent& event)
{
    wxWindow *buttonToRead;
    int movesToPass;
    buttonToRead = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX, lastPassedY - 1));
    movesToPass = wxAtoi(_T(buttonToRead->GetLabel()));
    totalScore += movesToPass;
    movesToPass++;
    int yToAchieve = lastPassedY - movesToPass;
    for(int i = lastPassedY; i > yToAchieve; i--)
    {
        wxWindow *buttonToRename = wxButton::FindWindowByName(wxString::Format(wxT("ID_BUTTON_%dX%d"), lastPassedX, i));
        buttonToRename->SetLabel(_T("0"));
        buttonToRename->SetFont(buttonBoldFont);
        if(i != yToAchieve + 1)
            buttonToRename->SetForegroundColour(wxColour(255, 128, 0));
        else
            buttonToRename->SetForegroundColour(wxColour(*wxRED));
    }
    lastPassedY = yToAchieve + 1; // we've achieved it

    CheckForTopBoundary(UpButton, buttonToRead, lastPassedX, lastPassedY);
    CheckForLeftBoundary(LeftButton, buttonToRead, lastPassedX, lastPassedY);
    CheckForRightBoundary(RightButton, buttonToRead, lastPassedX, lastPassedY);
    DownButton->Disable(); // obviously you cannot turn back

    wxTopLevelWindow::SetTitle(_T(wxString::Format(wxT(titleWithScore + "%d"), totalScore)));
    CheckIfNoPossibleMovements(DownButton, RightButton, LeftButton, UpButton, totalScore);
}

void CypherWalkerDialog::OnHiScoresButtonClick(wxCommandEvent& event)
{
    HiScoresDialog *NewHiScoresDialog = new HiScoresDialog(GetParent(), -1);
    NewHiScoresDialog->ShowModal();
    wxDELETE(NewHiScoresDialog);
}

void CypherWalkerDialog::OnOptionsButtonClick(wxCommandEvent& event)
{
    OptionsDialog *NewOptionsDialog = new OptionsDialog(wxGetApp().languageID, wxGetApp().newGameSoundFileName, wxGetApp().makingMoveSoundFileName, wxGetApp().lostGameSoundFileName, wxGetApp().newHiScoreSoundFileName, GetParent(), -1);
    NewOptionsDialog->ShowModal();
    wxDELETE(NewOptionsDialog);
}
