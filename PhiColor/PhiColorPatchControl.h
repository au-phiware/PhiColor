//
//  PhiColorPatch.h
//  ColorWheel
//
// Copyright 2013 Corin Lawson
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import "PhiColorWheelController.h"

@class PhiColorPatchControl;

@protocol PhiColorPatchControlDelegate <NSObject>

@optional

- (BOOL)colorPatchControlShouldBeginEditing:(PhiColorPatchControl *)colorPatch;
- (void)colorPatchControlDidBeginEditing:(PhiColorPatchControl *)colorPatch;
- (BOOL)colorPatchControlShouldEndEditing:(PhiColorPatchControl *)colorPatch;
- (void)colorPatchControlDidEndEditing:(PhiColorPatchControl *)colorPatch;
- (BOOL)colorPatchControl:(PhiColorPatchControl *)colorPatch shouldChangeToColor:(CGColorRef)aColor;
- (CGColorRef)colorPatchControl:(PhiColorPatchControl *)colorPatch changeToColor:(CGColorRef)aColor;

@end

@interface PhiColorPatchControl : UIControl <PhiColorWheelResponder> {
	IBOutlet id<PhiColorPatchControlDelegate> delegate;
}

@property (nonatomic, strong) UIColor *color;
@property (nonatomic) BOOL didInitColor;

- (void)editColor:(id)sender animated:(BOOL)animate;
- (IBAction)editColor:(id)sender;
- (BOOL)becomeFirstResponderAnimated:(BOOL)animate;
- (BOOL)resignFirstResponderAnimated:(BOOL)animate;

@end
