#ifndef HISCORESDIALOG_H
#define HISCORESDIALOG_H

//(*Headers(HiScoresDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class HiScoresDialog: public wxDialog
{
	public:

		HiScoresDialog(wxWindow* parent, wxWindowID id=wxID_ANY);
		virtual ~HiScoresDialog();

		//(*Declarations(HiScoresDialog)
		wxStaticText* NameStaticText4;
		wxButton* EraseAllButton;
		wxStaticText* ScoreStaticText4;
		wxStaticText* NameStaticText5;
		wxButton* OKButton;
		wxStaticText* NameStaticText1;
		wxStaticText* ScoreStaticText5;
		wxStaticText* HallOfFameStaticText;
		wxStaticText* ScoreStaticText1;
		wxStaticText* NameStaticText2;
		wxStaticText* NameStaticText3;
		wxStaticText* ScoreStaticText3;
		wxStaticText* ScoreStaticText2;
		//*)

	protected:

		//(*Identifiers(HiScoresDialog)
		static const long ID_HALLOFFAMESTATICTEXT;
		static const long ID_NAMESTATICTEXT1;
		static const long ID_SCORESTATICTEXT1;
		static const long ID_NAMESTATICTEXT2;
		static const long ID_SCORESTATICTEXT2;
		static const long ID_NAMESTATICTEXT3;
		static const long ID_SCORESTATICTEXT3;
		static const long ID_NAMESTATICTEXT4;
		static const long ID_SCORESTATICTEXT4;
		static const long ID_NAMESTATICTEXT5;
		static const long ID_SCORESTATICTEXT5;
		static const long ID_ERASEALLBUTTON;
		//*)

	private:

		//(*Handlers(HiScoresDialog)
		void OnOKButtonClick(wxCommandEvent& event);
		void OnEraseAllButtonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
