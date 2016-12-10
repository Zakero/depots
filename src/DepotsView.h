/* DepotsView.h
 * Copyright 2016 Brian Hill
 * All rights reserved. Distributed under the terms of the BSD License.
 */
#ifndef DEPOTS_VIEW_H
#define DEPOTS_VIEW_H

#include <ColumnListView.h>
#include <GroupView.h>
#include <String.h>
#include <View.h>

#include "DepotsSettings.h"

enum {
	kEnabledColumn,
	kNameColumn,
	kUrlColumn
};

class RepoRow : public BRow {
public:
								RepoRow(const char* repo_name,
									const char* repo_url, bool enabled);
		
			const char*			Name() const { return fName.String(); }
			void				SetName(const char *name);
			const char*			Url() const { return fUrl.String(); }
			void				SetEnabled(bool enabled);
			bool				IsEnabled() { return fEnabled; }
private:
			BString				fName;
			BString				fUrl;
			bool				fEnabled;
};


class DepotsView : public BView {
public:
							DepotsView();
							~DepotsView();
	virtual void			AllAttached();
	virtual void			MessageReceived(BMessage*);
	status_t				Clean();
	void					AddManualRepository(BString url);
private:
	BPath					fPkgmanListOut;
	DepotsSettings			fSettings;
	BColumnListView			*fListView;
	BButton					*fAddButton, *fRemoveButton, *fEnableButton, *fDisableButton;
	BString					fTitleEnabled, fTitleName, fTitleUrl,
							fLabelRemove, fLabelRemoveAll,
							fLabelEnable, fLabelDisable, fLabelEnableAll, fLabelDisableAll;
	BString					_GetRootUrl(BString url);
	void					_InitList();
	void					_UpdatePkgmanList(bool updateStatusOnly=false);
	void					_SaveList();
	RepoRow*				_AddRepo(BString name, BString url, bool enabled);
	void					_UpdateButtons();
};

#endif
