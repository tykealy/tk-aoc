#include <iostream>
#include <string>
#include <openssl/md5.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();

    string input = "ckczppom";
    const char *prefix = input.c_str();
    size_t prefix_len = input.size();

    for (int i = 0;; ++i)
    {
        // Convert the number to a string efficiently
        char suffix[20];
        int suffix_len = snprintf(suffix, sizeof(suffix), "%d", i);

        // Compute MD5 hash of prefix + suffix
        unsigned char digest[MD5_DIGEST_LENGTH];
        MD5_CTX ctx;
        MD5_Init(&ctx);
        MD5_Update(&ctx, prefix, prefix_len);
        MD5_Update(&ctx, suffix, suffix_len);
        MD5_Final(digest, &ctx);

        // Check if the first three bytes are zero
        if (digest[0] == 0 && digest[1] == 0 && digest[2] == 0)
        {
            cout << i << endl;
            break;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;

    return 0;
}