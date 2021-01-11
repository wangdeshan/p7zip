// UserInputUtils.cpp

#include "StdAfx.h"

#include "../../../Common/StdInStream.h"
#include "../../../Common/StringConvert.h"

#include "UserInputUtils.h"

static const char kYes = 'y';
static const char kNo = 'n';
static const char kYesAll = 'a';
static const char kNoAll = 's';
static const char kAutoRenameAll = 'u';
static const char kQuit = 'q';

static const char *kFirstQuestionMessage = "? ";
static const char *kHelpQuestionMessage =
  "(Y)es / (N)o / (A)lways / (S)kip all / A(u)to rename all / (Q)uit? ";

// return true if pressed Quite;

NUserAnswerMode::EEnum ScanUserYesNoAllQuit(CStdOutStream *outStream)
{
  if (outStream)
    *outStream << kFirstQuestionMessage;
  for (;;)
  {
    if (outStream)
    {
      *outStream << kHelpQuestionMessage;
      outStream->Flush();
    }
    AString scannedString = g_StdIn.ScanStringUntilNewLine();
    scannedString.Trim();
    if (!scannedString.IsEmpty())
      switch(::MyCharLower_Ascii(scannedString[0]))
      {
        case kYes:    return NUserAnswerMode::kYes;
        case kNo:     return NUserAnswerMode::kNo;
        case kYesAll: return NUserAnswerMode::kYesAll;
        case kNoAll:  return NUserAnswerMode::kNoAll;
        case kAutoRenameAll: return NUserAnswerMode::kAutoRenameAll;
        case kQuit:   return NUserAnswerMode::kQuit;
      }
  }
}

UString GetPassword(CStdOutStream *outStream,bool verify)
{
  if (outStream)
  {
    *outStream << "\n  use   -p{Password}";
    outStream->Flush();
  }
  exit (999);
}
