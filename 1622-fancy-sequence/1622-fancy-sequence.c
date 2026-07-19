#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int *nums;
    int size;
    int capacity;
    long long mult;
    long long add;
} Fancy;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

Fancy* fancyCreate() {
    Fancy* obj = (Fancy*)malloc(sizeof(Fancy));
    obj->size = 0;
    obj->capacity = 100005;
    obj->nums = (int*)malloc(obj->capacity * sizeof(int));
    obj->mult = 1;
    obj->add = 0;
    return obj;
}

void fancyAppend(Fancy* obj, int val) {
    // val = (original * mult + add) % MOD
    // original = (val - add) * inv(mult) % MOD
    long long invMult = modInverse(obj->mult);
    long long original = (1LL * (val - obj->add) % MOD + MOD) % MOD;
    original = (original * invMult) % MOD;
    obj->nums[obj->size++] = (int)original;
}

void fancyAddAll(Fancy* obj, int inc) {
    obj->add = (obj->add + inc) % MOD;
}

void fancyMultAll(Fancy* obj, int m) {
    obj->mult = (obj->mult * m) % MOD;
    obj->add = (obj->add * m) % MOD;
}

int fancyGetIndex(Fancy* obj, int idx) {
    if (idx >= obj->size) return -1;
    long long val = (1LL * obj->nums[idx] * obj->mult + obj->add) % MOD;
    return (int)val;
}

void fancyFree(Fancy* obj) {
    free(obj->nums);
    free(obj);
}