#include "HiScoresDialog.h"
#include "HiScoresFile.h"

//(*InternalHeaders(HiScoresDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(HiScoresDialog)
const long HiScoresDialog::ID_HALLOFFAMESTATICTEXT = wxNewId();
const long HiScoresDialog::ID_NAMESTATICTEXT1 = wxNewId();
const long HiScoresDialog::ID_SCORESTATICTEXT1 = wxNewId();
const long HiScoresDialog::ID_NAMESTATICTEXT2 = wxNewId();
const long HiScoresDialog::ID_SCORESTATICTEXT2 = wxNewId();
const long HiScoresDialog::ID_NAMESTATICTEXT3 = wxNewId();
const long HiScoresDialog::ID_SCORESTATICTEXT3 = wxNewId();
const long HiScoresDialog::ID_NAMESTATICTEXT4 = wxNewId();
const long HiScoresDialog::ID_SCORESTATICTEXT4 = wxNewId();
const long HiScoresDialog::ID_NAMESTATICTEXT5 = wxNewId();
const long HiScoresDialog::ID_SCORESTATICTEXT5 = wxNewId();
const long HiScoresDialog::ID_ERASEALLBUTTON = wxNewId();
//*)

BEGIN_EVENT_TABLE(HiScoresDialog,wxDialog)
	//(*EventTable(HiScoresDialog)
	//*)
END_EVENT_TABLE()

