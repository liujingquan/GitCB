#ifndef CLONEDIALOG_H
#define CLONEDIALOG_H

//(*Headers(CloneDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class CloneDialog: public wxDialog
{
	public:

		CloneDialog(wxWindow* parent);
		virtual ~CloneDialog();
		bool cloneclick=false;

		//(*Declarations(CloneDialog)
		wxButton* Button1;
		wxButton* Button2;
		wxSlider* Slider1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
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
		void OnButton1Click2(wxCommandEvent& event);
		void OnButton2Click2(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
