//---------------------------------------------------------------------------

#ifndef Track_ISSH
#define Track_ISSH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include "VCL.TMSFNCCustomControl.hpp"
#include "VCL.TMSFNCGraphics.hpp"
#include "VCL.TMSFNCGraphicsTypes.hpp"
#include "VCL.TMSFNCMaps.hpp"
#include "VCL.TMSFNCMapsCommonTypes.hpp"
#include "VCL.TMSFNCTypes.hpp"
#include "VCL.TMSFNCUtils.hpp"
#include "VCL.TMSFNCWebBrowser.hpp"
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
  __published: // IDE-managed Components
    TTMSFNCMaps* TMSFNCMaps1;
    TRESTClient* RESTClient1;
    TRESTRequest* RESTRequest1;
    TRESTResponse* RESTResponse1;
    TButton* FindISSButton;
	TListBox *ListBox1;
    void __fastcall FindISSButtonClick(TObject* Sender);
  private: // User declarations
    void __fastcall DoISSTracking();
	void __fastcall TrackTheISS(TButton* AButton, TTMSFNCMaps* AMap,
        TRESTClient* ARESTClient, TRESTRequest* ARESTRequest,
		TRESTResponse* ARESTResponse);
	String __fastcall LatLongValue(String PosLAT, String PosLONG);
    void __fastcall ShowLocationValueEditor(String Location);
  public: // User declarations
    __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4* Form4;
//---------------------------------------------------------------------------
#endif

