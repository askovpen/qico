
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <cmocka.h>

#include "headers.h"
#include "config.h"
#include "binkp.h"
#include "types.h"
#include "md5q.h"

char progname[] = "qico-test";

RETSIGTYPE sigerr(int sig) {}

char * pwd="test";


int init_test(void) {
    return 0;
}
int clean_test(void) {
    return 0;
}
void test_md5_digest(void **state) {
	byte * buf=malloc(1024);
	sprintf(buf,"CRAM-MD5-a185bcedff29c157154b3764b3adcfee");
	byte* chal=md5_challenge(buf);
	char *dig = md5_digest( (unsigned char*)pwd, (unsigned char*)chal );
	assert_string_equal(dig, "b9569b6ba1563cd11c74d13ad983545d");
//      CU_ASSERT_STRING_EQUAL("test", dig);

}
void test_md5_cram_get(void **state) {
	unsigned char digest[16]= {0};
	md5_cram_get((unsigned char*)pwd,(unsigned char*)"\xa1\x85\xbc\xed\xff\x29\xc1\x57\x15\x4b\x37\x64\xb3\xad\xcf\xee",16,digest);
	char *ret = xcalloc( 1, MD5_DIGEST_LEN * 2 + 5 );
	    bin2strhex((unsigned char *) ret, digest, MD5_DIGEST_LEN );
//      CU_ASSERT(0 == strncmp(ret, "test", 4));
	assert_string_equal("b9569b6ba1563cd11c74d13ad983545d",ret);

}
int setup (void ** state)
{
    return 0;
}

int teardown (void ** state)
{
    return 0;
}
int main (void)
{
    const struct CMUnitTest tests [] =
    {
        cmocka_unit_test (test_md5_digest),
        cmocka_unit_test (test_md5_cram_get),
    };

    /* If setup and teardown functions are not
       needed, then NULL may be passed instead */

    int count_fail_tests =
        cmocka_run_group_tests (tests, setup, teardown);

    return count_fail_tests;
}