HiScoresDialog::HiScoresDialog(wxWindow* parent, wxWindowID id)
{
	//(*Initialize(HiScoresDialog)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("High scores"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
	HallOfFameStaticText = new wxStaticText(this, ID_HALLOFFAMESTATICTEXT, _("Hall of Fame"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_HALLOFFAMESTATICTEXT"));
	wxFont HallOfFameStaticTextFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	HallOfFameStaticText->SetFont(HallOfFameStaticTextFont);
	FlexGridSizer1->Add(HallOfFameStaticText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(5, 2, 0, 0);
	NameStaticText1 = new wxStaticText(this, ID_NAMESTATICTEXT1, _("Name 1"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE, _T("ID_NAMESTATICTEXT1"));
	NameStaticText1->SetMinSize(wxSize(300,14));
	NameStaticText1->SetMaxSize(wxSize(-1,14));
	FlexGridSizer2->Add(NameStaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ScoreStaticText1 = new wxStaticText(this, ID_SCORESTATICTEXT1, _("0"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE|wxALIGN_RIGHT, _T("ID_SCORESTATICTEXT1"));
	ScoreStaticText1->SetMinSize(wxSize(20,14));
	ScoreStaticText1->SetMaxSize(wxSize(20,14));
	FlexGridSizer2->Add(ScoreStaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	NameStaticText2 = new wxStaticText(this, ID_NAMESTATICTEXT2, _("Name 2"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE, _T("ID_NAMESTATICTEXT2"));
	NameStaticText2->SetMinSize(wxSize(300,14));
	NameStaticText2->SetMaxSize(wxSize(-1,14));
	FlexGridSizer2->Add(NameStaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ScoreStaticText2 = new wxStaticText(this, ID_SCORESTATICTEXT2, _("0"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE|wxALIGN_RIGHT, _T("ID_SCORESTATICTEXT2"));
	ScoreStaticText2->SetMinSize(wxSize(20,14));
	ScoreStaticText2->SetMaxSize(wxSize(20,14));
	FlexGridSizer2->Add(ScoreStaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	NameStaticText3 = new wxStaticText(this, ID_NAMESTATICTEXT3, _("Name 3"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE, _T("ID_NAMESTATICTEXT3"));
	NameStaticText3->SetMinSize(wxSize(300,14));
	NameStaticText3->SetMaxSize(wxSize(-1,14));
	FlexGridSizer2->Add(NameStaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ScoreStaticText3 = new wxStaticText(this, ID_SCORESTATICTEXT3, _("0"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE|wxALIGN_RIGHT, _T("ID_SCORESTATICTEXT3"));
	ScoreStaticText3->SetMinSize(wxSize(20,14));
	ScoreStaticText3->SetMaxSize(wxSize(20,14));
	FlexGridSizer2->Add(ScoreStaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	NameStaticText4 = new wxStaticText(this, ID_NAMESTATICTEXT4, _("Name 4"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE, _T("ID_NAMESTATICTEXT4"));
	NameStaticText4->SetMinSize(wxSize(300,14));
	NameStaticText4->SetMaxSize(wxSize(-1,14));
	FlexGridSizer2->Add(NameStaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ScoreStaticText4 = new wxStaticText(this, ID_SCORESTATICTEXT4, _("0"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE|wxALIGN_RIGHT, _T("ID_SCORESTATICTEXT4"));
	ScoreStaticText4->SetMinSize(wxSize(20,14));
	ScoreStaticText4->SetMaxSize(wxSize(20,14));
	FlexGridSizer2->Add(ScoreStaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	NameStaticText5 = new wxStaticText(this, ID_NAMESTATICTEXT5, _("Name 5"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE, _T("ID_NAMESTATICTEXT5"));
	NameStaticText5->SetMinSize(wxSize(300,14));
	NameStaticText5->SetMaxSize(wxSize(-1,14));
	FlexGridSizer2->Add(NameStaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ScoreStaticText5 = new wxStaticText(this, ID_SCORESTATICTEXT5, _("0"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE|wxALIGN_RIGHT, _T("ID_SCORESTATICTEXT5"));
	ScoreStaticText5->SetMinSize(wxSize(20,14));
	ScoreStaticText5->SetMaxSize(wxSize(20,14));
	FlexGridSizer2->Add(ScoreStaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	OKButton = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	OKButton->SetDefault();
	FlexGridSizer3->Add(OKButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
	EraseAllButton = new wxButton(this, ID_ERASEALLBUTTON, _("&Erase all"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_ERASEALLBUTTON"));
	FlexGridSizer3->Add(EraseAllButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	Center();

	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HiScoresDialog::OnOKButtonClick);
	Connect(ID_ERASEALLBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HiScoresDialog::OnEraseAllButtonClick);
	//*)

    HiScoresFile *newHiScoresFile = new HiScoresFile();
    wxString *currentHiScores = newHiScoresFile->ReadFileContents();
    wxDELETE(newHiScoresFile);
    NameStaticText1->SetLabel(currentHiScores[0]);
    ScoreStaticText1->SetLabel(currentHiScores[1]);
    NameStaticText2->SetLabel(currentHiScores[2]);
    ScoreStaticText2->SetLabel(currentHiScores[3]);
    NameStaticText3->SetLabel(currentHiScores[4]);
    ScoreStaticText3->SetLabel(currentHiScores[5]);
    NameStaticText4->SetLabel(currentHiScores[6]);
    ScoreStaticText4->SetLabel(currentHiScores[7]);
    NameStaticText5->SetLabel(currentHiScores[8]);
    ScoreStaticText5->SetLabel(currentHiScores[9]);
}

HiScoresDialog::~HiScoresDialog()
{
	//(*Destroy(HiScoresDialog)
	//*)
}


void HiScoresDialog::OnOKButtonClick(wxCommandEvent& event)
{
    Close();
}

void HiScoresDialog::OnEraseAllButtonClick(wxCommandEvent& event)
{
    HiScoresFile *resetHiScoresFile = new HiScoresFile();
    resetHiScoresFile->NewFileContents();
    wxString *cleanHiScores = resetHiScoresFile->ReadFileContents();
    wxDELETE(resetHiScoresFile);
    NameStaticText1->SetLabel(cleanHiScores[0]);
    ScoreStaticText1->SetLabel(cleanHiScores[1]);
    NameStaticText2->SetLabel(cleanHiScores[2]);
    ScoreStaticText2->SetLabel(cleanHiScores[3]);
    NameStaticText3->SetLabel(cleanHiScores[4]);
    ScoreStaticText3->SetLabel(cleanHiScores[5]);
    NameStaticText4->SetLabel(cleanHiScores[6]);
    ScoreStaticText4->SetLabel(cleanHiScores[7]);
    NameStaticText5->SetLabel(cleanHiScores[8]);
    ScoreStaticText5->SetLabel(cleanHiScores[9]);
}
