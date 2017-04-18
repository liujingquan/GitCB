#include "CommitmDialog.h"
#include "gitcommand.h"
#include<cbproject.h>
#include<wx/filedlg.h>
#include<wx/filefn.h>

//(*InternalHeaders(CommitmDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(CommitmDialog)
//*)

BEGIN_EVENT_TABLE(CommitmDialog,wxDialog)
	//(*EventTable(CommitmDialog)
	//*)
END_EVENT_TABLE()

CommitmDialog::CommitmDialog(wxWindow* parent)
{
	//(*Initialize(CommitmDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("CommitmDialog"),_T("wxDialog"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	CheckListBox1 = (wxCheckListBox*)FindWindow(XRCID("ID_CHECKLISTBOX1"));
	TextCtrl2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	TextCtrl3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));
	Button2 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
	Button5 = (wxButton*)FindWindow(XRCID("ID_BUTTON5"));
	Button3 = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));
	Button4 = (wxButton*)FindWindow(XRCID("ID_BUTTON4"));

	Connect(XRCID("ID_TEXTCTRL1"),wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CommitmDialog::OnTextCtrl1Text1);
	Connect(XRCID("ID_BUTTON1"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitmDialog::OnButton1Click);
	Connect(XRCID("ID_BUTTON2"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitmDialog::OnButton2Click);
	Connect(XRCID("ID_BUTTON5"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitmDialog::OnButton5Click);
	Connect(XRCID("ID_BUTTON3"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitmDialog::OnButton3Click);
	//*)
	cbProject* project=Manager::Get()->GetProjectManager()->GetActiveProject();
	if(project->IsLoaded())
	{
    for(unsigned int i=0;i<project->GetFilesCount();i++)
        CheckListBox1->Append(project->GetFile(i)->relativeFilename);
    TextCtrl1->SetValue(project->GetExecutionDir());
    }
}

CommitmDialog::~CommitmDialog()
{
	//(*Destroy(CommitmDialog)
	//*)
}

//Browse
void CommitmDialog::OnButton1Click(wxCommandEvent& event)
{
    wxFileDialog dialog(this,wxFileSelectorPromptStr,wxEmptyString,wxEmptyString,wxFileSelectorDefaultWildcardStr);
    if (dialog.ShowModal())
    {
        const wxString filename=dialog.GetFilename();
        TextCtrl1->SetValue(dialog.GetDirectory());
        CheckListBox1->Append(filename);
    }
}
//Commit
void CommitmDialog::OnButton2Click(wxCommandEvent& event)
{
    wxString cmd=_T("git commit -m \"")+TextCtrl2->GetValue()+_T("\"");
    wxArrayInt items=0;
    wxArrayInt::iterator iter;
    CheckListBox1->GetCheckedItems(items);
    for(iter=items.begin();iter!=items.end();++iter)
        GitCommand::GetCommand()->add(CheckListBox1->GetString((*iter)));
    //GitCommand::GetCommand()->commit(TextCtrl2->GetValue());
    //GitCommand::GetCommand()->printmessage(TextCtrl3);
    GitCommand::GetCommand()->Execute(cmd,TextCtrl3);
}

void CommitmDialog::OnCheckListBox1Toggled(wxCommandEvent& event)
{
}

void CommitmDialog::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void CommitmDialog::OnTextCtrl1Text1(wxCommandEvent& event)
{
}

void CommitmDialog::OnButton5Click(wxCommandEvent& event)
{
    wxArrayInt items=0;
    wxArrayInt::iterator iter;
    CheckListBox1->GetCheckedItems(items);
    for(iter=items.begin();iter!=items.end();++iter)
    {
        CheckListBox1->Delete((*iter));
        GitCommand::GetCommand()->rm(CheckListBox1->GetString((*iter)));
    }
}
//diff
void CommitmDialog::OnButton3Click(wxCommandEvent& event)
{
    wxArrayInt items=0;
    wxArrayInt::iterator iter;
    CheckListBox1->GetCheckedItems(items);
    for(iter=items.begin();iter!=items.end();++iter)
    {
        GitCommand::GetCommand()->Execute(_T("git diff ")+CheckListBox1->GetString((*iter)),TextCtrl3);
    }
}
