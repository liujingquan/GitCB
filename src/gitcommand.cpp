#include"gitcommand.h"


static GitCommand* Command_Instance=nullptr;

GitCommand::GitCommand()
{

}

GitCommand::~GitCommand()
{

}

bool GitCommand::Execute(wxString command,wxArrayString output,wxArrayString error)
{
#ifdef _WXMSW_
    wxExecute(command,output,error);
#else
    wxExecute(command,output,error);
#endif // _WXMSW_
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
    Execute(_T("git init"),all_output,all_error);
}

void GitCommand::add()
{
    Execute(_T("git add"),all_output,all_error);
}

void GitCommand::commit(wxString commit_message)
{
    Execute(_T("git commit -m ")+commit_message,all_output,all_error);
}

void GitCommand::clone(wxString link)
{
    if(!link.empty())
        Execute(_T("git clone ")+link,all_output,all_error);
}

void GitCommand::config(wxString name,wxString e_mail)
{
    if (Execute(_T("git config --global user.name ")+name,all_output,all_error))
        Execute(_T("git config --global user.email ")+e_mail,all_output,all_error);
}

