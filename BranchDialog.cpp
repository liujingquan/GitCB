#include "BranchDialog.h"
#include "gitcommand.h"
#include <cbproject.h>
//(*InternalHeaders(BranchDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(BranchDialog)
//*)

BEGIN_EVENT_TABLE(BranchDialog,wxDialog)
	//(*EventTable(BranchDialog)
	//*)
END_EVENT_TABLE()

BranchDialog::BranchDialog(wxWindow* parent)
{
	//(*Initialize(BranchDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("BranchDialog"),_T("wxDialog"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	TextCtrl2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	StaticText3 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT3"));
	Choice1 = (wxChoice*)FindWindow(XRCID("ID_CHOICE1"));
	Button2 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
	Button3 = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));
	Button4 = (wxButton*)FindWindow(XRCID("ID_BUTTON4"));
	TextCtrl3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));

	Connect(XRCID("ID_BUTTON1"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BranchDialog::OnButton1Click1);
	Connect(XRCID("ID_BUTTON2"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BranchDialog::OnButton2Click1);
	Connect(XRCID("ID_BUTTON3"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BranchDialog::OnButton3Click);
	Connect(XRCID("ID_BUTTON4"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BranchDialog::OnButton4Click);
	//*)
	cbProject* project=Manager::Get()->GetProjectManager()->GetActiveProject();
	if(project->IsLoaded())
        TextCtrl1->SetValue(project->GetExecutionDir());
}

BranchDialog::~BranchDialog()
{
	//(*Destroy(BranchDialog)
	//*)
}

//push
void BranchDialog::OnButton2Click(wxCommandEvent& event)
{
    GitCommand::GetCommand()->push(Choice1->GetString(Choice1->GetSelection()));
}
//Add
void BranchDialog::OnButton1Click1(wxCommandEvent& event)
{
    GitCommand::GetCommand()->Execute(_T("git branch ")+TextCtrl2->GetValue(),TextCtrl3);
    Choice1->Append(TextCtrl2->GetValue());
}
//Push
void BranchDialog::OnButton2Click1(wxCommandEvent& event)
{
    wxString cmd=_T("git chechout ")+Choice1->GetString(Choice1->GetSelection());
    if(GitCommand::GetCommand()->Execute(cmd,TextCtrl3));
        GitCommand::GetCommand()->Execute(_T("git push"),TextCtrl3);
}
//Remove
void BranchDialog::OnButton3Click(wxCommandEvent& event)
{
    GitCommand::GetCommand()->Execute(_T("git branch -d ")+Choice1->GetString(Choice1->GetSelection()),TextCtrl3);
}
//Cancel
void BranchDialog::OnButton4Click(wxCommandEvent& event)
{
}
