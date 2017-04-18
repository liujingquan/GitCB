#include"gitcommand.h"
#include <sdk.h>
#include <wx/sstream.h>
static GitCommand* Command_Instance=nullptr;

GitCommand::GitCommand()
    :process(NULL)
{
}

GitCommand::~GitCommand()
{
    delete process;
}

int GitCommand::Execute(const wxString& command,wxTextCtrl* text)
{
    process=new wxProcess(wxPROCESS_REDIRECT);
    wxString log;
#ifdef _WXMSW_
    long result=wxExecute(command,wxEXEC_ASYNC,process);
#else
    long result=wxExecute(command,wxEXEC_ASYNC,process);
#endif // _WXMSW_
    process->Redirect();
    if(process)
    {
        wxInputStream *msg=process->GetInputStream();
        wxTextInputStream InputStream(*msg);
        while(!msg->Eof())
        {
            log=InputStream.ReadLine();
            text->AppendText(log+wxT("\n"));
        }
        return 0;
    }else
    {
        text->AppendText(_("can't execute command!"));
        return -1;
    }
}
int GitCommand::Execute(const wxString& command)
{
    process=new wxProcess(wxPROCESS_REDIRECT);
#ifdef _WXMSW_
    long result=wxExecute(command,wxEXEC_ASYNC,process);
#else
    long result=wxExecute(command,wxEXEC_ASYNC,process);
#endif // _WXMSW_
    if(result)
    {
        return 1;
    }else
    {
        return 0;
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
    if(Execute(_T("git checkout")))
        Execute(_T("git push ")+remotebranch);
}

void GitCommand::rm(const wxString& filename)
{
    Execute(_T("git rm ")+filename);
}

void GitCommand::logmessage(TextCtrlLogger* logger,int slot)
{
    wxString log;
    wxInputStream *msg=process->GetInputStream();
    wxTextInputStream InputStream(*msg);
    while(msg->IsOk())
    {
        log=InputStream.ReadLine();
        Manager::Get()->GetLogManager()->Log(log,slot);
    }
}
