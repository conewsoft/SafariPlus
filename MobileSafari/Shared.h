// Shared.h
// (c) 2018 opa334

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

@class BrowserController, BrowserRootViewController, TabDocument, SPFileManager, SPCacheManager, SPDownload, SPDownloadInfo, SPDownloadManager, SPLocalizationManager, SPPreferenceManager, SPCommunicationManager, SafariWebView;

extern BOOL showAlert;
extern BOOL edgeToEdgeDisplay;
extern SPFileManager* fileManager;
extern SPPreferenceManager* preferenceManager;
extern SPLocalizationManager* localizationManager;
extern SPDownloadManager* downloadManager;
extern SPCommunicationManager* communicationManager;
extern SPCacheManager* cacheManager;
extern NSBundle* SPBundle;
extern NSBundle* MSBundle;

extern BOOL privateBrowsingEnabled(BrowserController* controller);
extern void togglePrivateBrowsing(BrowserController* controller);
extern NSArray<BrowserController*>* browserControllers();
extern NSArray<SafariWebView*>* activeWebViews();
extern BrowserController* browserControllerForTabDocument(TabDocument* document);
extern BrowserRootViewController* rootViewControllerForBrowserController(BrowserController* controller);
extern BrowserRootViewController* rootViewControllerForTabDocument(TabDocument* document);
extern void addToDict(NSMutableDictionary* dict, NSObject* object, NSString* key);
extern void sendSimpleAlert(NSString* title, NSString* message);
extern void loadOtherPlist();
extern void saveOtherPlist();

#ifdef DEBUG_LOGGING

extern void initDebug();
extern void intDlog(NSString* fString, ...);
extern void intDlogDownload(SPDownload* download, NSString* message);
extern void intDlogDownloadInfo(SPDownloadInfo* downloadInfo, NSString* message);
extern void intDlogDownloadManager();

#define dlog(args...) intDlog(args)
#define dlogDownload(args...) intDlogDownload(args)
#define dlogDownloadInfo(args...) intDlogDownloadInfo(args)
#define dlogDownloadManager() intDlogDownloadManager()

#else

#define dlog(args...)
#define dlogDownload(args...)
#define dlogDownloadInfo(args...)
#define dlogDownloadManager()

#endif

@interface UIImage (ColorInverse)
+ (UIImage *)inverseColor:(UIImage *)image;
@end

@interface NSURL (HTTPtoHTTPS)
- (NSURL*)httpsURL;
@end

@interface NSString (Strip)
- (NSString*)stringStrippedByStrings:(NSArray<NSString*>*)strings;
@end

@interface NSString (UUID)
- (BOOL)isUUID;
@end

//http://commandshift.co.uk/blog/2013/01/31/visual-format-language-for-autolayout/
@interface UIView (Autolayout)
+ (id)autolayoutView;
@end

@interface UITableViewController (FooterFix)
- (void)fixFooterColors;
@end
