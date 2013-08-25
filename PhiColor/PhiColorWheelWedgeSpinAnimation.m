//
//  ColorWheelWedgeSpinAnimation.m
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

#import "PhiColorWheelWedgeSpinAnimation.h"
#import "PhiColorWheelLayer.h"

@interface PhiColorWheelLayer (ColorWheelWedgeSpinAnimation)

- (void)setTransitionBaseColor:(CGColorRef)aColor;
- (void)setTransitionAddColor:(CGColorRef)aColor;

@end

@implementation PhiColorWheelLayer (ColorWheelWedgeSpinAnimation)

- (void)setTransitionBaseColor:(CGColorRef)aColor {
	if (!CGColorEqualToColor(transitionBaseColor, aColor)) {
		CGColorRelease(transitionBaseColor);
		transitionBaseColor = CGColorRetain(aColor);
	}
}
- (void)setTransitionAddColor:(CGColorRef)aColor {
	if (!CGColorEqualToColor(transitionAddColor, aColor)) {
		CGColorRelease(transitionAddColor);
		transitionAddColor = CGColorRetain(aColor);
	}
}

@end

@implementation PhiColorWheelWedgeSpinAnimation

@synthesize direction;
@synthesize fromValue, toValue;

- (id)init {
	if (self = [super init]) {
		self.duration = 1.5;
	}
	return self;
}

- (void)animationDidStart:(CAAnimation *)anim {
	if ([self.delegate respondsToSelector:@selector(animationDidStart:)]) {
		[self.delegate animationDidStart:self];
	}
}

- (void)animationDidStop:(CAAnimation *)anim finished:(BOOL)flag {
	if ([self.delegate respondsToSelector:@selector(animationDidStop:finished:)]) {
		[self.delegate animationDidStop:self finished:flag];
	}
}

- (void)runActionForKey:(NSString *)key object:(id)object arguments:(NSDictionary *)dict {
	if ([object isKindOfClass:[PhiColorWheelLayer class]] && ([key isEqualToString:@"baseColor"] || [key isEqualToString:@"addColor"])) {
		PhiColorWheelLayer *layer = (PhiColorWheelLayer *)object;
		CABasicAnimation *wheel = [CABasicAnimation animationWithKeyPath:[key stringByAppendingString:@"AngleWeight"]];
		wheel.fromValue = @0.0f;
		wheel.toValue = @(self.direction == PhiColorWheelWedgeSpinDirectionAnticlockwise ? 1.0f : -1.0f);
		wheel.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseOut];
		wheel.duration = self.duration; 
		wheel.delegate = self;
		
		if (self.fromValue) {
			if ([key isEqualToString:@"baseColor"]) {
				[layer setTransitionBaseColor:self.fromValue];
			} else if ([key isEqualToString:@"addColor"]) {
				[layer setTransitionAddColor:self.fromValue];
			}
		} else {
			if ([key isEqualToString:@"baseColor"]) {
				[layer setTransitionBaseColor:(CGColorRef)[[layer presentationLayer] valueForKey:key]];
			} else if ([key isEqualToString:@"addColor"]) {
				[layer setTransitionAddColor:(CGColorRef)[[layer presentationLayer] valueForKey:key]];
			}
		}

		if (self.toValue) {
			[CATransaction begin];
			[CATransaction setDisableActions:YES];
			[layer setValue:(id)self.toValue forKey:key];
			[CATransaction commit];
		}
		
		[layer addAnimation:wheel forKey:[wheel keyPath]];
	}
}

@end
