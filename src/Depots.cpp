/* Depots.cpp
 * Copyright 2016 Brian Hill
 * All rights reserved. Distributed under the terms of the BSD License.
 */
#include "Depots.h"

#include <Alert.h>
#include <Catalog.h>

#undef B_TRANSLATION_CONTEXT
#define B_TRANSLATION_CONTEXT "DepotsApplication"

const char* kAppSignature = "application/x-vnd.BH-Depots";


DepotsApplication::DepotsApplication()
	:
	BApplication(kAppSignature)
{
	BRect mainWindowRect(50,50,80,80);
	fWindow = new DepotsWindow(mainWindowRect);
}

/*
void
DepotsApplication::QuitRequested()
{
	return true;
}*/


void
DepotsApplication::AboutRequested()
{
	BAlert *aboutAlert = new BAlert(B_TRANSLATE("About"),
				B_TRANSLATE_COMMENT("Depots preferences by Brian Hill", "About box text"),
				B_TRANSLATE_COMMENT("OK", "About box button label"));
	aboutAlert->SetFlags(aboutAlert->Flags() | B_CLOSE_ON_ESCAPE);
	aboutAlert->Go();
}


int
main()
{
	DepotsApplication myApp;
	myApp.Run();
	return 0;
}
