#ifndef COMMITMDIALOG_H
#define COMMITMDIALOG_H

//(*Headers(CommitmDialog)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CommitmDialog: public wxDialog
{
	public:

		CommitmDialog(wxWindow* parent);
		virtual ~CommitmDialog();

		//(*Declarations(CommitmDialog)
		wxButton* Button4;
		wxButton* Button1;
		wxCheckListBox* CheckListBox1;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxButton* Button3;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(CommitmDialog)
		//*)

	private:

		//(*Handlers(CommitmDialog)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnCheckListBox1Toggled(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
