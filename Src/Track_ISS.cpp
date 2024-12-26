//---------------------------------------------------------------------------

#include <vcl.h>
#include <Vcl.Consts.hpp>
#pragma hdrstop

#include "Track_ISS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VCL.TMSFNCCustomControl"
#pragma link "VCL.TMSFNCGraphics"
#pragma link "VCL.TMSFNCGraphicsTypes"
#pragma link "VCL.TMSFNCMaps"
#pragma link "VCL.TMSFNCMapsCommonTypes"
#pragma link "VCL.TMSFNCTypes"
#pragma link "VCL.TMSFNCUtils"
#pragma link "VCL.TMSFNCWebBrowser"
#pragma resource "*.dfm"
TForm4* Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm4::FindISSButtonClick(TObject* Sender)
{
    DoISSTracking();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::DoISSTracking()
{
    TrackTheISS(
        FindISSButton, TMSFNCMaps1, RESTClient1, RESTRequest1, RESTResponse1);
}

//---------------------------------------------------------------------------
String __fastcall TForm4::LatLongValue(String PosLAT, String PosLONG)
{
    String Location;
    if (PosLAT.IsEmpty() == false && PosLONG.IsEmpty() == false) {
        Location = "Location ISS: " + PosLAT + ", " + PosLONG;

        return Location;
    }

    // Message debug box
	ShowMessage("Location not found");

	return "";
}

//---------------------------------------------------------------------------
void __fastcall TForm4::ShowLocationValueEditor(String Location)
{
    if (Location.IsEmpty() == false) {
        ListBox1->Items->Add(Location); // Use Add method instead of Text
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::TrackTheISS(TButton* AButton, TTMSFNCMaps* AMap,
    TRESTClient* ARESTClient, TRESTRequest* ARESTRequest,
    TRESTResponse* ARESTResponse)
{
    TJSONObject* JO;
    TJSONObject* JPosition;
    String PosLAT, PosLONG, Location;
    double dLAT, dLONG;

    AButton->Enabled = false;

    AMap->SetZoomLevel(0); // Open layer API sometimes times out..

    try {
        ARESTRequest->Execute();

        if (ARESTResponse->StatusCode == 200) {
            // Casting JSONValue to TJSONObject
            JO = static_cast<TJSONObject*>(ARESTResponse->JSONValue);

            // Accessing the nested JSON object's values
            JPosition = static_cast<TJSONObject*>(JO->GetValue("iss_position"));

            if (JPosition != nullptr) // Check if JPosition is valid
            {
                // Get value from json body
                PosLAT = JPosition->Values["latitude"]->Value();
                PosLONG = JPosition->Values["longitude"]->Value();

                // Message box
                Location = LatLongValue(PosLAT, PosLONG);
                ShowLocationValueEditor(Location);

            } else {
                // Handle the case where 'iss_position' is not found
                PosLAT = "N/A";
                PosLONG = "N/A";
            }

            // Convert strings to double
            if (TryStrToFloat(PosLAT, dLAT)) {
                if (TryStrToFloat(PosLONG, dLONG)) {
                    // Update Location for Map
                    AMap->BeginUpdate();
                    AMap->AddMarker(dLAT, dLONG, "ISS!");
                    AMap->EndUpdate();
                } else {
                    // Handle invalid longitude if needed
                    ShowMessage("Invalid Longitude Value");
                }
            } else {
                // Handle invalid latitude if needed
                ShowMessage("Invalid Latitude Value");
            }
        } else {
            // Handle HTTP error (non-200 status code)
            ShowMessage("Error: HTTP Status Code " +
                        IntToStr(ARESTResponse->StatusCode));
        }
    } catch (const Exception &e) {
        ShowMessage("An error occurred: " + e.Message);
    } catch (...) {
        ShowMessage("An unexpected error occurred.");
    }

    // Enable the button again - Button can click again
    AButton->Enabled = true;
}

