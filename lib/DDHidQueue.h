/*
 * Copyright (c) 2007 Dave Dribin
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#import <Cocoa/Cocoa.h>
#include <IOKit/hid/IOHIDLib.h>

@class DDHidElement;
@class DDHidEvent;

@interface DDHidQueue : NSObject
{
    IOHIDQueueInterface ** mQueue;
    NSRunLoop * mRunLoop;
    BOOL mStarted;
    
    id mDelegate;
    CFRunLoopSourceRef mEventSource;
}

- (id) initWithHIDQueue: (IOHIDQueueInterface **) queue
                   size: (NSUInteger) size;

- (void) addElement: (DDHidElement *) element;

- (void) addElements: (NSArray *) elements;

- (void) addElements: (NSArray *) elements recursively: (BOOL) recursively;

- (void) setDelegate: (id) delegate;

- (void) startOnCurrentRunLoop;

- (void) startOnRunLoop: (NSRunLoop *) runLoop;

- (void) stop;

- (BOOL) isStarted;

- (BOOL) getNextEvent: (IOHIDEventStruct *) event;

- (DDHidEvent *) nextEvent;

@end

@interface NSObject (DDHidQueueDelegate)

- (void) ddhidQueueHasEvents: (DDHidQueue *) hidQueue;

@end
