//
//  DPCalendarMonthlyView.h
//  DPCalendar
//
//  Created by Ethan Fang on 19/12/13.
//  Copyright (c) 2013 Ethan Fang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DPCalendarMonthlySingleMonthCell.h"
#import "DPCalendarEvent.h"

extern NSString *const DPCalendarMonthlyViewAttributeWeekdayHeight; //Height of weekday cell
extern NSString *const DPCalendarMonthlyViewAttributeWeekdayFont; //Font of weekday

extern NSString *const DPCalendarMonthlyViewAttributeCellTodayBannerBkgColor; //Today's color in cell
extern NSString *const DPCalendarMonthlyViewAttributeCellHeight; //Height of date cell
extern NSString *const DPCalendarMonthlyViewAttributeDayFont; //Font of day label
extern NSString *const DPCalendarMonthlyViewAttributeEventFont; //Font of event, which has underline
extern NSString *const DPCalendarMonthlyViewAttributeCellRowHeight; //Height of event
extern NSString *const DPCalendarMonthlyViewAttributeEventColors; //Underline color of the event
extern NSString *const DPCalendarMonthlyViewAttributeIconEventFont; //Font of icon event
extern NSString *const DPCalendarMonthlyViewAttributeIconEventBkgColors; //Background color of icon event
extern NSString *const DPCalendarMonthlyViewAttributeCellNotInSameMonthColor; //Background color of the cell that is not in current month
extern NSString *const DPCalendarMonthlyViewAttributeCellHighlightedColor; //Highlight color of the cell
extern NSString *const DPCalendarMonthlyViewAttributeCellSelectedColor; //Selected color of the cell
extern NSString *const DPCalendarMonthlyViewAttributeCellNotInSameMonthSelectable; //Whether the cell that is not in current month can be selected
extern NSString *const DPCalendarMonthlyViewAttributeEventDrawingStyle;//Drawing style of event

extern NSString *const DPCalendarMonthlyViewAttributeSeparatorColor; //Border color of cell

extern NSString *const DPCalendarMonthlyViewAttributeStartDayOfWeek; //Start day of the week (0 means starting from Sunday)
extern NSString *const DPCalendarMonthlyViewAttributeMonthRows; //A convenient function to define the height of cell

@protocol DPCalendarMonthlyViewDelegate <NSObject>

-(void) didScrollToMonth:(NSDate *)month firstDate:(NSDate *)firstDate lastDate:(NSDate *)lastDate;

@optional
- (Class) monthlyCellClass;
- (Class) monthlyWeekdayClassClass;

- (BOOL) shouldHighlightItemWithDate:(NSDate *)date;
- (BOOL) shouldSelectItemWithDate:(NSDate *)date;
- (void) didSelectItemWithDate:(NSDate *)date;

- (NSDictionary *) monthlyViewAttributes;
@end

@interface DPCalendarMonthlyView : UIScrollView<UICollectionViewDataSource, UICollectionViewDelegate>

//Current selected date
@property (nonatomic, readonly) NSDate *selectedDate;

//Current selected month
@property (nonatomic, readonly) NSDate *seletedMonth;

@property(nonatomic,strong) UIColor *separatorColor;

//Background Color for monthly scroll view
@property(nonatomic, strong) UIColor *monthlyViewBackgroundColor;

//Background Color for monthly scroll view
@property(nonatomic) BOOL didSelectIntemWhenDateSelected;

@property (nonatomic, weak) id<DPCalendarMonthlyViewDelegate> monthlyViewDelegate;

- (void) setEvents:(NSArray *)events complete:(void (^)(void))complete;
- (void) setIconEvents:(NSArray *)iconEvents complete:(void (^)(void))complete;

-(id)initWithFrame:(CGRect)frame delegate:(id<DPCalendarMonthlyViewDelegate>)monthViewDelegate;

-(void) scrollToMonth:(NSDate *)month complete:(void (^)(void))complete;
-(void) scrollToPreviousMonthWithComplete:(void (^)(void))complete;
-(void) scrollToNextMonthWithComplete:(void (^)(void))complete;

- (NSDate *)firstVisibleDateOfMonth:(NSDate *)date;
- (NSDate *)lastVisibleDateOfMonth:(NSDate *)date;

- (void) clickDate:(NSDate *)date;

- (NSArray *)eventsForDay:(NSDate *)date;
- (NSArray *)iconEventsForDay:(NSDate *)date;

@end
