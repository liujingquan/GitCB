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
		wxButton* Button4;
		wxButton* Button1;
		wxCheckListBox* CheckListBox1;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(CommitDialog)
		//*)

	private:

		//(*Handlers(CommitDialog)
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnCheckListBox1Toggled(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl1Text1(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnTextCtrl2Text1(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnTextCtrl2Text2(wxCommandEvent& event);
		void OnTextCtrl1Text2(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
