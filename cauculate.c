#include <stdio.h>
#include <stdint.h>
#include<math.h>
#pragma warning(disable:4996)

typedef struct {
	int year;
	int month;
	int dayofmonth;
}DateTime;

DateTime datetime = { 1900,1,26 };
const DateTime BaseDateTime = { 1900,1,1 };

int calculate_total_day(DateTime d, DateTime base);
int calculate(DateTime date1, DateTime date2);

int main()
{
	DateTime d1, d2;
#if 1
	printf("-------日期计算程序--------\n");
	printf("输入日期1（>1900），以空格分隔符:\n");
	scanf("%d %d %d", &d1.year, &d1.month, &d1.dayofmonth);
	printf("输入日期2（>1900），以空格分隔符:\n");
	scanf("%d %d %d", &d2.year, &d2.month, &d2.dayofmonth);

#endif
	printf("计算的天数%d", calculate(d1, d2));
	return 0;
}

int calculate_total_day(DateTime d, DateTime base)
{
	int i = 0, totalday = 0, passday = 0;
	int year, dayofweek;
	int temp[12] = {};
	int mday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if ((d.year / 100) * 100 % 4 == 0 && (d.year / 100) * 100 != 0 || (d.year / 100) * 100 % 400 == 0)
		mday[1] = 29;
	else
		mday[1] = 28;

	if (d.year != base.year)
	{
		for (i = base.year; i < d.year; i++)
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				totalday += 366;
			else
				totalday += 365;
		}
	}
	if (d.month == base.month)
	{
		totalday += d.dayofmonth - 1;
	}
	else
	{
		for (i = 0; i < d.month - 1; i++)
		{
			totalday += mday[i];
		}
		totalday += d.dayofmonth - 1;
	}
	return totalday;
}
int calculate(DateTime date1, DateTime date2)
{
	return abs(calculate_total_day(date1, BaseDateTime) - calculate_total_day(date2, BaseDateTime));
}