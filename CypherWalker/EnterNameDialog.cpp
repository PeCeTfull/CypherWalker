#include "EnterNameDialog.h"
#include "HiScoresFile.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(EnterNameDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(EnterNameDialog)
const long EnterNameDialog::ID_MAINSTATICTEXT = wxNewId();
const long EnterNameDialog::ID_NAMETEXTCTRL = wxNewId();
//*)

BEGIN_EVENT_TABLE(EnterNameDialog,wxDialog)
	//(*EventTable(EnterNameDialog)
	//*)
END_EVENT_TABLE()

EnterNameDialog::EnterNameDialog(int& finalScore, short& hiScoresPlace, wxString* hiScores, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	//(*Initialize(EnterNameDialog)
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Game over"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
	MainStaticText = new wxStaticText(this, ID_MAINSTATICTEXT, _("Congratulations! You\'ve made it into the Top 5 with %d points you\'ve got!\nPlease enter your name: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_MAINSTATICTEXT"));
	FlexGridSizer1->Add(MainStaticText, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	NameTextCtrl = new wxTextCtrl(this, ID_NAMETEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_NAMETEXTCTRL"));
	NameTextCtrl->SetMaxLength(50);
	FlexGridSizer1->Add(NameTextCtrl, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	OKButton = new wxButton(this, wxID_YES, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_YES"));
	OKButton->SetDefault();
	FlexGridSizer2->Add(OKButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
	CancelButton = new wxButton(this, wxID_OK, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	FlexGridSizer2->Add(CancelButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	Center();

	Connect(wxID_YES,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnterNameDialog::OnOKButtonClick);
	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnterNameDialog::OnCancelButtonClick);
	//*)
	MainStaticText->SetLabel(wxString::Format(wxT(MainStaticText->GetLabel()), finalScore));
	newFinalScore = finalScore;
	newHiScoresPlace = hiScoresPlace;
	newHiScores = hiScores;
}

EnterNameDialog::~EnterNameDialog()
{
	//(*Destroy(EnterNameDialog)
	//*)
}


void EnterNameDialog::OnOKButtonClick(wxCommandEvent& event)
{
    wxString newName = NameTextCtrl->GetLabel();
    if(newName.Contains('|'))
    {
        wxMessageBox(_("Your name consists of at least one vertical bar. Please remove them and try again."), _("Error"), wxICON_HAND);
        return;
    }
	switch(newHiScoresPlace)
    {
    case 1:
        newHiScores[8] = newHiScores[6];
        newHiScores[9] = newHiScores[7];
        newHiScores[6] = newHiScores[4];
        newHiScores[7] = newHiScores[5];
        newHiScores[4] = newHiScores[2];
        newHiScores[5] = newHiScores[3];
        newHiScores[2] = newHiScores[0];
        newHiScores[3] = newHiScores[1];

        newHiScores[0] = newName;
        newHiScores[1] = wxString::Format(wxT("%d"), newFinalScore);
        break;

    case 2:
        newHiScores[8] = newHiScores[6];
        newHiScores[9] = newHiScores[7];
        newHiScores[6] = newHiScores[4];
        newHiScores[7] = newHiScores[5];
        newHiScores[4] = newHiScores[2];
        newHiScores[5] = newHiScores[3];

        newHiScores[2] = newName;
        newHiScores[3] = wxString::Format(wxT("%d"), newFinalScore);
        break;

    case 3:
        newHiScores[8] = newHiScores[6];
        newHiScores[9] = newHiScores[7];
        newHiScores[6] = newHiScores[4];
        newHiScores[7] = newHiScores[5];

        newHiScores[4] = newName;
        newHiScores[5] = wxString::Format(wxT("%d"), newFinalScore);
        break;

    case 4:
        newHiScores[8] = newHiScores[6];
        newHiScores[9] = newHiScores[7];

        newHiScores[6] = newName;
        newHiScores[7] = wxString::Format(wxT("%d"), newFinalScore);
        break;

    case 5:
        newHiScores[8] = newName;
        newHiScores[9] = wxString::Format(wxT("%d"), newFinalScore);
        break;

    default:
        break;
    }
    HiScoresFile *updateHiScoresFile = new HiScoresFile();
    updateHiScoresFile->WriteFileContents(newHiScores);
    wxDELETE(updateHiScoresFile);
    Close();
}

void EnterNameDialog::OnCancelButtonClick(wxCommandEvent& event)
{
    Close();
}
