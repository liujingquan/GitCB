/****************************************************************************
this file is a part of gitcb plugin ,all the command are packaged in a class,
use the method can easily call the command function, and add command for future
*****************************************************************************/
#ifndef GITCOMMAND_H
#define GITCOMMAND_H

#include "GitCB.h"
#include<wx/wxprec.h>

#ifndef WX_PRECOMP
    #include<wx/wx.h>
#endif // WX_PRECOMP

class GitCommand
{
    public:
    GitCommand();                   //constructor
    ~GitCommand();                  //destructor
//execute the command,but not sure on linux
    bool Execute(const wxString& command,const wxString& comment);
    bool valid_command();
    static GitCommand* GetCommand();//use the pointer to get the command
/********************
all command function
********************/
    void commit(wxString commit_message);
    void init();
    void add(wxString filename);
    void clone(wxString link);
    void config(wxString name,wxString e_mail);
    void cd(wxString dir);
    void Diff();

    private:
    GitCB a;
    wxArrayString all_output;
    wxArrayString all_error;




};

#endif // GITCOMMAND_H





