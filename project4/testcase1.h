/*************************************************************************
	> File Name: testcase1.h
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月07日 星期日 11时29分39秒
 ************************************************************************/


#ifndef _TESTCASE1_H
#define _TESTCASE1_H
#include "is_prime.h"

TEST(test, is_prime_func) {
    EXPECT(is_prime(2), 0);
    EXPECT(is_prime(-2), 0);
    EXPECT(is_prime(15), 0);
    EXPECT(is_prime(9973), 1);
}

#endif
