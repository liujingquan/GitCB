#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include<cbproject.h>
#include "GitCB.h"
#include"CommitmDialog.h"
#include <loggers.h>
#include"CloneDialog.h"
#include"BranchDialog.h"
#include"PushDialog.h"
#include"gitcommand.h"
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
	logSlot = Manager::Get()->GetLogManager()->SetLog(gitcblogger);
	Manager::Get()->GetLogManager()->Slot(logSlot).title = _T("Git");
	CodeBlocksLogEvent evtAdd1(cbEVT_ADD_LOG_WINDOW, gitcblogger, Manager::Get()->GetLogManager()->Slot(logSlot).title);
	Manager::Get()->ProcessEvent(evtAdd1);
    //Manager::Get()->GetLogManager()->Log(_("init"),logSlot);
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
    menu=menuBar->GetMenu(menuBar->FindMenu(_("Tools")));
    git=new wxMenu();
    currentrepository=new wxMenu();
    currentrepository->Append(commitid,_("&commit"));
    currentrepository->Append(branchid,_("&branch"));
   //menuBar->Insert(menuBar->FindMenu(_("&Tools"))+1,menu,wxT("&Team"));
    currentrepository->Append(pushid,_("&push"));
    git->Append(cloneid,_("&clone repository"));
    git->Append(newposid,_("&creat repository"));
    git->AppendSeparator();
    git->AppendSubMenu(currentrepository,_("&current repository"));
    menu->AppendSubMenu(git,_("&Git"));
    Connect(commitid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::showcommitdlg));
    Connect(cloneid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::showclonedlg));
    Connect(pushid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::showpushdlg));
    Connect(branchid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::showbranchdlg));
   // Connect(cloneid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::Clone));
    //The application is offering its menubar for your plugin,
    //to add any menu items you want...
    //Append any items you need in the menu...
    //NOTE: Be careful in here... The application's menubar is at your disposal.
    NotImplemented(_T("GitCB::BuildMenu()"));
}

void GitCB::BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data)
{
    menu->Append(initid,_T("&add to git"));
    Connect(initid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::setgitcb));
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
    if(!IsAttached())
        return;
    CloneDialog dialog(Manager::Get()->GetAppWindow());
    dialog.ShowModal();
}

void GitCB::showpushdlg(wxCommandEvent& event)
{
    if(!IsAttached()||!Is_loaded())
        return;
    PushDialog dialog(Manager::Get()->GetAppWindow());
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
    GitCommand::GetCommand()->init();
}
