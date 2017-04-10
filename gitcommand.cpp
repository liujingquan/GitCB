#include"gitcommand.h"
#include <sdk.h>
#include <loggers.h>
#include<wx/process.h>

static GitCommand* Command_Instance=nullptr;

GitCommand::GitCommand()
{

}

GitCommand::~GitCommand()
{
    delete GetCommand();
}

int GitCommand::Execute(const wxString& command)
{
#ifdef _WXMSW_
    long result=wxExecute(command,output,error);
#else
    long result=wxExecute(command,output,error);
#endif // _WXMSW_
    if(result!=0)
    {

        return 0;
    }else
    {
        return -1;
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
    Execute(_T("git init"));
}

void GitCommand::add(const wxString& filename)
{
    Execute(_T("git add ")+filename);
}

void GitCommand::commit(const wxString& commit_message)
{
    Execute(_T("git commit -m \"")+commit_message+_T("\""));
}

void GitCommand::clone(const wxString& link)
{
    if(!link.empty())
    {
        Execute(_T("git clone ")+link);
    }
}

void GitCommand::config(const wxString& name,const wxString& e_mail)
{
    Execute(_T("git config --global user.name ")+name);
    Execute(_T("git config --global user.email ")+e_mail);
}

void GitCommand::Diff()
{

}

void GitCommand::push(const wxString& remotebranch)
{
    Execute(_T("git push ")+remotebranch);
}

void GitCommand::rm(const wxString& filename)
{
    Execute(_T("git rm ")+filename);
}

void GitCommand::printmessage(wxTextCtrl& logtext)
{
    for(unsigned int i=0;i<output.GetCount();++i)
        logtext.AppendText(output[i]);
    for(unsigned int i=0;i<error.GetCount();++i)
        logtext.AppendText(error[i]);
}
