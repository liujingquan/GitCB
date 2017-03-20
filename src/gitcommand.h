/****************************************************************************
this file is a part of gitcb plugin ,all the command are packaged in a class,
use the method can easily call the command function, and add command for future
*****************************************************************************/
#ifndef GITCOMMAND_H
#define GITCOMMAND_H

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
    bool Execute(wxString command,wxArrayString output,wxArrayString error);
    static GitCommand* GetCommand();//use the pointer to get the command
/********************
all command function
********************/
    void commit(wxString commit_message);
    void init();
    void add();
    void clone(wxString link);
    void config(wxString name,wxString e_mail);

    private:
    wxArrayString all_output;
    wxArrayString all_error;




};

#endif // GITCOMMAND_H





