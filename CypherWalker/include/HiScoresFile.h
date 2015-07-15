#ifndef HISCORESFILE_H
#define HISCORESFILE_H

#include <wx/string.h>


class HiScoresFile
{
    public:
        HiScoresFile();
        wxString *ReadFileContents();
        void NewFileContents();
        void WriteFileContents(wxString* hiScoresTable);
        virtual ~HiScoresFile();
        const wxString hiScoresFileName = wxT("scores.dat");
    protected:
    private:
        wxString EncryptOrDecrypt(wxString toEncrypt);
        void SaveFile(wxString& records);
};

#endif // HISCORESFILE_H
