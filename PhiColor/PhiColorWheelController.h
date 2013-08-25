//
//  PhiColorWheelController.h
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

@protocol PhiColorWheelResponder;

@protocol PhiColorWheelResponder
- (BOOL)isFirstResponder;
- (BOOL)canResignFirstResponder;
- (BOOL)resignFirstResponder;
- (BOOL)canBecomeFirstResponder;
- (BOOL)becomeFirstResponder;
@end

@class PhiColorWheelView;

@interface PhiColorWheelController : NSObject {
	PhiColorWheelView *wheelView;
	CGSize preferredSize;
	CGSize minimumPreferredSize;
	CGRect constraints;
	CGPoint targetPoint;
	BOOL wheelVisible;
}

+ (PhiColorWheelController *)sharedColorWheelController;

@property (nonatomic, weak) id delegate;
@property (nonatomic, readonly, strong) PhiColorWheelView *wheelView;

@property (nonatomic, assign, getter=isWheelVisible) BOOL wheelVisible;
-(void)setWheelVisible:(BOOL)visible animated:(BOOL)animate;
-(void)hideColorWheel;

-(void)setWheelColor:(CGColorRef)color;

-(CGPoint)targetPointInView:(UIView *)view;
-(void)setTargetPoint:(CGPoint)point inView:(UIView *)view;

-(CGRect)constraintsInView:(UIView *)view;
-(void)setConstraints:(CGRect)constraints inView:(UIView *)view;
-(void)constrainToView:(UIView *)view;

-(CGSize)minimumPreferredSizeInView:(UIView *)view;
-(void)setMinimumPreferredSize:(CGSize)size inView:(UIView *)view;

-(CGSize)preferredSizeInView:(UIView *)view;
-(void)setPreferredSize:(CGSize)size inView:(UIView *)view;

@end
