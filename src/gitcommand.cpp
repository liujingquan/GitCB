#include"gitcommand.h"

static GitCommand* Command_Instance=nullptr;

GitCommand::GitCommand()
{

}

GitCommand::~GitCommand()
{

}

void GitCommand::Execute(wxString& command,wxArrayString& output,wxArrayString& error)
{
#ifdef _WXMSW_
    wxExecute(command,output,error);
#else
    wxExecute(command,output,error);
#endif // _WXMSW_
}

GitCommand* GitCommand::GetCommand()
{
    if(!Command_Instance)
        Command_Instance=new GitCommand();
    return Command_Instance;
}

void GitCommand::init()
{
    Execute(_T("git init"));
}

void GitCommand::add()
{
    Execute(_T("git add"));
}

void GitCommand::commit()
{
    wxString message;
    Execute(_T("git commit -m ")+message);
}

void GitCommand::clone()
{

}

void GitCommand::config()
{

}

