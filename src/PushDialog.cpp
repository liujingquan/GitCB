#include "PushDialog.h"

//(*InternalHeaders(PushDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(PushDialog)
//*)

BEGIN_EVENT_TABLE(PushDialog,wxDialog)
	//(*EventTable(PushDialog)
	//*)
END_EVENT_TABLE()

PushDialog::PushDialog(wxWindow* parent)
{
	//(*Initialize(PushDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("PushDialog"),_T("wxDialog"));
	StaticText3 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT3"));
	TextCtrl2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	Button3 = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	Choice1 = (wxChoice*)FindWindow(XRCID("ID_CHOICE1"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	Button2 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
	//*)
}

PushDialog::~PushDialog()
{
	//(*Destroy(PushDialog)
	//*)
}

