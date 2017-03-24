#include "CommitDialog.h"
#include "gitcommand.h"
//(*InternalHeaders(CommitDialog)
#include <wx/xrc/xmlres.h>
//*)
#include<wx/filedlg.h>
#include<cbproject.h>
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
	TextCtrl3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	Button5 = (wxButton*)FindWindow(XRCID("ID_BUTTON5"));
	Button4 = (wxButton*)FindWindow(XRCID("ID_BUTTON4"));
	Button3 = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));

	Connect(XRCID("ID_BUTTON2"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitDialog::OnButton2Click);
	Connect(XRCID("ID_CHECKLISTBOX1"),wxEVT_COMMAND_CHECKLISTBOX_TOGGLED,(wxObjectEventFunction)&CommitDialog::OnCheckListBox1Toggled);
	Connect(XRCID("ID_TEXTCTRL2"),wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CommitDialog::OnTextCtrl2Text3);
	//*)
	cbProject* project=Manager::Get()->GetProjectManager()->GetActiveProject();
	if(project->IsLoaded())
	{
    for(unsigned int i=0;i<project->GetFilesCount();i++)
        CheckListBox1->Append(project->GetFile(i)->relativeFilename);
     TextCtrl1->SetValue(project->GetExecutionDir());
    }
}

CommitDialog::~CommitDialog()
{
	//(*Destroy(CommitDialog)
	//*)
}

//Browse the directory and insert items
void CommitDialog::OnButton2Click(wxCommandEvent& event)
{
    wxFileDialog dialog(this,wxFileSelectorPromptStr,wxEmptyString,wxEmptyString,wxFileSelectorDefaultWildcardStr);
    if (dialog.ShowModal())
    {
        const wxString filename=dialog.GetFilename();
        TextCtrl1->SetValue(dialog.GetDirectory());
        //for(unsigned int i=0;i<=CheckListBox1->GetCount();i++)
        CheckListBox1->InsertItems(1,&filename,0);
    }
}
//commit file
void CommitDialog::OnButton1Click(wxCommandEvent& event)
{
    for(unsigned int i=0;i<CheckListBox1->GetCount();++i)
    {
        if (CheckListBox1->IsChecked(i))
        {
            GitCommand::GetCommand()->add(CheckListBox1->GetString(i));
        }
    }
    GitCommand::GetCommand()->commit(TextCtrl2->GetValue());
}
//checklistbox
void CommitDialog::OnCheckListBox1Toggled(wxCommandEvent& event)
{

}
//cancel button
void CommitDialog::OnButton4Click(wxCommandEvent& event)
{
   //CommitDialog dialog;
   //dialog.DestroyGripper();
}
//comment text
void CommitDialog::OnTextCtrl2Text2(wxCommandEvent& event)
{
}
//directory text
void CommitDialog::OnTextCtrl1Text2(wxCommandEvent& event)
{
}

void CommitDialog::OnTextCtrl2Text3(wxCommandEvent& event)
{
}
