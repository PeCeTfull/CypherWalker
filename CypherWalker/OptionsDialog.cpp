#include "OptionsDialog.h"
#include "CypherWalkerApp.h"
#include "ConfigFile.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(OptionsDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(OptionsDialog)
const long OptionsDialog::ID_NEWGAMESOUNDSTATICTEXT = wxNewId();
const long OptionsDialog::ID_NEWGAMESOUNDTEXTCTRL = wxNewId();
const long OptionsDialog::ID_MAKINGMOVESOUNDSTATICTEXT = wxNewId();
const long OptionsDialog::ID_MAKINGMOVESOUNDTEXTCTRL = wxNewId();
const long OptionsDialog::ID_LOSTGAMESOUNDSTATICTEXT = wxNewId();
const long OptionsDialog::ID_LOSTGAMESOUNDTEXTCTRL = wxNewId();
const long OptionsDialog::ID_NEWHISCORESOUNDSTATICTEXT = wxNewId();
const long OptionsDialog::ID_NEWHISCORESOUNDTEXTCTRL = wxNewId();
const long OptionsDialog::ID_STATICLINE1 = wxNewId();
const long OptionsDialog::ID_CURRENTLANGUAGESTATICTEXT = wxNewId();
const long OptionsDialog::ID_CHANGELANGUAGEBUTTON = wxNewId();
const long OptionsDialog::ID_APPLYBUTTON = wxNewId();
//*)

BEGIN_EVENT_TABLE(OptionsDialog,wxDialog)
	//(*EventTable(OptionsDialog)
	//*)
END_EVENT_TABLE()

