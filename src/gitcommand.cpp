#include"gitcommand.h"
#include <sdk.h>
#include <loggers.h>
#include "GitCB.h"
static GitCommand* Command_Instance=nullptr;

GitCommand::GitCommand()
{

}

GitCommand::~GitCommand()
{

}

bool GitCommand::Execute(const wxString& command,const wxString& comment)
{
    wxArrayString output;
    wxArrayString error;
#ifdef _WXMSW_
    wxExecute(command,output,error);
#else
    wxExecute(command,output,error);
#endif // _WXMSW_
    Manager::Get()->GetLogManager()->Log(comment,logSlot);
    return true;
}

GitCommand* GitCommand::GetCommand()
{
    if(!Command_Instance)
        Command_Instance=new GitCommand();
    return Command_Instance;
}

void GitCommand::init()
{
    Execute(_T("git init"),_("initializing"));
}

void GitCommand::add(wxString filename)
{
    Execute(_T("git add ")+filename,_("add to working area"));
}

void GitCommand::commit(wxString commit_message)
{
    Execute(_T("git commit -m ")+commit_message,_("committing"));
}

void GitCommand::clone(wxString link)
{
    if(!link.empty())
        Execute(_T("git clone ")+link,_("clone a remote repository"));
}

void GitCommand::config(wxString name,wxString e_mail)
{
    if (Execute(_T("git config --global user.name ")+name,_("configure your name")))
        Execute(_T("git config --global user.email ")+e_mail,_("configure your email"));
}

void GitCommand::cd(wxString dir)
{
    Execute(_T("cd ")+dir,_("/t"));
}

