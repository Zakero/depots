/* AddRepoWindow.h
 * Copyright 2016 Brian Hill
 * All rights reserved. Distributed under the terms of the BSD License.
 */
#ifndef ADD_REPO_WINDOW_H
#define ADD_REPO_WINDOW_H


#include <Button.h>
#include <TextControl.h>
#include <View.h>
#include <Window.h>


class AddRepoWindow : public BWindow {
public:
							AddRepoWindow(BRect size, BLooper *looper);
	virtual void			MessageReceived(BMessage*);
	virtual void			Quit();
	virtual void			FrameResized(float newWidth, float newHeight);

private:
	BView					*fView;
	BTextControl			*fText;
	BButton					*fAddButton, *fCancelButton;
	BLooper					*fReplyLooper;
	status_t				_GetClipboardData();
};

#endif
