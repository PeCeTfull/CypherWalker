#include "HiScoresFile.h"
#include <wx/wfstream.h>
#include <wx/sstream.h>

#define DOUBLE_RECORDS_AMOUNT 10 // 5 high score records * 2 details

HiScoresFile::HiScoresFile()
{
    //ctor
}

wxString HiScoresFile::EncryptOrDecrypt(wxString sourceText) { // XOR encryption/decryption method
    char key[5] = {'T', 'A', 'N', 'E', 'R'};
    wxString output = sourceText;
    size_t sourceTextLength = sourceText.Length();

    for (int i = 0; i < sourceTextLength; i++)
        output[i] = sourceText[i] ^ key[i % (sizeof(key) / sizeof(char))];

    return output;
}

wxString *HiScoresFile::ReadFileContents()
{
    wxString *contents = new wxString[DOUBLE_RECORDS_AMOUNT];
    wxString content;
    wxFileInputStream file(hiScoresFileName);
    wxStringOutputStream sOutput(&content);
    sOutput.Write(file);
    sOutput.Close();

    content = EncryptOrDecrypt(content);
    size_t verticalBarPos;
    for(int i = 0; i < DOUBLE_RECORDS_AMOUNT; i++)
    {
        verticalBarPos = content.Find('|');
        contents[i] = content.SubString(0, verticalBarPos - 1);
        content = content.SubString(verticalBarPos + 1, content.Length());
    }

    return contents;
}

void HiScoresFile::SaveFile(wxString& records)
{
    records = EncryptOrDecrypt(records);
    wxStringInputStream sInput(records);
    wxFileOutputStream file(hiScoresFileName);
    file.Write(sInput);
    file.Close();
}

void HiScoresFile::NewFileContents()
{
    wxString records = wxT("John Smith|100|Jan Kowalski|80|Johannes Schmidt|60|Juan Ferrer|40|Ian McGowan|20");

    SaveFile(records);
}

void HiScoresFile::WriteFileContents(wxString* hiScoresTable)
{
    wxString records = wxT(hiScoresTable[0] + '|' + hiScoresTable[1] + '|' + hiScoresTable[2] + '|' + hiScoresTable[3] + '|' + hiScoresTable[4] + '|' + hiScoresTable[5] + '|' + hiScoresTable[6] + '|' + hiScoresTable[7] + '|' + hiScoresTable[8] + '|' + hiScoresTable[9]);

    SaveFile(records);
}

HiScoresFile::~HiScoresFile()
{
    //dtor
}
