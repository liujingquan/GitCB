#include"gitcommand.h"


//constructor
GitCommand::GitCommand()
{

}
//destructor
GitCommand::~GitCommand()
{

}

void GitCommand::Execute()
{

}

GitCommand* GitCommand::GetCommand()
{

}


void GitCommand::commit()
{


    wxArrayString output;
    wxExecute(_T("git commit"),output);

}

void GitCommand::clone()
{
    wxString command;
    wxExecute(command,output);

}

void GitCommand::config()
{

}

