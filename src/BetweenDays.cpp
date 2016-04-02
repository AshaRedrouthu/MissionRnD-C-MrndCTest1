/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int valied(int d, int m, int year)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0)
		month[1] = 29;
	if (d <= month[m - 1] && m <= 12)
		return 1;
	else
		return 0;
}
int returndiff(int d1, int d2)
{
	if (d1 > d2)
		return d1 - 1 - d2;
	else
		return d2 - 1 - d1;
}
int returnYearDiff(int y1, int y2)
{
	int max, i, sum = 0;
	if (y1 > y2){
		max = y1; i = y2;
	}
	else{
		max = y2; i = y1;
	}
	while (i >= max)
	{
		if (i % 4 == 0)
			sum = sum + 366;
		else
			sum = sum + 365;
		i++;
	}
	return sum;

}
int monthdays(int *arr, int m){
	if (m % 4 == 0)
		arr[1] = 29;
	else
		arr[1] = 28;
	return arr[m - 1];
}
int returnMonthDiff(int *arr, int a, int b)
{
	int i, sum = 0, max = 0;
	if (a < b){
		i = a; max = b;
	}
	else{
		i = b; max = a;
	}
	while (i <= max)
	{
		sum = sum + monthdays(arr, i);
		i++;
	}
	return sum;

}
int returnDays(int d1, int d2, int m1, int m2, int y1, int y2)
{
	if (valied(d1, m1, y1) && valied(d2, m2, y2)){
		if (m1 == m2 && y1 == y2)
			return returndiff(d1, d2);
		int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (m1 != m2)
		{
			if (y1 == y2){
				return returndiff(d1, d2) + returnMonthDiff(month, m1, m2);
			}
			else{
				return returndiff(d1, d2) + returnMonthDiff(month, m1, m2) + returnYearDiff(y1, y2);
			}
		}
		if (y1 != y2)
		{
			if (m1 == m2)
				return returndiff(d1, d2) + returnYearDiff(y1, y2);
		}
	}
}

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	struct node *temp1 = date1head;
	struct node *temp2 = date2head;
	int date1 = temp1->data * 10 + temp1->next->data;
	int date2 = temp2->data * 10 + temp2->next->data;
	temp1 = temp1->next->next;
	temp2 = temp2->next->next;
	int month1 = temp1->data * 10 + temp1->next->data;
	int month2 = temp2->data * 10 + temp2->next->data;
	temp1 = temp1->next->next;
	temp2 = temp2->next->next;
	int year1 = temp1->data * 1000 + temp1->next->data * 100 + temp1->next->next->data * 10 + temp1->next->next->next->data;
	int year2 = temp2->data * 1000 + temp2->next->data * 100 + temp2->next->next->data * 10 + temp2->next->next->next->data;
	return returnDays(date1, date2, month1, month2, year1, year2);

}