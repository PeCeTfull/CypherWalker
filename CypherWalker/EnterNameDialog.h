#ifndef ENTERNAMEDIALOG_H
#define ENTERNAMEDIALOG_H

#include "HiScoresFile.h"

//(*Headers(EnterNameDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class EnterNameDialog: public wxDialog
{
	public:

		EnterNameDialog(int& finalScore, short& hiScoresPlace, wxString* hiScores, wxWindow* parent, wxWindowID id=wxID_ANY, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize);
		virtual ~EnterNameDialog();

		//(*Declarations(EnterNameDialog)
		wxTextCtrl* NameTextCtrl;
		wxButton* OKButton;
		wxStaticText* MainStaticText;
		wxButton* CancelButton;
		//*)

	protected:

		//(*Identifiers(EnterNameDialog)
		static const long ID_MAINSTATICTEXT;
		static const long ID_NAMETEXTCTRL;
		//*)

	private:

	    int newFinalScore;
	    short newHiScoresPlace;
	    wxString *newHiScores;

		//(*Handlers(EnterNameDialog)
		void OnOKButtonClick(wxCommandEvent& event);
		void OnCancelButtonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
