#ifndef CLONEDIALOG_H
#define CLONEDIALOG_H

//(*Headers(CloneDialog)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CloneDialog: public wxDialog
{
	public:

		CloneDialog(wxWindow* parent);
		virtual ~CloneDialog();

		//(*Declarations(CloneDialog)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(CloneDialog)
		//*)

	private:

		//(*Handlers(CloneDialog)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnTextCtrl2Text1(wxCommandEvent& event);
		void OnTextCtrl1Text1(wxCommandEvent& event);
		void OnButton1Click1(wxCommandEvent& event);
		void OnButton2Click1(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
