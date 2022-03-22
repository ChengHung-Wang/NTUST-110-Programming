#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define 如果 if
#define 就 {
#define 好了 }
#define 还是不行 else if
#define 实在不行 else
#define 空值 void
#define 短数字 short
#define 数字 int
#define 长值 long
#define 单精度浮点数 float
#define 双精度浮点数 double
#define 布林 bool
#define 类定义 typedef
#define 结构体 struct
#define 返回 return
#define 指针 *
#define 命令行显示 printf
#define 物体大小 sizeof
#define 循环 while
#define 做 {
#define 完成 }
#define 开始 {

#define 结束 }

#define 入口函数 main
#define 主程序 main
#define 命令数量 argc
#define 只讀變量 const
#define 字符 char
#define 循環 for
#define 字符長度 strlen

#define 命令数组 argv

#define 马洛个 malloc

#define 重新马洛个 realloc

#define 扔掉 free


#define 加 +
#define 减 -
#define 乘 *
#define 除 /
#define 大于 >
#define 小于 <
#define 赋值 =
#define 等于 ==
#define 不 !
#define 加一 ++
#define 减一 --
#define 自加 +=
#define 自减 -=
#define 自乘 *=
#define 自除 /=
#define 不是 !=


数字 主程序()
{
    数字 數字對應配置[] 赋值{ 1, 5, 10, 50, 100, 500, 1000 };
    字符 字符對應配置[] 赋值{ 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
    数字 計算結果 赋值 0;

    signed 字符* str;
    数字 c;
    数字 i;
    数字 尺寸 赋值 10;
    str 赋值 马洛个(尺寸 * 物体大小(字符));

    循環(i 赋值 0; (c 赋值 getchar()) != '\n' && c != EOF; ++i) 开始
        如果(i 等于 尺寸) 做
        尺寸 赋值 2 * 尺寸;
    str 赋值 重新马洛个(str, 尺寸 * 物体大小(字符));
    如果(str 等于 NULL) 做
        命令行显示("err 400");
    exit(-1);
    完成
        完成
        str[i] 赋值 c;
    完成

        如果(i 等于 尺寸) 做
        str 赋值 重新马洛个(str, (尺寸 + 1) * 物体大小(字符));
    如果(str 等于 NULL) 做
        printf("err 400");
    exit(-1);
    完成
        完成

        str[i] 赋值 '\0';

    循環(字符 索引 赋值 0; 索引 小于 字符長度(str); 索引++) 开始
        計算結果 自加 數字對應配置[尋找索引(str[索引], 字符對應配置)];
    完成

        命令行显示("%d\n", 計算結果);
    返回 0;
}
数字 尋找索引(只讀變量 字符 尋找字符, 只讀變量 字符 配置[]) {
    数字 結果 赋值 - 1;

    循環(数字 索引 赋值 0; 索引 小于 字符長度(配置); 索引 加一) 开始
        如果(配置[索引] 等于 尋找字符) 开始
        返回 索引;
    完成
        完成

        返回 結果;
}
