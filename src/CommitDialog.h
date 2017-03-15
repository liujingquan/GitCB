#ifndef COMMITDIALOG_H
#define COMMITDIALOG_H

//(*Headers(CommitDialog)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CommitDialog: public wxDialog
{
	public:

		CommitDialog(wxWindow* parent);
		virtual ~CommitDialog();

		//(*Declarations(CommitDialog)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxCheckListBox* CheckListBox1;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(CommitDialog)
		//*)

	private:

		//(*Handlers(CommitDialog)
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
