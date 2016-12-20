/* DepotsView.h
 * Copyright 2016 Brian Hill
 * All rights reserved. Distributed under the terms of the BSD License.
 */
#ifndef DEPOTS_VIEW_H
#define DEPOTS_VIEW_H

#include <ColumnListView.h>
#include <GroupView.h>
#include <ObjectList.h>
#include <String.h>
#include <StringView.h>
#include <View.h>

#include "DepotsSettings.h"
#include "RepoRow.h"
#include "TaskLooper.h"
#include "TaskTimer.h"


class DepotsView : public BView {
public:
							DepotsView();
							~DepotsView();
	virtual void			AllAttached();
	virtual void			AttachedToWindow();
	virtual void			MessageReceived(BMessage*);
	void					AddManualRepository(BString url);
	bool					IsTaskRunning() { return fIsTaskRunning; }
private:
//	BPath					fPkgmanListOut;
	DepotsSettings			fSettings;
	BColumnListView			*fListView;
	BStringView				*fListStatusView;
	TaskLooper				*fTaskLooper;
//	BObjectList<RepoRow>	fTaskQueue;
//	TaskTimer				*fTaskTimer;
	bool					fIsTaskRunning, fShowCompletedStatus;
	int						fRunningTaskCount;
	BButton					*fAboutButton, *fAddButton, *fRemoveButton, *fEnableButton, *fDisableButton;
	
	// Message helpers
	void					_AddSelectedRowsToQueue();
	void					_TaskStarted(RepoRow *rowItem, int16 count);
	void					_StartNextTask();
	void					_TaskCompleted(RepoRow *rowItem, int16 count, bool noErrors, BString& newName);
	void					_CompleteRunningTask(bool noErrors, BString& name);
	
	// GUI functions
	BString					_GetRootUrl(BString url);
	status_t				_Clean();
	void					_InitList();
	void					_UpdatePkgmanList(bool updateStatusOnly=false);
	void					_SaveList();
	RepoRow*				_AddRepo(BString name, BString url, bool enabled);
	void					_UpdateButtons();
	void					_UpdateStatusView();
};

#endif
