#include "CloneDialog.h"
#include"gitcommand.h"
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

	Connect(XRCID("ID_TEXTCTRL1"),wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CloneDialog::OnTextCtrl1Text1);
	Connect(XRCID("ID_TEXTCTRL2"),wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CloneDialog::OnTextCtrl2Text1);
	Connect(XRCID("ID_BUTTON1"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CloneDialog::OnButton1Click1);
	Connect(XRCID("ID_BUTTON2"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CloneDialog::OnButton2Click1);
	//*)
}

CloneDialog::~CloneDialog()
{
	//(*Destroy(CloneDialog)
	//*)
}

void CloneDialog::OnTextCtrl2Text1(wxCommandEvent& event)
{
}

void CloneDialog::OnButton1Click1(wxCommandEvent& event)
{
    wxDirDialog Dialog(this,wxDirSelectorPromptStr,wxEmptyString);
    if(Dialog.ShowModal())
    {
        TextCtrl1->SetValue(Dialog.GetPath());
        wxSetWorkingDirectory(Dialog.GetPath());
        //GitCommand::GetCommand()->cd(Dialog.GetPath());
        //wxExecute(_T("cd /d")+Dialog.GetPath());
    }

}

void CloneDialog::OnTextCtrl1Text1(wxCommandEvent& event)
{
}

void CloneDialog::OnButton2Click1(wxCommandEvent& event)
{
    GitCommand::GetCommand()->clone(TextCtrl2->GetValue());
    //wxExecute(_T("git clone ")+TextCtrl2->GetValue());
}
