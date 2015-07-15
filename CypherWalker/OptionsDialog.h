#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <wx/string.h>

//(*Headers(OptionsDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class OptionsDialog: public wxDialog
{
	public:

		OptionsDialog(short& languageID, wxString& newGameSoundFileName, wxString& makingMoveSoundFileName, wxString& lostGameSoundFileName, wxString& newHiScoreSoundFileName, wxWindow* parent, wxWindowID id=wxID_ANY, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize);
		virtual ~OptionsDialog();

		//(*Declarations(OptionsDialog)
		wxButton* OKButton;
		wxButton* ApplyButton;
		wxStaticText* NewGameSoundStaticText;
		wxStaticText* NewHiScoreSoundStaticText;
		wxTextCtrl* NewHiScoreSoundTextCtrl;
		wxButton* ChangeLanguageButton;
		wxTextCtrl* MakingMoveSoundTextCtrl;
		wxStaticLine* StaticLine1;
		wxStaticText* MakingMoveSoundStaticText;
		wxButton* CancelButton;
		wxTextCtrl* NewGameSoundTextCtrl;
		wxStaticText* CurrentLanguageStaticText;
		wxTextCtrl* LostGameSoundTextCtrl;
		wxStaticText* LostGameSoundStaticText;
		//*)

	protected:

		//(*Identifiers(OptionsDialog)
		static const long ID_NEWGAMESOUNDSTATICTEXT;
		static const long ID_NEWGAMESOUNDTEXTCTRL;
		static const long ID_MAKINGMOVESOUNDSTATICTEXT;
		static const long ID_MAKINGMOVESOUNDTEXTCTRL;
		static const long ID_LOSTGAMESOUNDSTATICTEXT;
		static const long ID_LOSTGAMESOUNDTEXTCTRL;
		static const long ID_NEWHISCORESOUNDSTATICTEXT;
		static const long ID_NEWHISCORESOUNDTEXTCTRL;
		static const long ID_STATICLINE1;
		static const long ID_CURRENTLANGUAGESTATICTEXT;
		static const long ID_CHANGELANGUAGEBUTTON;
		static const long ID_APPLYBUTTON;
		//*)

	private:

        void ApplySettings();
		short *languageIDPointer;
        wxString *newGameSoundFileNamePointer;
        wxString *makingMoveSoundFileNamePointer;
        wxString *lostGameSoundFileNamePointer;
        wxString *newHiScoreSoundFileNamePointer;
		short chosenLanguageID;

		//(*Handlers(OptionsDialog)
		void OnOKButtonClick(wxCommandEvent& event);
		void OnCancelButtonClick(wxCommandEvent& event);
		void OnApplyButtonClick(wxCommandEvent& event);
		void OnChangeLanguageButtonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
