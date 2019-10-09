#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char *ptr;

  for(int i = 0; i < 10; i++)
  {
    ptr = (char*) malloc(10 * 1024 * 1024 * sizeof(char)); //allocating 10 mb
    memset(ptr, '0', 10 * 1024 * 1024 * sizeof(char)); //filling with 0s
    sleep(1);
  }
  return 0;
}

/*
Allocating only 10 MB every second during 10 seconds didnt make si and so change

but allocating 1 gb every second during 20 seconds with the following for loop

  for(int i = 0; i < 20; i++)
  {
    ptr = (char*) malloc(1024 * 1024 * 1024 * sizeof(char));
    memset(ptr, '0',1024 * 1024 * 1024 * sizeof(char));
    sleep(1);
  }

made si and so go crazy
also, almost killed my laptop (very dangerous exercises!)

The output for 1gb:

procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 2  0      0 9130732 280948 2610484    0    0    31    28  178  538  6  2 92  0  0
 1  0      0 8564636 280948 2610864    0    0     0     0 1308 3064  6  4 90  0  0
 1  0      0 7515640 280956 2611508    0    0     0    40 1125 2725  4  5 91  0  0
 0  0      0 6465068 280956 2610992    0    0     0     0 1024 2475  4  4 92  0  0
 3  0      0 6371820 280956 2610756    0    0     0     0  973 2543  4  2 94  0  0
 0  0      0 5412968 280964 2610888    0    0     0    60 1079 2618  4  4 92  0  0
 1  0      0 4362128 280964 2611036    0    0     0  2452  990 2515  4  4 92  0  0
 1  0      0 3524984 280964 2611056    0    0     0     0 1158 2908  6  4 91  0  0
 0  0      0 3311824 280964 2611096    0    0     0     0 1023 2674  4  2 94  0  0
 0  0      0 2261960 280964 2610700    0    0     0     0 1096 2545  4  5 91  0  0
 0  0      0 1211756 280964 2610980    0    0     0     0 1057 2599  3  6 91  0  0
 1  0      0 873876 280972 2611372    0    0     0    56 1251 2917  4  3 93  0  0
 0  0      0 190088 280972 2581732    0    0     0     0 1129 2462  4  4 92  0  0
 0  0  41216 292372 238512 1549436    0 40436   252 41312 8703 4441  5 14 81  0  0
 1  0  44800 172348   9248 1372628    0 3432  5164  3432 1428 3068  4  7 89  0  0
 0  0  46336 190548   1208 837188    0 1360  4780  1360 2506 4215  4  9 87  0  0
 1 23 758528 139604    368 405924  336 845452 115920 845580 8445 11505  2 18 47 33  0
 0  0 1173504 202340   4488 498780 69300 353460 278019 353580 13265 22846  2 18 45 35  0
 0 25 2181120 254252    728 397664  588 1010112 81822 1011788 24597 13219  3 19 34 44  0
 1 15 2724096 462324   2512 363148 4508 551976 67014 551976 14316 6775  3 24  2 71  0
 1 21 3121408 152136    676 293416 3608 409824 32658 409992 37582 10842  2 17  4 78  0
 5 12 3346944 147580   4168 373680 95040 248204 221863 248412 24096 32906  3 18  4 74  0
 3 17 3664128 140436   1076 315224 2804 319060 38899 319060 42905 9165  3 19  3 75  0
 6 13 3959040 138712   1988 332892 3432 300028 57773 300112 35287 17538  3 28  6 63  0
 1 20 4227328 138316   2252 347508 7620 276240 43963 276240 43340 11049  4 27  4 64  0
 2  5 4357632 166540   3320 402364 72516 198136 148795 198148 17936 17409  4 22 14 60  0
 2 11 4559104 141988   3764 454308 39348 240440 102865 240520 54343 16708  2 22  6 70  0
 0  8 4838144 138252   1984 403580 3096 282612 16545 282612 39351 11348  3 16 11 70  0
 0 17 5131008 142692    508 365116 2544 305044 65145 305428 47880 13200  2 20 12 66  0
 1  5 5407744 182008   1396 418604 9056 274116 123524 274156 27466 13552  1 18  6 75  0
 2 10 5611264 150172   3996 464064 45648 240568 120229 240568 18414 13573  2 18 15 64  0
 2 15 5921280 141512    896 376760 1604 317744 40715 318004 44099 11384  2 19  6 74  0
 3 16 6259456 143188   1580 379540 2376 334564 59140 334568 42912 10944  4 20  2 74  0
 3  6 6451456 179460   4188 463472 20496 210256 218215 210308 16660 16715  2 21  7 69  0
 ....
*/