OptionsDialog::OptionsDialog(short& languageID, wxString& newGameSoundFileName, wxString& makingMoveSoundFileName, wxString& lostGameSoundFileName, wxString& newHiScoreSoundFileName, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	//(*Initialize(OptionsDialog)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Game options"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(4, 0, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(4, 2, 0, 0);
	NewGameSoundStaticText = new wxStaticText(this, ID_NEWGAMESOUNDSTATICTEXT, _("New game sound:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_NEWGAMESOUNDSTATICTEXT"));
	FlexGridSizer2->Add(NewGameSoundStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	NewGameSoundTextCtrl = new wxTextCtrl(this, ID_NEWGAMESOUNDTEXTCTRL, wxEmptyString, wxDefaultPosition, wxSize(200,21), 0, wxDefaultValidator, _T("ID_NEWGAMESOUNDTEXTCTRL"));
	FlexGridSizer2->Add(NewGameSoundTextCtrl, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	MakingMoveSoundStaticText = new wxStaticText(this, ID_MAKINGMOVESOUNDSTATICTEXT, _("Making a move sound:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_MAKINGMOVESOUNDSTATICTEXT"));
	FlexGridSizer2->Add(MakingMoveSoundStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	MakingMoveSoundTextCtrl = new wxTextCtrl(this, ID_MAKINGMOVESOUNDTEXTCTRL, wxEmptyString, wxDefaultPosition, wxSize(200,21), 0, wxDefaultValidator, _T("ID_MAKINGMOVESOUNDTEXTCTRL"));
	FlexGridSizer2->Add(MakingMoveSoundTextCtrl, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	LostGameSoundStaticText = new wxStaticText(this, ID_LOSTGAMESOUNDSTATICTEXT, _("Lost game sound:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LOSTGAMESOUNDSTATICTEXT"));
	FlexGridSizer2->Add(LostGameSoundStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	LostGameSoundTextCtrl = new wxTextCtrl(this, ID_LOSTGAMESOUNDTEXTCTRL, wxEmptyString, wxDefaultPosition, wxSize(200,21), 0, wxDefaultValidator, _T("ID_LOSTGAMESOUNDTEXTCTRL"));
	FlexGridSizer2->Add(LostGameSoundTextCtrl, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	NewHiScoreSoundStaticText = new wxStaticText(this, ID_NEWHISCORESOUNDSTATICTEXT, _("New record sound:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_NEWHISCORESOUNDSTATICTEXT"));
	FlexGridSizer2->Add(NewHiScoreSoundStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	NewHiScoreSoundTextCtrl = new wxTextCtrl(this, ID_NEWHISCORESOUNDTEXTCTRL, wxEmptyString, wxDefaultPosition, wxSize(200,21), 0, wxDefaultValidator, _T("ID_NEWHISCORESOUNDTEXTCTRL"));
	FlexGridSizer2->Add(NewHiScoreSoundTextCtrl, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
	CurrentLanguageStaticText = new wxStaticText(this, ID_CURRENTLANGUAGESTATICTEXT, _("Current language: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_CURRENTLANGUAGESTATICTEXT"));
	FlexGridSizer4->Add(CurrentLanguageStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	ChangeLanguageButton = new wxButton(this, ID_CHANGELANGUAGEBUTTON, _("C&hange"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHANGELANGUAGEBUTTON"));
	FlexGridSizer4->Add(ChangeLanguageButton, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	OKButton = new wxButton(this, wxID_YES, _("&OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_YES"));
	OKButton->SetDefault();
	FlexGridSizer3->Add(OKButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
	CancelButton = new wxButton(this, wxID_OK, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	FlexGridSizer3->Add(CancelButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
	ApplyButton = new wxButton(this, ID_APPLYBUTTON, _("&Apply"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_APPLYBUTTON"));
	FlexGridSizer3->Add(ApplyButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	Center();

	Connect(ID_CHANGELANGUAGEBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OptionsDialog::OnChangeLanguageButtonClick);
	Connect(wxID_YES,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OptionsDialog::OnOKButtonClick);
	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OptionsDialog::OnCancelButtonClick);
	Connect(ID_APPLYBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OptionsDialog::OnApplyButtonClick);
	//*)

	NewGameSoundTextCtrl->SetLabel(newGameSoundFileName);
	MakingMoveSoundTextCtrl->SetLabel(makingMoveSoundFileName);
	LostGameSoundTextCtrl->SetLabel(lostGameSoundFileName);
	NewHiScoreSoundTextCtrl->SetLabel(newHiScoreSoundFileName);
	wxString currentLanguageName = wxLocale::GetLanguageName(languageID);
	if(currentLanguageName.Contains(DEFAULT_LANGUAGE_FORMAL_NAME))
        currentLanguageName = DEFAULT_LANGUAGE_FORMAL_NAME;
    currentLanguageName = _(currentLanguageName);
	CurrentLanguageStaticText->SetLabel(_("Current language: ") + currentLanguageName);
	languageIDPointer = &languageID;
	newGameSoundFileNamePointer = &newGameSoundFileName;
	makingMoveSoundFileNamePointer = &makingMoveSoundFileName;
	lostGameSoundFileNamePointer = &lostGameSoundFileName;
	newHiScoreSoundFileNamePointer = &newHiScoreSoundFileName;
	chosenLanguageID = languageID;
}

OptionsDialog::~OptionsDialog()
{
	//(*Destroy(OptionsDialog)
	//*)
}


void OptionsDialog::ApplySettings()
{
    if(*languageIDPointer != chosenLanguageID)
    {
        wxMessageBox(_("Another language has just been selected. To reflect all the changes, please restart the application."), _("Message"));
        *languageIDPointer = chosenLanguageID;
    }
    *newGameSoundFileNamePointer = NewGameSoundTextCtrl->GetLabel();
    *makingMoveSoundFileNamePointer = MakingMoveSoundTextCtrl->GetLabel();
    *lostGameSoundFileNamePointer = LostGameSoundTextCtrl->GetLabel();
    *newHiScoreSoundFileNamePointer = NewHiScoreSoundTextCtrl->GetLabel();
    wxString *parameters = new wxString[PARAMS_AMOUNT];
    parameters[0] = FILE_HEADER;
    parameters[1] = PARAM_1 + wxString::Format(wxT("%d"), chosenLanguageID);
    parameters[2] = PARAM_2 + NewGameSoundTextCtrl->GetLabel();
    parameters[3] = PARAM_3 + MakingMoveSoundTextCtrl->GetLabel();
    parameters[4] = PARAM_4 + LostGameSoundTextCtrl->GetLabel();
    parameters[5] = PARAM_5 + NewHiScoreSoundTextCtrl->GetLabel();
    ConfigFile *newConfigFile = new ConfigFile();
    newConfigFile->WriteFileContents(parameters);
    wxDELETE(newConfigFile);
}

void OptionsDialog::OnOKButtonClick(wxCommandEvent& event)
{
    ApplySettings();
    Close();
}

void OptionsDialog::OnCancelButtonClick(wxCommandEvent& event)
{
    if(*languageIDPointer != chosenLanguageID)
        wxGetApp().OnSetLanguage(*languageIDPointer);
    Close();
}

void OptionsDialog::OnApplyButtonClick(wxCommandEvent& event)
{
    ApplySettings();
}

void OptionsDialog::OnChangeLanguageButtonClick(wxCommandEvent& event)
{
    short selectedLanguageID = wxGetApp().SelectLanguage();
    if(selectedLanguageID != wxLANGUAGE_UNKNOWN)
        chosenLanguageID = selectedLanguageID;
}
