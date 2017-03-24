#ifndef BRANCHDIALOG_H
#define BRANCHDIALOG_H

//(*Headers(BranchDialog)
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>
#include <wx/choicebk.h>
//*)

class BranchDialog: public wxDialog
{
	public:

		BranchDialog(wxWindow* parent);
		virtual ~BranchDialog();

		//(*Declarations(BranchDialog)
		wxChoicebook* Choicebook1;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(BranchDialog)
		//*)

	private:

		//(*Handlers(BranchDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
