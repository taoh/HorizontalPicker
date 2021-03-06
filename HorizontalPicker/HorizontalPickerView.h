//  The MIT License (MIT)
//  Copyright (c) 2011-2013 <RABE_IT Services>
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//
//  HPickerView.h
//  HorizontalPicker
//
//  Created by Bernd Rabe on 02.05.11.
//  Copyright 2011-2013 RABE_IT Services. All rights reserved.
//

/** \brief A horizontal picker suitable where only a view number of items are present.
 */

#import <UIKit/UIKit.h>
#import "HorizontalPickerGlobal.h"

@protocol HPickerViewDataSource, HPickerViewDelegate;

@interface HorizontalPickerView : UIView

@property(nonatomic, weak) IBOutlet id <HPickerViewDataSource> dataSource;
@property(nonatomic, weak) IBOutlet id <HPickerViewDelegate>   delegate;

/** The used style.
 */
@property (assign, nonatomic) HPStyle   style;

/** The color of the selected element.
 */
@property (strong, nonatomic) UIColor   *tintColor;

/** Puts the picker in non-responsive mode.
 */
@property (assign, nonatomic) BOOL      enabled;

- (NSInteger)selectedRow;
- (UIView *)viewForRow:(NSInteger)row;
- (void)selectRow:(NSInteger)row animated:(BOOL)animated;
- (void)reloadAllComponents;

@end


@protocol HPickerViewDataSource <NSObject>
@required
- (NSInteger)numberOfRowsInPickerView:(HorizontalPickerView *)pickerView;
@end


@protocol HPickerViewDelegate <NSObject>
@optional
- (NSString *)pickerView:(HorizontalPickerView *)pickerView titleForRow:(NSInteger)row;
- (void)pickerView:(HorizontalPickerView *)pickerView didSelectRow:(NSInteger)row;
@end
