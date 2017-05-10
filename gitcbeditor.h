#ifndef GITCBEDITOR_H
#define GITCBEDITOR_H

#include "editorbase.h"
#include "cbstyledtextctrl.h"

class cbEditor;//forward decalre

class GitcbEditor
{
public:
    GitcbEditor();
    ~GitcbEditor();
    bool Init();
    void Colourset();
    void Append(const wxString& text);
    void Clear();
    void Copy();
private:
    cbEditor* geditor;
};

#endif // GITCBEDITOR_H
