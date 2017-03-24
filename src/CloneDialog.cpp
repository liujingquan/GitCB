#include "CloneDialog.h"

//(*InternalHeaders(CloneDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(CloneDialog)
//*)

BEGIN_EVENT_TABLE(CloneDialog,wxDialog)
	//(*EventTable(CloneDialog)
	//*)
END_EVENT_TABLE()

CloneDialog::CloneDialog(wxWindow* parent)
{
	//(*Initialize(CloneDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("CloneDialog"),_T("wxDialog"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	TextCtrl2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	Button2 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
	//*)
}

CloneDialog::~CloneDialog()
{
	//(*Destroy(CloneDialog)
	//*)
}

