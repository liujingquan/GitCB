#ifndef PUSHDIALOG_H
#define PUSHDIALOG_H

//(*Headers(PushDialog)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class PushDialog: public wxDialog
{
	public:

		PushDialog(wxWindow* parent);
		virtual ~PushDialog();

		//(*Declarations(PushDialog)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxButton* Button3;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxChoice* Choice1;
		//*)

	protected:

		//(*Identifiers(PushDialog)
		//*)

	private:

		//(*Handlers(PushDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
