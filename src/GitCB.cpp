#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include "GitCB.h"
#include"CommitDialog.h"

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
    // do whatever initialization you need for your plugin
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be TRUE...
    // You should check for it in other functions, because if it
    // is FALSE, it means that the application did *not* "load"
    // (see: does not need) this plugin...
}

void GitCB::OnRelease(bool appShutDown)
{
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...
}

void GitCB::BuildMenu(wxMenuBar* menuBar)
{
    wxMenu* menu=menuBar->GetMenu(menuBar->FindMenu(_("Tools")));
    wxMenu* git=new wxMenu();
   //menuBar->Insert(menuBar->FindMenu(_("&Tools"))+1,menu,wxT("&Team"));
    git->Append(commitid,_("&commit"));
    git->AppendSeparator();
    git->Append(cloneid,_("&clone"));
    menu->AppendSubMenu(git,_("&Git"));
    Connect(commitid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::Commit));
    Connect(cloneid,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GitCB::Clone));

    //The application is offering its menubar for your plugin,
    //to add any menu items you want...
    //Append any items you need in the menu...
    //NOTE: Be careful in here... The application's menubar is at your disposal.
    NotImplemented(_T("GitCB::BuildMenu()"));
}

void GitCB::BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data)
{
    //Some library module is ready to display a pop-up menu.
    //Check the parameter \"type\" and see which module it is
    //and append any items you need in the menu...
    //TIP: for consistency, add a separator as the first item...
    NotImplemented(_T("GitCB::BuildModuleMenu()"));
}

void GitCB::Execute(wxString command,wxArrayString output)
{
   /* wxstring dir;
    dir=Manager::Get()->GetProjectManager()->GetActiveProject();
    if(dir.empty())
        return -1;*/





}

void GitCB::Commit(wxCommandEvent& event)
{
    CommitDialog commit(Manager::Get()->GetAppWindow());

}

void GitCB::Clone(wxCommandEvent& event)
{

}

