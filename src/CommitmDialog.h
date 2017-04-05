#ifndef COMMITMDIALOG_H
#define COMMITMDIALOG_H

//(*Headers(CommitmDialog)
#include <wx/button.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class CommitmDialog: public wxDialog
{
	public:

		CommitmDialog(wxWindow* parent);
		virtual ~CommitmDialog();

		//(*Declarations(CommitmDialog)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxCheckListBox* CheckListBox1;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
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
		void OnTextCtrl1Text1(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
