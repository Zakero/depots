/* constants.h
 * Copyright 2016 Brian Hill
 * All rights reserved. Distributed under the terms of the BSD License.
 */
#ifndef DEPOTS_CONSTANTS_H
#define DEPOTS_CONSTANTS_H

#include <Catalog.h>
#include <String.h>

#undef B_TRANSLATION_CONTEXT
#define B_TRANSLATION_CONTEXT "Constants"

#define USE_MINIMAL_BUTTONS 1

static const BString kOKLabel = B_TRANSLATE_COMMENT("OK", "Button label");
static const BString kCancelLabel = B_TRANSLATE_COMMENT("Cancel", "Button label");
static const BString kWebsiteUrl = "http://perelandra0x309.github.io/depots";

typedef struct {
	const char* name;
	const char* url;
} Repository;

static const Repository kDefaultRepos[] = {
	{ "Haiku", "http://packages.haiku-os.org/haiku/master/"B_HAIKU_ABI_NAME"/current"},
	{ "Haikuports", "http://packages.haiku-os.org/haikuports/master/repo/"B_HAIKU_ABI_NAME"/current" },
	{ "BeSly Software Solutions", "http://software.besly.de/repo"},
	{ "clasqm's repo", "http://clasquin-johnson.co.za/michel/repo"},
	{ "FatElk", "http://coquillemartialarts.com/fatelk/repo"}
};

#define key_frame "frame"
#define key_name "repo_name"
#define key_url "repo_url"
#define key_text "text"

//Messages
enum {
	ADD_REPO_WINDOW = 'BHDa',
	ADD_BUTTON_PRESSED,
	CANCEL_BUTTON_PRESSED,
	ADD_REPO_URL,
	REMOVE_REPOS,
	LIST_SELECTION_CHANGED,
	ENABLE_BUTTON_PRESSED,
	DISABLE_BUTTON_PRESSED,
	DO_TASKS,
	UPDATE_STATUS,
	TASKS_COMPLETE,
	TASKS_COMPLETE_WITH_ERRORS,
	TASKS_CANCELED,
	UPDATE_LIST,
	SHOW_ABOUT
};


#endif
