/****************************************************************************
this file is a part of gitcb plugin ,all the command are packaged in a class,
use the method can easily call the command function, print output and add command
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

    static GitCommand* GetCommand();
    bool valid_command();
/**
some command function,if you want to execute another command,use Execute function
*/
    int  Execute        (const wxString& command);
    void commit         (const wxString& commit_message);
    void add            (const wxString& filename);
    void clone          (const wxString& link);
    void rm             (const wxString& filename);
    void config         (const wxString& name,const wxString& e_mail);
    void push           (const wxString& remotebranch);
/**
print output or error message to TextCtrl,EDIT:Actually,it is NOT a good idea to use wxTextctrl,
and do NOT print message to log,IMpossible to do it.
*/
    void printmessage   (wxTextCtrl& logtext);
    void Diff();
    void init();

    private:
    friend class CommitmDialog;
    friend class CloneDialog;
    friend class BranchDialog;
    wxArrayString output;
    wxArrayString error;

};

#endif // GITCOMMAND_H





