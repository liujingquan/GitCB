#include"gitcommand.h"
#include <sdk.h>
#include <loggers.h>

static GitCommand* Command_Instance=nullptr;

GitCommand::GitCommand()
{

}

GitCommand::~GitCommand()
{
    delete GetCommand();
}

void GitCommand::Execute(const wxString& command,const wxString& comment)
{
    wxArrayString output;
    wxArrayString error;
#ifdef _WXMSW_
    long result=wxExecute(command,output,error);
#else
    long result=wxExecute(command,output,error);
#endif // _WXMSW_
    if(result!=0)
    {
    for(size_t i=0;i<output.GetCount();++i)
        Manager::Get()->GetLogManager()->Log(output[i],a.logSlot);
    }else
    {
    for(size_t i=0;i<error.GetCount();++i)
        Manager::Get()->GetLogManager()->Log(error[i],a.logSlot);
    }

}

GitCommand* GitCommand::GetCommand()
{
    if(!Command_Instance)
        Command_Instance=new GitCommand();
    return Command_Instance;
}

void GitCommand::init()
{
    Execute(_T("git init "),_("initializing  a repository..."));
}

void GitCommand::add(const wxString& filename)
{
    Execute(_T("git add ")+filename,_("add to working area"));
}

void GitCommand::commit(const wxString& commit_message)
{
    Execute(_T("git commit -m ")+commit_message,_("committing..."));
}

void GitCommand::clone(const wxString& link)
{
    if(!link.empty())
        Execute(_T("git clone ")+link,_("clone a remote repository"));

}

void GitCommand::config(const wxString& name,const wxString& e_mail)
{
    Execute(_T("git config --global user.name ")+name,_("configure your name"));
    Execute(_T("git config --global user.email ")+e_mail,_("configure your email"));
}

void GitCommand::Diff()
{

}

void GitCommand::push()
{
    Execute(_T("git push"),_("push to master"));
}

wxString GitCommand::status()
{
}
