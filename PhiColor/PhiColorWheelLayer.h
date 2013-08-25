//
//  ColorWheelLayer.h
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

@interface PhiColorWheelLayer : CALayer {
	CGColorRef color;
	CGColorRef transitionColor;
	CGColorRef transitionBaseColor;
	CGColorRef transitionAddColor;
}

@property(nonatomic) CGColorRef baseColor;
@property(nonatomic) CGColorRef addColor;
@property(nonatomic) CGFloat strength;
@property(readonly, nonatomic) CGColorRef color;
@property(readonly, nonatomic) CGColorRef transitionColor;
@property(nonatomic) CGFloat wedgeMargin;
@property(nonatomic) CGFloat wedgeCornerRadius;
@property(nonatomic) CGFloat wedgeHeight;
@property(nonatomic) CGFloat wedgeWindowHeight;
@property(nonatomic) CGFloat wedgeWindowArc;
@property(nonatomic) CGFloat baseColorAngleWeight;
@property(nonatomic) CGFloat addColorAngleWeight;

+ (void)computeColor:(CGFloat *)colorComponents fromBaseColor:(CGFloat *)baseComponents withAddColor:(CGFloat *)addComponents forStrength:(CGFloat)strength model:(CGColorSpaceModel)model;
+ (BOOL)computeBaseColor:(CGFloat *)baseComponents andStrength:(CGFloat *)strength fromColor:(CGFloat *)colorComponents forAddColor:(CGFloat *)addComponents model:(CGColorSpaceModel)model;

- (BOOL)containsPoint:(CGPoint)point inSegment:(NSString *)segment inLayer:(CALayer *)layer;
- (void)translateSegment:(NSString *)segment by:(CGPoint)point inLayer:(CALayer *)layer;

@end
