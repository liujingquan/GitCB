#include "CommitDialog.h"
#include "gitcommand.h"
//(*InternalHeaders(CommitDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(CommitDialog)
//*)

BEGIN_EVENT_TABLE(CommitDialog,wxDialog)
	//(*EventTable(CommitDialog)
	//*)
END_EVENT_TABLE()

CommitDialog::CommitDialog(wxWindow* parent)
{
	//(*Initialize(CommitDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("CommitDialog"),_T("wxDialog"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	TextCtrl2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	TextCtrl3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));
	CheckListBox1 = (wxCheckListBox*)FindWindow(XRCID("ID_CHECKLISTBOX2"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	//*)
}

CommitDialog::~CommitDialog()
{
	//(*Destroy(CommitDialog)
	//*)
}


void CommitDialog::OnButton2Click(wxCommandEvent& event)
{

}

void CommitDialog::OnButton1Click(wxCommandEvent& event)
{

}
