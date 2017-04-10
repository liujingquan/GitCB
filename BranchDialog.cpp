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

	Connect(XRCID("ID_BUTTON1"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BranchDialog::OnButton1Click);
	Connect(XRCID("ID_BUTTON2"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BranchDialog::OnButton2Click);
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
void BranchDialog::OnButton1Click(wxCommandEvent& event)
{
    GitCommand::GetCommand()->Execute(_T("git branch ")+TextCtrl2->GetValue());
    Choice1->Append(TextCtrl2->GetValue());
}
