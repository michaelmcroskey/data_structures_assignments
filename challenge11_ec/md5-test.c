#include <stdio.h>
#include "md5.h"

int main()
{
    unsigned char sol_a_hash[16], sol_b_hash[16];
    char sol_a_hash_hex[33], sol_b_hash_hex[33];
    sol_a_hash_hex[32] = sol_b_hash_hex[32] = 0;

		char *sol_a_fn = "solution-a.cpp", *sol_b_fn = "solution-b.cpp";

    FILE *sol_a = fopen(sol_a_fn, "rb"), *sol_b =  fopen(sol_b_fn, "rb");

    MD5_CTX ctx_sol_a, ctx_sol_b;
    int bytes;
    unsigned char data[1024];

    if (!sol_a || !sol_b) {
      fprintf(stderr, "One or more of the files could not be opened.\n");
      return 1;
    }

    MD5_Init (&ctx_sol_a);
    while ((bytes = fread (data, 1, 1024, sol_a)) != 0) MD5_Update (&ctx_sol_a, data, bytes);
    MD5_Final (sol_a_hash,&ctx_sol_a);

    MD5_Init (&ctx_sol_b);
    while ((bytes = fread (data, 1, 1024, sol_b)) != 0) MD5_Update (&ctx_sol_b, data, bytes);
    MD5_Final (sol_b_hash,&ctx_sol_b);

    fclose(sol_a), fclose(sol_b);

		int i, match = 1;
    for(i = 0; i < 16; ++i) {
      sprintf(&sol_a_hash_hex[i<<1], "%02x", sol_a_hash[i]);
      sprintf(&sol_b_hash_hex[i<<1], "%02x", sol_b_hash[i]);
      if (sol_a_hash[i] != sol_b_hash[i]) match = 0;
    }

    if (match) {
      printf("The hashes match.\n");
      printf("Value: %s\n", sol_a_hash_hex);
    } else {
      fprintf(stderr, "Hash mismatch!\n");
      fprintf(stderr, "solution-a: %s\n", sol_a_hash_hex);
      fprintf(stderr, "solution-b: %s\n", sol_b_hash_hex);
    }

    return !match;
}
