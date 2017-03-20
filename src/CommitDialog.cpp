#include "CommitDialog.h"

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
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	Button2 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
	CheckListBox1 = (wxCheckListBox*)FindWindow(XRCID("ID_CHECKLISTBOX1"));
	TextCtrl2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	Button3 = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));
	Button4 = (wxButton*)FindWindow(XRCID("ID_BUTTON4"));

	Connect(XRCID("ID_BUTTON2"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitDialog::OnButton2Click);
	//*)
}

CommitDialog::~CommitDialog()
{
	//(*Destroy(CommitDialog)
	//*)
}


void CommitDialog::OnButton2Click(wxCommandEvent& event)
{
    wxDirDialog dialog(this,wxDirSelectorPromptStr,wxEmptyString);
    if (dialog.ShowModal()=wxID_OK)
    {
        TextCtrl1->SetValue(dialog.GetPath());
    }
}
