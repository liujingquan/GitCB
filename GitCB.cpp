#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include <cbproject.h>
#include <loggers.h>
#include "GitCB.h"
#include "CommitmDialog.h"
#include "CloneDialog.h"
#include "BranchDialog.h"
#include "PushDialog.h"
#include "gitcommand.h"
// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
    PluginRegistrant<GitCB> reg(_T("GitCB"));
}

// events handling
BEGIN_EVENT_TABLE(GitCB, cbPlugin)
    // add any events you want to handle here
END_EVENT_TABLE()

// constructor
GitCB::GitCB()
{
    // Make sure our resources are available.
    // In the generated boilerplate code we have no resources but when
    // we add some, it will be nice that this code is in place already ;)
    if(!Manager::LoadResource(_T("GitCB.zip")))
    {
        NotifyMissingFile(_T("GitCB.zip"));
    }
}

// destructor
GitCB::~GitCB()
{

}

void GitCB::OnAttach()
{
    gitcblogger=new TextCtrlLogger();
	logSlot = Manager::Get()->GetLogManager()->SetLog(gitcblogger,1);
	Manager::Get()->GetLogManager()->Slot(logSlot).title = _T("Git");
	CodeBlocksLogEvent evtAdd1(cbEVT_ADD_LOG_WINDOW, gitcblogger, Manager::Get()->GetLogManager()->Slot(logSlot).title);
	Manager::Get()->ProcessEvent(evtAdd1);
    // do whatever initialization you need for your plugin
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be TRUE...
    // You should check for it in other functions, because if it
    // is FALSE, it means that the application did *not* "load"
    // (see: does not need) this plugin...
}

void GitCB::OnRelease(bool appShutDown)
{
    CodeBlocksLogEvent evt(cbEVT_REMOVE_LOG_WINDOW,gitcblogger);
    Manager::Get()->ProcessEvent(evt);
    gitcblogger=0;
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...
}

void GitCB::BuildMenu(wxMenuBar* menuBar)
{
    wxMenu* git=new wxMenu();
    wxMenu* menu=new wxMenu();
    wxMenu* currentrepository=new wxMenu();
    menu=menuBar->GetMenu(menuBar->FindMenu(_("Tools")));
    currentrepository->Append(commitid,_("&commit"));
    currentrepository->Append(branchid,_("&branch"));
    git->Append(cloneid,_("&clone repository"));
    git->Append(newposid,_("&creat repository"));
    git->AppendSeparator();
    git->AppendSubMenu(currentrepository,_("&current repository"));
    menu->AppendSubMenu(git,_("&Git"));
    Connect(commitid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::showcommitdlg));
    Connect(cloneid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::showclonedlg));
    Connect(branchid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::showbranchdlg));
    //The application is offering its menubar for your plugin,
    //to add any menu items you want...
    //Append any items you need in the menu...
    //NOTE: Be careful in here... The application's menubar is at your disposal.
    NotImplemented(_T("GitCB::BuildMenu()"));
}

void GitCB::BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data)
{
    wxMenu* gitmodule=new wxMenu();
    gitmodule->Append(moduleinitid,_T("&Add to git"));
    gitmodule->Append(modulecommitid,_T("&commit all files"));
    gitmodule->Append(modulepushid,_T("&push"));
    gitmodule->Append(modulestatusid,_T("&status"));
    menu->AppendSubMenu(gitmodule,_T("&git"));
    Connect(moduleinitid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::setgitcb));
    Connect(modulecommitid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::commit));
    Connect(modulepushid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::push));
    Connect(modulestatusid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::status));
    //Some library module is ready to display a pop-up menu.
    //Check the parameter \"type\" and see which module it is
    //and append any items you need in the menu...
    //TIP: for consistency, add a separator as the first item...
    NotImplemented(_T("GitCB::BuildModuleMenu()"));
}

void GitCB::showcommitdlg(wxCommandEvent& event)
{
    if(!IsAttached()||!Is_loaded())
        return;
    CommitmDialog dialog(Manager::Get()->GetAppWindow());
    dialog.ShowModal();
}

void GitCB::showclonedlg(wxCommandEvent& event)
{
    if(!IsAttached()||!Is_loaded())
        return;
    CloneDialog dialog(Manager::Get()->GetAppWindow());
    dialog.ShowModal();

}

void GitCB::showbranchdlg(wxCommandEvent& event)
{
    if(!IsAttached()||!Is_loaded())
        return;
    BranchDialog dialog(Manager::Get()->GetAppWindow());
    dialog.ShowModal();
}

bool GitCB::Is_loaded()
{
    cbProject* project=Manager::Get()->GetProjectManager()->GetActiveProject();
    if(!Manager::Get()->GetProjectManager()->IsProjectStillOpen(project))
    {
        wxMessageBox(wxT("you need open a project first"),wxMessageBoxCaptionStr);
        return false;
    }
    return true;
}

void GitCB::setgitcb(wxCommandEvent& event)
{
    if(!IsAttached()||!Is_loaded())
        return;
    cbProject* m_project=Manager::Get()->GetProjectManager()->GetActiveProject();
    wxSetWorkingDirectory(m_project->GetExecutionDir());
    Execute(_T("git init"));
}
void GitCB::printmessage(const wxArrayString& m_output)
{
    logSlot=Manager::Get()->GetLogManager()->FindIndex(gitcblogger);
    CodeBlocksLogEvent evt(cbEVT_SWITCH_TO_LOG_WINDOW,gitcblogger);
    Manager::Get()->ProcessEvent(evt);
    for(size_t i=0;i<m_output.GetCount();++i)
        Manager::Get()->GetLogManager()->Log(m_output[i],logSlot);
}

int GitCB::Execute(const wxString& command)
{
    wxArrayString error;
    wxArrayString output;
    cbProject* m_project=Manager::Get()->GetProjectManager()->GetActiveProject();
    wxSetWorkingDirectory(m_project->GetExecutionDir());
#ifdef _WXMSW_
    long result=wxExecute(command,output,error);
#else
    long result=wxExecute(command,output,error);
#endif // _WXMSW_
    if(result!=0)
    {
        printmessage(output);
        return 0;
    }else
    {
        printmessage(error);
        return -1;
    }
}

void GitCB::commit(wxCommandEvent& event)
{
    if(!IsAttached()||!Is_loaded())
        return;
    cbProject* m_project=Manager::Get()->GetProjectManager()->GetActiveProject();
    for(int i=0;i<m_project->GetFilesCount();++i)
    {
        wxString file=m_project->GetFile(i)->relativeFilename;
        Execute(_T("git add ")+file);
    }
    Execute(_T("git commit -m commit"));
}

void GitCB::push(wxCommandEvent& event)
{
    if(!IsAttached()||!Is_loaded())
        return;
    Execute(_T("git push"));
}

void GitCB::status(wxCommandEvent& event)
{
    if(!IsAttached()||!Is_loaded())
        return;
    Execute(_T("git status"));
}


