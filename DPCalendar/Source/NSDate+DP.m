//
//  NSDate+DP.m
//  DPCalendar
//
//  Created by Ethan Fang on 23/12/13.
//  Copyright (c) 2013 Ethan Fang. All rights reserved.
//

#import "NSDate+DP.h"

@implementation NSDate (DP)

+ (int)dp_monthsDifferenceBetweenStartDate:(NSDate *)startDate endDate:(NSDate *)endDate {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
    NSDateComponents *startDateComponents = [calendar components:NSYearCalendarUnit|NSMonthCalendarUnit fromDate:startDate];
    NSDateComponents *endDateComponents = [calendar components:NSYearCalendarUnit|NSMonthCalendarUnit fromDate:endDate];
    
    int yearOfStartDate = (int)startDateComponents.year;
    int monthOfStartDate = (int)startDateComponents.month;
    
    int yearOfEndDate = (int)endDateComponents.year;
    int monthOfEndDate = (int)endDateComponents.month;
    return yearOfEndDate * 12 + monthOfEndDate - (yearOfStartDate * 12 + monthOfStartDate);
}

- (NSDate *)dp_dateByAddingYears:(int)years months:(int)months days:(int)days {
    NSDateComponents* dateComponents = [[NSDateComponents alloc]init];
    [dateComponents setYear:years];
    [dateComponents setMonth:months];
    [dateComponents setDay:days];
    NSCalendar* calendar = [NSCalendar currentCalendar];
    return [calendar dateByAddingComponents:dateComponents toDate:self options:0];
}

- (instancetype) dp_firstDateOfMonth:(NSCalendar *)calendar {
    if (nil == calendar) {
        calendar = [NSCalendar currentCalendar];
    }
    
    NSDateComponents *components = [calendar components:NSYearCalendarUnit|NSMonthCalendarUnit|NSDayCalendarUnit fromDate:self];
    
    [components setDay:1];
    
    return [calendar dateFromComponents:components];
}

- (instancetype) dp_lastDateOfMonth:(NSCalendar *)calendar {
    if (nil == calendar) {
        calendar = [NSCalendar currentCalendar];
    }
    
    NSDateComponents *components = [calendar components:NSYearCalendarUnit|NSMonthCalendarUnit|NSDayCalendarUnit fromDate:self];
    [components setDay:0];
    [components setMonth:components.month + 1];
    
    return [calendar dateFromComponents:components];
}

- (instancetype)dp_dateWithDay:(NSUInteger)day calendar:(NSCalendar *)calendar {
    if (nil == calendar) {
        calendar = [NSCalendar currentCalendar];
    }
    NSDateComponents *components = [calendar components:NSYearCalendarUnit|NSMonthCalendarUnit|NSDayCalendarUnit fromDate:self];
    
    [components setDay:day];
    
    return [calendar dateFromComponents:components];
}

-(instancetype)dp_dateWithoutTimeWithCalendar:(NSCalendar *)calendar {
    NSUInteger preservedComponents = (NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit);
    return [calendar dateFromComponents:[calendar components:preservedComponents fromDate:self]];
}

@end

